class QueueNode:
	def __init__(self, data):
		self.data = data
		self.next = None


class Queue:
	def __init__(self, elems = None):
		self._front = None
		self._back = None
		self._length = 0
		if elems:
			for e in elems:
				self.enqueue(e)
	
	def __len__(self):
		return self._length
	
	def __contains__(self, e):
		return self.contains(e)
	
	def empty(self):
		return self._length == 0
	
	def enqueue(self, e):
		if self._length == 0:
			self._back = QueueNode(e)
			self._front = self._back
		else:
			temp = QueueNode(e)
			self._back.next = temp
			self._back = temp
		self._length += 1
	
	def peek(self):
		return getattr(self._front, 'data', None)
	
	def dequeue(self):
		data = self.peek()
		if self._front == self._back:
			self.clear()
		else:
			self._front = self._front.next
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
