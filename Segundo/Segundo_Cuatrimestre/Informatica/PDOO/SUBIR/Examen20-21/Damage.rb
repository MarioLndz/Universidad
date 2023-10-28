require_relative 'DamageToUI'
require_relative 'WeaponType'
require_relative 'Weapon'
require_relative 'ShieldBooster'


module Deepspace
	class Damage
		
		@@NOUSO=-1
		
		private_class_method :new
		
		def initialize(s,w,wp)  # s int es numero de escudos, w int es numero de armas, wp es array de weapontype 
			@nShields=s
			@nWeapons=w
			@weapons=wp
		end
		
		def self.newNumericWeapons(w, s)  # w es numero de armas int, s int es numero de escudos
			return new(s, w, nil)
		end
		
		def self.newSpecificWeapons(wl, s)  #wl es array de weapontype, s int es numero de escudos
			return new(s, @@NOUSO, wl)
		end
		
		def self.newCopy(d)
			if d.nWeapons == @@NOUSO
				return newSpecificWeapons(d.weapons, d.nShields)
			else
				return newNumericWeapons(d.nWeapons, d.nShields)
			end
		end
		
		def getUIversion()
			return DamageToUI.new(self)
		end
		
		attr_reader :nShields, :nWeapons, :weapons
		
		def adjust(w,s)   ## funciona    # w es un jarray list de Weapon,s es un Array list de shield
			d = nil
			
			l_nshields = [s.length, nShields].min

			if @weapons==nil
				l_nweapons = [w.length, nWeapons].min
				
				d = Damage.newNumericWeapons(l_nweapons,l_nshields)

			else
				result = []
				w_aux = w.clone
				
				@weapons.each do |element|
					indice = arrayContainsType(w_aux, element)
              
					if indice != -1
						result.push(element)
						w_aux.delete_at(indice)
					end
				end

				d =Damage.newSpecificWeapons(result, l_nshields)
			end
			
			return d    # d es un Damage ajustado a lo que hemos pasado
		end
		
		
		def discardWeapon(w)    # w es Weapon
		
			if @nWeapons == @@NOUSO
			
				if @weapons.length != 0
					
					indice = @weapons.index(w.type)
					
					if indice != nil
						
						@weapons.delete_at(indice)
					end
				end
				
			elsif
				
				if @nWeapons > 0
					@nWeapons -= 1
				end                    # es void()
			end
			  
		end
			
			
		def discardShieldBooster()
					
			if @nShields > 0
				
				@nShields -= 1
				
			end              # es void()
			
		end
		
		def hasNoEffect()
		
			if @nWeapons == @@NOUSO
			
				retorno = @weapons.length + @nShields == 0
				
			else
			
				retorno = @nShields + @nWeapons == 0
				
			end
			
			return retorno        # true si no se pierden accesorios
		end
		
		def to_s
			out="Damage - nShields: #{@nShields}"
						
			if (@nWeapons != @@NOUSO)
				out+=", nWeapons: #{@nWeapons}\n"
			else
				#out+="\tWeapons: [#{@weapons.join(' // ')}]\n"
				out += "\tWeapons: "
				@weapons.each do |w|
					out += w.to_s + " // "
				end			
				out += "\n"	
			end
			out+="------- end of Damage -------"
			return out
		end
		
		private 
		def arrayContainsType(w,t)   # w es arraylist de Weapon y t es WeaponType
			
			i = 0
			retorno = -1
			sigo = true
			
			while (sigo && i < w.length)
				if w[i].type == t
					retorno = i
					sigo = false
				end
				i += 1
			end
			
			return retorno	# devuelve indice de la primer posición de w que coincida con el tipo t	
		end
		
	end
	
	#tipos = Array.new
	#tipos << WeaponType::LASER
	#tipos << WeaponType::MISSILE

	#shields = Array.new
	#shields << "AAA"

	#d = Damage.newSpecificWeapons(tipos, 3)
	#puts d.getUIversion

	#pendingDamage = Damage.newSpecificWeapons(Array.new, 2)

	#armas = Array.new
	#armas << Weapon.new("MISIL", WeaponType::MISSILE, 2)

	#pendingDamage = d.adjust(armas, shields)
	#puts pendingDamage.getUIversion

end			

