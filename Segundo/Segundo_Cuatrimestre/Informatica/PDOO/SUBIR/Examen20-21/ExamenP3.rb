#encoding: UTF-8

require_relative 'Damage'

=begin
	GameUniverse:
		- Cambiado mountWeapon()
		- Añadido cleanHangar()
		
	SpaceStation:
		- Añadido cleanHangar()
		
	Hangar:
		- Añadido clean()
		- Añadido isEmpty()

=end

module Deepspace
	class ExamenP3
		def self.principal
			d1 = Damage.newNumericWeapons(2, 3)
			puts d1.getUIversion
			d2 = Damage.newSpecificWeapons([WeaponType::LASER, WeaponType::LASER, WeaponType::PLASMA], 0)
			puts d2.getUIversion
			
			puts "\n\n"
			
			w1 = Deepspace::Weapon.new("wea1", Deepspace::WeaponType::LASER,3)
			w2 = Deepspace::Weapon.new("wea2", Deepspace::WeaponType::PLASMA,3)
			w3 = Deepspace::Weapon.new("wea3", Deepspace::WeaponType::PLASMA,3)
			w4 = Deepspace::Weapon.new("wea4", Deepspace::WeaponType::LASER,3)
			w5 = Deepspace::Weapon.new("wea5", Deepspace::WeaponType::LASER,3)
			w6 = Deepspace::Weapon.new("wea4", Deepspace::WeaponType::MISSILE,3)
			w7 = Deepspace::Weapon.new("wea5", Deepspace::WeaponType::MISSILE,3)
			
			sb1 = Deepspace::ShieldBooster.new("sb1",3,2)
			sb2 = Deepspace::ShieldBooster.new("sb2",3,2)
			sb3 = Deepspace::ShieldBooster.new("sb3",3,2)
			
			arr_w1 = [w2,w3,w1,w4,w5] #2 plasma, 3 laser
			arr_s1 = [sb1,sb2]	#2 potenciadores de escudo
			puts (d1.adjust(arr_w1, arr_s1)).getUIversion
			
			arr_w2 = [w1,w4,w2,w3,w6,w7]	#2 armas de cada tipo
			arr_s2 = []		# ningun potenciador de escudo
			puts (d2.adjust(arr_w2, arr_s2)).getUIversion
			
			
		end
	end
	
	ExamenP3.principal

end
