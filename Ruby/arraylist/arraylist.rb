class ArrayList	
	attr_reader :size, :capacity
	INITIAL_CAPACITY = 10
	
	def initalize()
		@size = 0
		@capacity = INITIAL_CAPACITY
		@data = Array.new(INITIAL_CAPACITY)
	end
	
	def empty()
		@size == 0
	end
	
	def length
		@size
	end
end