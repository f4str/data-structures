class DequeNode:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.previous = None


class Deque:
	def __init__(self, elems = None):
		self._front = None
		self._back = None
		self._length = 0
		if elems:
			for e in elems:
				self.add_last(e)
	
	def __len__(self):
		return self._length
	
	def __contains__(self, e):
		return self.contains(e)
	
	def empty(self):
		return self._length == 0
	
	@property
	def first(self):
		return getattr(self._front, 'data', None)
	
	@property 
	def last(self):
		return getattr(self._back, 'data', None)
	
	@first.setter
	def first(self, e):
		if self._length > 0:
			self._front.data = e
		else:
			self.add_first(e)
	
	@last.setter
	def last(self, e):
		if self._length > 0:
			self._back.data = e
		else:
			self.add_last(e)
	
	def add_first(self, e):
		if self._length == 0:
			self._front = DequeNode(e)
			self._back = self._front
		else:
			temp = DequeNode(e)
			temp.next = self._front
			self._front.previous = temp
			self._front = temp
		self._length += 1
	
	def add_last(self, e):
		if self._length == 0:
			self._back = DequeNode(e)
			self._front = self._back
		else:
			temp = DequeNode(e)
			self._back.next = temp
			temp.previous = self._back
			self._back = temp
		self._length += 1
	
	def remove_first(self):
		data = self.first
		if self._front == self._back:
			self.clear()
		else:
			self._front = self._front.next
			self._front.previous = None
			self._length -= 1
		return data
	
	def remove_last(self):
		data = self.last
		if self._front == self._back:
			self.clear()
		else:
			self._back = self._back.previous
			self._back.next = None
			self._length -= 1
		return data
	
	def contains(self, e):
		current = self._front
		while current:
			if current.data == e:
				return True
			current = current.next
		return False
	
	def clear(self):
		self._front = None
		self._back = None
		self._length = 0

