#encoding: UTF-8
require_relative 'LootToUI'

module Deepspace
	class Loot
		def initialize (supplies,weapons,shields,hangars,medals)  # son todos int
			@nSupplies = supplies
			@nWeapons = weapons
			@nShields = shields
			@nHangars = hangars
			@nMedals = medals
		end

		attr_reader :nSupplies
		
		attr_reader :nWeapons

		attr_reader :nShields
	
		attr_reader :nHangars

		attr_reader :nMedals
		
		def getUIversion()
			return LootToUI.new(self)
		end
		
		def to_s
			return "Supplies: #{@nSupplies}, Weapons: #{@nWeapons}, Shields: #{@nShields}, Hangars: #{@nHangars}, Medals: #{@nMedals}"
		end
	end

end
