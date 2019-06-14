class SinglyNode:
	def __init__(self, data):
		self.data = data
		self.next = None
	
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
			self._head = SinglyNode(e)
			self._tail = self._head
		else:
			temp = SinglyNode(e)
			temp.next = self._head
			self._head = temp
		self._size += 1
		
	def add_last(self, e):
		if self._size == 0:
			self._tail = SinglyNode(e)
		else:
			temp = SinglyNode(e)
			self._tail.next = temp
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
			self._size -= 1
		return data
	
	def remove_last(self):
		data = self.tail()
		if self._head == self._tail:
			self._head = None
			self._tail = None
			self._size = 0
		else:
			current = self._head
			while current.next != self._tail:
				current = current.next
			current.next = None
			tail = current
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
			previous = self._head
			current = self._head.next
			for _ in range(index):
				previous = current
				current = current.next
			temp = SinglyNode(e)
			previous.next = temp
			temp.next = current
			self._size += 1
		
	def erase(self, index):
		if index == 0:
			self.remove_first()
		elif index == self._size - 1:
			self.remove_last()
		else:
			previous = self._head
			current = self._head.next
			for _ in range(index):
				previous = current
				current = current.next
			previous.next = current.next
			self._size -= 1
			return current.data
		
	def remove(self, e):
		previous = self._head
		current = self._head.next
		while current is not None:
			if current.data == e:
				previous.next = current.next
				self._size -= 1
				return True
			previous = current
			current = current.next
		return False
	
	def clear(self):
		self._head = None
		self._tail = None
		self._size = 0
