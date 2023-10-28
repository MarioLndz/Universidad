#encoding: UTF-8

require_relative 'ShieldToUI'

module Deepspace

	class ShieldBooster		# ponerle visibilidad de paquete -> visibilidad publica
	
		#constructor
		def initialize(n,b,u)  # n string, b float, u int
			# atributos de instancia privados
			@name=n
			@boost=b
			@uses=u
		end
		
		# constructor de copia
		def self.newCopy(other)
			new(other.name, other.boost, other.uses)		
		end		
		
		def getUIversion()
			ShieldToUI.new(self)
		end
		
		# consultor publico 
		attr_reader :uses
		attr_reader :boost
		attr_reader :name
		
		# metodo de instancia publico
		def useIt
			retorno=1
			if (@uses > 0)
				@uses -= 1
				retorno = boost
			end
			
			return retorno  #devuelve un float
		end 
		
		def to_s
			return "Name: "+ @name +", Boost: #{@boost}, Uses: #{@uses}"
		end     
	end
end
