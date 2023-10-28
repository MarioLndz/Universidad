#encoding: UTF-8

require_relative 'Damage'

module Deepspace
	class Examen
		def self.principal
			weapons = [WeaponType::LASER, WeaponType::PLASMA, WeaponType::LASER, WeaponType::MISSILE] 
			
=begin
				salida = ""
				weapons.each do |w|
					salida += w.to_s + "  \\  "
				end
				puts salida
=end
			
			damage = Damage.newSpecificWeapons(weapons, 4)
			puts damage.getUIversion
			
			w1 = Weapon.new("ArmaPrincipal", WeaponType::MISSILE, 4)
			w2 = Weapon.new("ArmaSecundaria", WeaponType::LASER, 4)
			
			sh = [ShieldBooster.new("Escudo", 5, 4)]
			
			damage = damage.adjust([w1,w2], sh)
			puts damage.getUIversion
		end
	end	# class
	
	Examen.principal
	
end # module
