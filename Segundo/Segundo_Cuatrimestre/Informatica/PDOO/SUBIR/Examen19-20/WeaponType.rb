#encoding: UTF-8

module Deepspace
	module WeaponType
		class Type
			def initialize (p) # p es float
				@power = p
			end
			
			attr_reader	:power
			
			def to_s
				if (self == WeaponType::LASER)
					type = "LASER"
				else 
					if (self == WeaponType::MISSILE)
						type = "MISSILE"
					else
						type = "PLASMA"
					end
				end
				
				return type
			end
		end
		
		LASER = Type.new(2.0)
		MISSILE = Type.new(3.0)
		PLASMA = Type.new(4.0)
		
	end

end
