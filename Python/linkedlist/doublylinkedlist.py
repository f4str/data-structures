class DoublyNode:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.previous = None
	
class SinglyLinkedList:
	def __init__(self, elems = None):
		self._head = None
		self._tail = None
		self._size = 0
		if elems:
			for e in elems:
				self.add_last(e)
	
	def __len__(self):
		return self._size
	
	def __getitem__(self, index):
		return self.get(index)
	
	def __setitem__(self, index, e):
		self.set(index, e)
	
	def __contains__(self, e):
		return self.contains(e)
	
	@property
	def size(self):
		return self._size
	
	def empty(self):
		return self._size == 0
	
	@property
	def first(self):
		return getattr(self._head, 'data', None)
	
	@first.setter
	def first(self, e):
		if self._size > 0:
			self._head.data = e
		else:
			self.add_first(e)
	
	@property 
	def last(self):
		return getattr(self._tail, 'data', None)
	
	@last.setter
	def last(self, e):
		if self._size > 0:
			self._tail.data = e
		else:
			self.add_last(e)
	
	def get(self, index):
		if index == 0:
			return self.head
		elif index == self._size - 1:
			return self.tail
		else:
			current = self.head
			for _ in range (index):
				current = current.next
			return current.data
	
	def set(self, index, e):
		if index == 0:
			data = self.first
			self.first = e
			return data
		elif index == self._size - 1:
			data = self.last
			self.last = e
			return data
		else:
			current = self.head
			for _ in range (index):
				current = current.next
			data = current.data
			current.data = e
			return data
	
	def add_first(self, e):
		if self._size == 0:
			self._head = DoublyNode(e)
			self._tail = self._head
		else:
			temp = DoublyNode(e)
			temp.next = self._head
			self._head.previous = temp
			self._head = temp
		self._size += 1
		
	def add_last(self, e):
		if self._size == 0:
			self._tail = DoublyNode(e)
		else:
			temp = DoublyNode(e)
			self._tail.next = temp
			temp.previous = self._tail
			self._tail = temp
		self._size += 1
	
	def remove_first(self):
		data = self.head()
		if self._head == self._tail:
			self._head = None
			self._tail = None
			self._size = 0
		else:
			self._head = self._head.next
			self._head.previous = None
			self._size -= 1
		return data
	
	def remove_last(self):
		data = self.tail()
		if self._head == self._tail:
			self._head = None
			self._tail = None
			self._size = 0
		else:
			self._tail = self._tail.previous
			self._tail.next = None
			self._size -= 1
		return data
	
	def contains(self, e):
		current = self._head
		while current is not None:
			if current.data == e:
				return True
			current = current.next
		return False
	
	def index(self, e):
		current = self._head
		i = 0
		while current is not None:
			if current.data == e:
				return i
			current = current.next
			i += 1
		return -1
	
	def insert(self, index, e):
		if index == 0:
			self.add_last(e)
		elif index == self._size - 1:
			self.add_last(e)
		else:
			current = self._head
			for _ in range(index + 1):
				current = current.next
			temp = DoublyNode(e)
			current.previous.next = temp
			temp.previous = current.previous
			temp.next = current
			self._size += 1
		
	def erase(self, index):
		if index == 0:
			self.remove_first()
		elif index == self._size - 1:
			self.remove_last()
		else:
			current = self._head
			for _ in range(index + 1):
				current = current.next
			current.previous.next = current.next
			current.next.previous = current.previous
			self._size -= 1
			return current.data
		
	def remove(self, e):
		current = self._head
		while current is not None:
			if current.data == e:
				if current == self._head:
					self.remove_first()
				elif current == self._tail:
					self.remove_last()
				else:
					current.previous.next = current.next
					current.next.previous = current.previous
					self._size -= 1
				return True
			current = current.next
		return False
	
	def clear(self):
		self._head = None
		self._tail = None
		self._size = 0
