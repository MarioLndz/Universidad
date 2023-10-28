#encoding: UTF-8

require_relative 'SpaceStationToUI'

require_relative 'Weapon'
require_relative 'WeaponType'
require_relative 'ShieldBooster'
require_relative 'Hangar'
require_relative 'Damage'
require_relative 'SuppliesPackage'
require_relative 'ShotResult'
require_relative 'Loot'

module Deepspace
  
	class SpaceStation

		#atributos de clase
		@@MAXFUEL=100
		@@SHIELDLOSSPERUNITSHOT=0.1
	  
		attr_reader :name, :nMedals, :ammoPower, :fuelUnits, \
		  :shieldPower, :shieldBoosters, :hangar, :weapons, \
		  :pendingDamage, :MAXFUEL, :SHIELDLOSSPERUNITSHOT
	  
		def initialize (n, supplies)	# n string, supplies es SuppliesPackage	
			@name=n
			@ammoPower = 0
			@shieldPower = 0
			@fuelUnits = 0
			receiveSupplies(supplies)
			
			@nMedals=0
			@weapons=Array.new()
			@shieldBoosters=Array.new()
			@hangar=nil
			@pendingDamage=nil
		end
		
		def cleanUpMountedItems()  # void()
			#Compruebo las armas sin usos y elimino las que no le queden usos
			@weapons.each do |w|
				if (w.uses == 0)
					@weapons.delete(w) #creo q es asi
				end
			end

			#Compruebo los escudos sin usos y elimino los que no tengan usos
			@shieldBoosters.each do |s|
				if (s.uses == 0)
					@shieldBoosters.delete(s) #creo q es asi
				end
			end
		end
		
		def discardHangar()  # void()
			@hangar=nil
		end
		
		def discardShieldBooster(i)   # i es indice del arma
			size = @shieldBoosters.length
			if (i>=0 && i<size)
				s=@shieldBoosters.delete_at(i)
				
				if (@pendingDamage != nil)
					@pendingDamage.discardShieldBooster(w)
					cleanPendingDamage
				end
			end	
		end        #void()
		
		def discardShieldBoosterInHangar(i)  # i es indice del escudo que se descarta
			if (hangar != nil)
				hangar.removeShieldBooster(i) 
			end		# void()
		end
		
		def discardWeapon(i)  # i es indice del arma
		
			size=@weapons.length
			if (i>=0 && i<size)
				w=@weapons.delete_at(i)
				
				if (@pendingDamage != nil)
					@pendingDamage.discardWeapon(w)
					cleanPendingDamage
				end
			end		
		end      # void()
		
		def discardWeaponInHangar(i)  # i es indice del arma que se descarta
			if (@hangar != nil)
				@hangar.removeWeapon(i)
			end         # void()
		end
		
		def fire()
			factor = 1
			
			@weapons.each do |w|
				factor *= w.useIt()
			end
			
			return (ammoPower*factor)  #float
		
		end
		
		def getNMedals()
			return @nMedals
		end
		
		def getSpeed() 
			return (@fuelUnits.to_f/@@MAXFUEL) # devuelve float
		end
		
		def getUIversion()
			SpaceStationToUI.new(self)
		end
		
		def mountShieldBooster(i)  # i es indice dentro del Hangar
			if (hangar != nil) 
				s = hangar.removeShieldBooster(i)
				if (s != nil)
					shieldBoosters.push(s)
				end        # void()
			end
		end
		
		def mountWeapon(i)   # i es indice dentro del Hangar
			if (hangar != nil) 
				w = hangar.removeWeapon(i)
				if (w != nil)
					weapons.push(w)
				end
			end       # void()
		end
		 
		def move()   # void()
			@fuelUnits -= @fuelUnits*getSpeed()
		end
		
		def protection()  #float
			factor = 1
			shieldBoosters.each do |s|
				factor *= s.useIt
			end	
			return (@shieldPower * factor)		
		end
		
		def receiveHangar(h)  # h es un Hangar
			if (hangar == nil)
				@hangar = h
			end   # es void()
		end
		
		def receiveShieldBooster(s)  # s es ShieldBooster
			retorno = false
			
			if (hangar != nil)
				retorno = hangar.addShieldBooster(s)	#creo q asi devuelve true o false ya
			end
			
			return (retorno)   # bool si consigue añadir el escudo
		end
		
		def receiveShot(shot)  # shot es float
			myProtection=protection()
			if(myProtection>=shot)
				@shieldPower=@shieldPower-(@@SHIELDLOSSPERUNITSHOT*shot)
				@shieldPower=[0.0,@shieldPower].max
				ShotResult::RESIST
			else
				@shieldPower=0.0
				ShotResult::DONOTRESIST   # devuelve shotResult
			end
		
		end
		
		def receiveSupplies(s) 
			@ammoPower += s.ammoPower
			@shieldPower += s.shieldPower
			
			assignFuelValue(fuelUnits + s.fuelUnits)
			
		end
		
		def receiveWeapon(w)  # w es Weapon
			retorno = false
			if (hangar != nil)
				retorno = hangar.addWeapon(w)	#creo q asi devuelve true o false ya
			end  # bool si ha conseguido añadir el arma
		end
		
		def setLoot(loot)  #loot es Loot
			dealer = CardDealer.instance
			
			#Aniadimos Hangars
			h = loot.nHangars
			if (h > 0)
				hangar = dealer.nextHangar()
				
				receiveHangar(hangar)  
			end
			
			#Aniadimos supplies
			elements = loot.nSupplies
			for i in (1..elements) do
				sup = dealer.nextSuppliesPackage()
				receiveSupplies(sup)
			end
			
			# Aniadimos Weapons
			elements = loot.nWeapons
			for i in (1..elements) do
				weap = dealer.nextWeapon()
				receiveWeapon(weap)
			end
			
			#Aniadimos Shields
			elements = loot.nShields
			for i in (1..elements) do
				sh = dealer.nextShieldBooster()
				receiveShieldBooster(sh)
			end
			
			medals = loot.nMedals

			@nMedals += medals

		end  # void()
		
		def setPendingDamage(d)   # d es Damage
			#d.adjust(@weapons, @shieldBoosters)
			# se almacena el resultado en el atributo correspondiente ???
			# creo q es esto:
			@pendingDamage = d.adjust(@weapons, @shieldBoosters)      # void()
		end
		
		def validState()
			return (@pendingDamage == nil || @pendingDamage.hasNoEffect())   # bool 
		end
		
		def to_s
			out="Space Station - Name: #{@name}\n"
			out+="\tnMedals: #{@nMedals}, Fuel units: #{@fuelUnits.round(2)}, Power: #{@ammoPower}, Shields: #{@shieldPower}\n"
			out+="\tWeapons: [#{@weapons.join(' // ')}]\n"
			out+="\tShieldBooster: [#{@shieldBoosters.join(' // ')}]\n"
			out+="\tHangars: #{@hangar}\n"
			out+="\tPendingDamage: #{@pendingDamage}\n" 
			out+="------- end of Space Station >> #{@name} << -------"
			return out
		end
		
		private 	#todos los metodos q haya debajo de esto son privados (solo los de instancia)
		def assignFuelValue(f)  # f es float
			if (f < @@MAXFUEL)
				@fuelUnits = f
			else
				@fuelUnits = @@MAXFUEL
			end
		end      # no devulve nada
		
		def cleanPendingDamage()
			if (@pendingDamage.hasNoEffect())
				pendingDamage = nil 
			end 
		end  # void

	end # class
	
	#s = SpaceStation.new("space", SuppliesPackage.new(3,4,5))
	#puts s.to_s
	
	#sui = SpaceStationToUI.new(s)
	#puts sui.to_s
end # module
