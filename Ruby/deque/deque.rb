class DequeNode
   attr_accessor :data, :next
   
   def initialize(data)
		@data = data
		@next = nil
		@previous = nil
   end
end

class Deque
	attr_reader :size
	
	def initialize(elems = nil)
		@front = nil
		@back = nil
		@size = 0
		if elems
			elems.each { |e| add_last(e) }
		end
	end
	
	def length
		@size
	end
	
	def empty?
		@size == 0
	end
	
	def first
		@front&.data
	end
	
	def last
		@back&.data
	end
	
	def first=(e)
		if @size > 0
			@front.data = e
		else
			add_first(e)
		end
	end
	
	def last=(e)
		if @size > 0
			@back.data = e
		else
			add_last(e)
		end
	end
	
	def add_first(e)
		if @size == 0
			@front = DequeNode.new(e)
			@back = @front
		else
			temp = DequeNode.new(e)
			temp.next = @front
			@front.previous = temp
			@front = temp
		end
		@size += 1
	end
	
	def add_last(e)
		if @size == 0
			@back = DequeNode.new(e)
			@front = @back
		else
			temp = DequeNode.new(e)
			@back.next = temp
			temp.previous = @back
			@back = temp
		end
		@size += 1
	end
	
	def remove_first
		data = first
		if @front == @back
			clear()
		else
			@front = @front.next
			@front.previous = nil
			@size -= 1
		end
		data
	end
	
	def remove_last
		data = last
		if @front == @back
			clear()
		else
			@back = @back.previous
			@back.next = nil
			@size -= 1
		end
		data
	end
	
	def include?(e)
		current = @front
		while current
			return true if current.data == e
			current = current.next
		end
		false
	end
	
	def clear
		@front = nil
		@back = nil
		@size = 0
	end
end
