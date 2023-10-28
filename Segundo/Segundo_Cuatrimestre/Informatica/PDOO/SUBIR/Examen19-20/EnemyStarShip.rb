#encoding: UTF-8

require_relative 'ShotResult'
require_relative 'Loot'
require_relative 'Damage'

require_relative 'EnemyToUI'

#require_relative 'SuppliesPackage'

module Deepspace
	class EnemyStarShip
		# Constructor
		def initialize (n, ap, sp, l, d)  # n string, ap float, sp float, l loot, d Damage
			@name = n
			@ammoPower = ap
			@shieldPower = sp
			@loot = l
			@damage = d
			
		end
		
		# Constructor de copia
		def self.newCopy(other)
			new(other.name, other.ammoPower, other.shieldPower, other.loot, other.damage)
		end
		
		def getUIversion()
			return EnemyToUI.new(self)
		end
		
		# Consultores publicos
		attr_reader :ammoPower
		attr_reader :loot
		attr_reader :name
		attr_reader :shieldPower
		attr_reader :damage
		
		def protection ()
			return @shieldPower   # devuelve float
		end
		
		def fire ()
			return @ammoPower   # devuelve float
		end
		
		def receiveShot (shot)   # shot es un float
			resultado = ShotResult::RESIST
			
			if (protection() < shot)
				resultado = ShotResult::DONOTRESIST
			end
			
			return (resultado)   # devuelve un ShotResult
		end
		
		def to_s
			out = "ENEMY - Name: " + @name + ", ammoPower:  #{@ammoPower}, shieldPower: #{@shieldPower} \n"
			out += "\tLoot: " + @loot.to_s + "\n"
			out += "\tDamage: " + @damage.to_s + "\n"
			out += "------- end of Enemy " + @name + " -------"
			return out
		end
		
	end	#class

	#d = Damage.newNumericWeapons(3, 2)
	#puts d.getUIversion

	#l = Loot.new(SuppliesPackage.new(1,2,3), 2, 3, 1, 5)
	#l.getUIversion

	#e = EnemyStarShip.new("Huebo", 2, 3, l, d)
	#puts e.to_s
	
	#eui = EnemyToUI.new(e)
	#puts eui.to_s

end	#module
