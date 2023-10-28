require_relative 'HangarToUI'
require_relative 'Weapon'
require_relative 'ShieldBooster'
require_relative 'WeaponType'

module Deepspace
	class Hangar
		def initialize(capacity)  # int 
			@maxElements = capacity
			@shieldBoosters = Array.new()
			@weapons = Array.new()
		end
		
		attr_reader :maxElements, :weapons, :shieldBoosters
		
		def self.newCopy(h)
			
			copy=new(h.maxElements)
			
			h.shieldBoosters.each do |shieldBooster|
				copy.addShieldBooster(shieldBooster)
			end
			
			h.weapons.each do |weapon|
				copy.addWeapon(weapon)
			end
			
			return copy
		end
		
		def spaceAvailable()
			retorno=true
						
			if (@maxElements <= (@weapons.length + @shieldBoosters.length))
				retorno=false
			end
			
			return (retorno)
		end
		
		def addWeapon(w)    # donde w es un Weapon
			retorno=false
			
			if spaceAvailable()
				retorno=true
				@weapons << w
			end
			
			return retorno       # devuelve un bool en función de si se puede añadir
		end
		
		def addShieldBooster(s)    # donde s es un ShieldBooster
			retorno=false
						
			if spaceAvailable()
				retorno=true
				@shieldBoosters << s 
			end
			  
			return retorno    # devuelve un bool en función de si se puede añadir
		end
		
		def removeWeapon(w)	   # donde w es un entero (indice de array)
					
			if (w < @weapons.length && w >= 0)
				retorno = @weapons.delete_at(w)
			else
				retorno = nil
			end
			
			return retorno   # devuelve el weapon eliminado
		end
		
		def  removeShieldBooster(s)    # donde s es un entero (indice de array)
			
			if (s < @shieldBoosters.length && s >= 0)
				retorno = @shieldBoosters.delete_at(s)
			else
				retorno = nil
			end
			
			return retorno     # devuelve el shield eliminado
		end
				
		def getUIversion()
			return HangarToUI.new(self)
		end
		
		def to_s
			out="Hangar - capacity: #{@maxElements}\n"
			out+="\tWeapons: [#{@weapons.join(' // ')}]\n"
			out+="\tShieldBoosters: [#{@shieldBoosters.join(' // ')}]\n"
			out+="------- end of Hangar -------"
			return out
		end

	end
end
		
		
			
			
