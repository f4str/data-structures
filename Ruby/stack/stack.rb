class StackNode
	attr_accessor :data, :next
	
	def initialize(data)
		@data = data
		@next = nil
	end
end

class Stack
	def initialize(elems = nil)
		@top = nil
		@size = 0
		if elems
			elems.each { |e| push(e) }
		end
	end
	
	def length
		@size
	end
	
	def empty?
		@size == 0
	end
	
	def push(e)
		if @size == 0
			@top = StackNode.new(e)
		else
			temp = SinglyNode.new(e)
			temp.next = @top
			@top = temp
		end
		@size += 1
	end
	
	def peek
		@top&.data
	end
	
	def pop
		data = @top&.data
		if data
			@top = @top.next
			@size -= 1
		end
		data
	end
	
	def include?(e)
		current = @top
		while current
			return true if current.data = e
			current = current.next
		end
		false
	end
	
	def clear
		@top = nil
		@size = 0
	end
end