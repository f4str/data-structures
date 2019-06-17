class SinglyNode:
	def __init__(self, data):
		self.data = data
		self.next = None


class SinglyLinkedList:
	def __init__(self, elems = None):
		self._head = None
		self._tail = None
		self._length = 0
		if elems:
			for e in elems:
				self.add_last(e)
	
	def __len__(self):
		return self._length
	
	def __getitem__(self, index):
		return self.get(index)
	
	def __setitem__(self, index, e):
		self.set(index, e)
	
	def __contains__(self, e):
		return self.contains(e)
	
	def empty(self):
		return self._length == 0
	
	@property
	def first(self):
		return getattr(self._head, 'data', None)
	
	@property 
	def last(self):
		return getattr(self._tail, 'data', None)
	
	def get(self, index):
		if index == 0:
			return self.first
		elif index == self._length - 1:
			return self.last
		else:
			current = self._head
			for _ in range(index):
				current = current.next
			return current.data
	
	@first.setter
	def first(self, e):
		if self._length > 0:
			self._head.data = e
		else:
			self.add_first(e)
	
	@last.setter
	def last(self, e):
		if self._length > 0:
			self._tail.data = e
		else:
			self.add_last(e)
	
	def set(self, index, e):
		if index == 0:
			data = self.first
			self.first = e
		elif index == self._length - 1:
			data = self.last
			self.last = e
		else:
			current = self._head
			for _ in range(index):
				current = current.next
			data = current.data
			current.data = e
		return data
	
	def add_first(self, e):
		if self._length == 0:
			self._head = SinglyNode(e)
			self._tail = self._head
		else:
			temp = SinglyNode(e)
			temp.next = self._head
			self._head = temp
		self._length += 1
	
	def add_last(self, e):
		if self._length == 0:
			self._tail = SinglyNode(e)
			self._head = self._tail
		else:
			temp = SinglyNode(e)
			self._tail.next = temp
			self._tail = temp
		self._length += 1
	
	def add(self, index, e):
		if index == 0:
			self.add_last(e)
		elif index == self._length - 1:
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
			self._length += 1
	
	def remove_first(self):
		data = self.first
		if self._head == self._tail:
			self.clear()
		else:
			self._head = self._head.next
			self._length -= 1
		return data
	
	def remove_last(self):
		data = self.last
		if self._head == self._tail:
			self.clear()
		else:
			current = self._head
			while current.next != self._tail:
				current = current.next
			current.next = None
			tail = current
			self._length -= 1
		return data
	
	def remove(self, index):
		if index == 0:
			return self.remove_first()
		elif index == self._length - 1:
			return self.remove_last()
		else:
			previous = self._head
			current = self._head.next
			for _ in range(index):
				previous = current
				current = current.next
			previous.next = current.next
			self._length -= 1
			return current.data
	
	def contains(self, e):
		current = self._head
		while current:
			if current.data == e:
				return True
			current = current.next
		return False
	
	def index(self, e):
		current = self._head
		i = 0
		while current:
			if current.data == e:
				return i
			current = current.next
			i += 1
		return -1
	
	def erase(self, e):
		i = self.index(e)
		if i >= 0:
			self.remove(i)
			return True
		return False
	
	def clear(self):
		self._head = None
		self._tail = None
		self._length = 0

