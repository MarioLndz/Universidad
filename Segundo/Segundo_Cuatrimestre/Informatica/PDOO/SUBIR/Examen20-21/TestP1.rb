#encoding: UTF-8

require_relative 'Loot'
require_relative 'SuppliesPackage'
require_relative 'ShieldBooster'
require_relative 'Weapon'
require_relative 'WeaponType'
require_relative 'Dice'
require_relative 'GameCharacter'



module Deepspace

	#LOOT
		 l = Loot.new(2,5,1,6,3)
		 puts "LOOT:"
		 puts "Num Supplies:\t" + l.nSupplies().to_s
		 puts "Num Weapons:\t" + l.nWeapons().to_s
		 puts "Num Shields:\t" + l.nShields().to_s
		 puts "Num Hangares:\t" + l.nHangars().to_s
		 puts "Num Medals:\t" + l.nMedals().to_s
	
	#SUPPLIES
        sp = SuppliesPackage.new(4.5, 2, 3.1)
        puts "\nSUPPLIES:"
        puts "AmmoPower:\t" + sp.ammoPower().to_s
        puts "Fuel Units:\t" + sp.fuelUnits().to_s
        puts "Shield Power:\t" + sp.shieldPower().to_s
		
	#SHIELD BOOSTER
        sb = ShieldBooster.new("shield", 3.4, 6)
        puts "\nSHIELD BOOSTER"
        puts "Boost:\t" + sb.boost().to_s
        puts "Uses:\t" + sb.uses().to_s
        puts "UseIt:\t" + sb.useIt().to_s
		
	#WEAPON
        w = Weapon.new("weapon", WeaponType::MISSILE, 4)
        puts "\nWEAPON"
        #puts "Type:\t" + w.type()
        puts "Uses:\t" + w.uses().to_s
        puts "Power:\t" + w.power().to_s
        puts "UseIt:\t" + w.useIt().to_s
        
	#PARTE 2
        d = Dice.new()
        TOPE = 100

        #initWithNHangars
        prob_hangars = 0
        TOPE.times{
            prob_hangars += d.initWithNHangars()
        }

        puts "\ninitWithNHangars: " + prob_hangars.to_s + "/" + TOPE.to_s

        #initWithNWeapons
        prob_uno = 0;
        prob_dos = 0;

        TOPE.times{
            valor = d.initWithNWeapons()
            if (valor==1)
                prob_uno+=1
            else 
				if (valor==2)
					prob_dos+=1
                end
            end
        }
		
        puts "\ninitWithNWeapons 1: " + prob_uno.to_s + "/" + TOPE.to_s
        puts "\ninitWithNWeapons 2: " + prob_dos.to_s + "/" + TOPE.to_s

        #initWithNShields
        prob_shields = 0
        TOPE.times{
            prob_shields += d.initWithNShields()
        }

        puts "\ninitWithNShields: " + prob_shields.to_s + "/" + TOPE.to_s

        #firstShot
        prob_firstShot = 0
        #character=GameCharacter.new()
        TOPE.times{
            character = d.firstShot()
            if (character == GameCharacter::SPACESTATION)
                prob_firstShot+=1
            end
        }
        
        puts "\nfirstShot SPACESTATION: " + prob_firstShot.to_s + "/" + TOPE.to_s
        
        
        #spaceStationMoves
        prob_spaceStationMoves = 0
        speed=0.6
        TOPE.times{
            if (d.spaceStationMoves(speed))
                prob_spaceStationMoves+=1
            end
                
        }
        
        puts "\nspaceStationMoves (speed = " + speed.to_s + "): " + prob_spaceStationMoves.to_s + "/" + TOPE.to_s

end
