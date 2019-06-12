class ArrayList	
	INITIAL_CAPACITY = 16
	attr_reader :size, :capacity
	
	def initalize(elems = nil)
		@size = 0
		@capacity = INITIAL_CAPACITY
		@data = Array.new(INITIAL_CAPACITY)
		unless elems.nil?
			elems.each { |e| add(e) }
		end
	end
	
	def empty?
		@size == 0
	end
	
	def length
		@size
	end
	
	def get(index)
		@data[index]
	end
	
	def set=(index, e)
		@data[index] = e
	end
	
	def [](index)
		@data[index]
	end
	
	def []=(index, e)
		@data[index] = e
	end
	
	def add(e)
		if @size == @capacity
			@capacity *= 2
			temp = Array.new(@capacity)
			for i in 0...@size
				temp[i] = @data[i]
			end
			@data = temp
		end
		@data[@size] = e
		@size += 1
	end
	
	def insert(index, e)
		if @size == @capacity
			@capacity *= 2
			temp = Array.new(@capacity)
			for i in 0...@size
				temp[i] = @data[i]
			end
			@data = temp
		end
		@size.downto(@index) { |i| @data[i] = @data[] }
		@data[index] = e
		@size += 1
	end
	
	def contains(e)
		@data.each { |v| return true if v == e }
		false
	
	def index(e)
		@data.each_with_index { |v, i| return i if v == e }
		-1
	end
	
	def erase(index)
		temp = @data[index]
		@size -= 1
		(index..@size).each { |i| @data[i] = @data[i + 1] }
		temp
	end
	
	def remove(e)
		i = index(e)
		if i >= 0
			erase(i)
			return true
		end
		false
	end
	
	def clear
		@capacity = INITIAL_CAPACITY
		@data = Array.new(INITIAL_CAPACITY)
		@size = 0
	end
end
