class DoublyNode
   attr_accessor :data, :next
   
   def initialize(data)
		@data = data
		@next = nil
   end
end

class DoublyLinkedList
	attr_reader :size
	
	def initialize(elems = nil)
		@head = nil
		@tail = nil
		@size = 0
		if elems
			elems.each { |e| add_last(e) }
		end
	end
	
	def [](index)
		get(index)
	end
	
	def []=(index, e)
		set(index, e)
	end
	
	def length
		@size
	end
	
	def empty?
		@size == 0
	end
	
	def first
		@head&.data
	end
	
	def last
		@tail&.data
	end
	
	def get(index)
		if index == 0
			first
		elsif index == @size - 1
			last
		else
			current = @head
			(index - 1).times { current = current.next }
			current.data
		end
	end
	
	def first=(e)
		if @size > 0
			@head.data = e
		else
			add_first(e)
		end
	end
	
	def last=(e)
		if @size > 0
			@tail.data = e
		else
			add_last(e)
		end
	end
	
	def set(index, e)
		if index == 0
			data = first
			first = e
		elsif index == @size - 1
			data = last
			last = e
		else
			current = @head
			(index - 1).times { current = current.next }
			current.data = e
		end
		data
	end
	
	def add_first(e)
		if @size == 0
			@head = DoublyNode.new(e)
			@tail = @head
		else
			temp = DoublyNode.new(e)
			temp.next = @head
			@head.previous = temp
			@head = temp
		end
		@size += 1
	end
	
	def add_last(e)
		if @size == 0
			@tail = DoublyNode.new(e)
			@head = @tail
		else
			temp = DoublyNode.new(e)
			@tail.next = temp
			temp.previous = @tail
			@tail = temp
		end
		@size += 1
	end
	
	def add(index, e)
		if index == 0
			add_last(e)
		elsif index == @size - 1
			add_last(e)
		else
			current = @head
			index.times do
				current = current.next
			end
			temp = DoublyNode.new(e)
			current.previous.next = temp
			temp.previous = current.previous
			temp.next = current
			@size += 1
		end
	end
	
	def remove_first
		data = first
		if @head == @tail
			clear()
		else
			@head = @head.next
			@head.previous = nil
			@size -= 1
		end
		data
	end
	
	def remove_last
		data = last
		if @head == @tail
			clear()
		else
			@tail = @tail.previous
			@tail.next = nil
			@size -= 1
		end
		data
	end
	
	def remove(index)
		if index == 0
			remove_first()
		elsif index == @size - 1
			remove_last()
		else
			current = @head
			index.times do
				current = current.next
			end
			current.previous.next = current.next
			current.next.previous = current.previous
			@size -= 1
			current.data
		end
	end
	
	def include?(e)
		current = @head
		while current
			return true if current.data == e
			current = current.next
		end
		false
	end
	
	def index(e)
		current = @head
		i = 0
		while current
			return i if current.data == e
			current = current.next
			i += 1
		end
		-1
	end
	
	def erase(e)
		i = index(e)
		if i >= 0
			remove(i)
			return true
		end
		false
	end
	
	def clear
		@head = nil
		@tail = nil
		@size = 0
	end
end
