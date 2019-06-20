class QueueNode
	attr_accessor :data, :next
	
	def initialize(data)
		@data = data
		@next = nil
	end
end

class Queue
	attr_reader :size
	
	def initalize(elems = nil)
		@front = nil
		@back = nil
		@size = 0
		if elems
			elems.each { |e| enqueue(e) }
		end
	end
	
	def length
		@size
	end
	
	def empty?
		@size == 0
	end
	
	def enqueue(e)
		if @size == 0
			@back = QueueNode.new(e)
			@front = @back
		else
			temp = QueueNode.new(e)
			@back.next = temp
			@back = temp
		end
		@size += 1
	end
	
	def peek
		@front&.data
	end
	
	def dequeue
		data = peek()
		if @front == @back
			clear()
		else
			@front = @front.next
			@size -= 1
		end
		data
	end
	
	def include?(e)
		current = @front
		while current
			return true if current.data = e
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