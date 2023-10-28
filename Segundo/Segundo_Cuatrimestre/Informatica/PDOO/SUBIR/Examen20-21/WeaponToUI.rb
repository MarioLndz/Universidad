module Deepspace
  
class WeaponToUI 

  # MIGUEL: por que  name  no forma parte de esta clase ?
  
    attr_reader :type, :power, :uses
    
    def initialize(w) 
        @type=w.type();
        @power=w.power();
        @uses=w.uses();
    end  
    
    def to_s
		if (@type == WeaponType::LASER)
			type = "LASER"
		else 
			if (@type == WeaponType::MISSILE)
				type = "MISSILE"
			else
				type = "PLASMA"
			end
		end
		
			return "Type: " + @type.to_s + ", Power: #{@type.power}, Uses: #{@uses}"
	end
    
end # class
	
end # module
