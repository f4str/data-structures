class ArrayList:
	INITIAL_CAPACITY = 16
	
	def __init__(self, elems = None):
		self._capacity = INITIAL_CAPACITY
		self._data = [None] * self._capacity
		self._length = 0
		if elems:
			for e in elems:
				self.add(e)
	
	def __len__(self):
		return self._length
	
	def __getitem__(self, index):
		return self._data[index]
	
	def __setitem__(self, index, e):
		elf._data[index] = e
	
	def __contains__(self, e):
		return self.contains(e)
	
	@property
	def capacity(self):
		return self._capacity
	
	def empty(self):
		return self._length == 0
	
	def get(self, index):
		return self._data[index]
	
	def set(self, index, e):
		temp = self._data[index]
		self._data[index] = e
		return temp
	
	def contains(self, e):
		for i in self._data:
			if i == key:
				return True
		return False
	
	def index(self, e):
		for i, v in enumerate(self.data):
			if v == e:
				return i
		return -1
	
	def add(self, e):
		if self._capacity == self._length:
			self._capacity *= 2
			temp = [None] * self._capacity
			for i in range(self._length):
				temp[i] = self._data[i]
			self._data = temp
		self._data[self._length] = e
		self._length += 1
	
	def insert(self, index, e):
		if self._capacity == self._length:
			self._capacity *= 2
			temp = [None] * self._capacity
			for i in range(self._length):
				temp[i] = self._data[i]
			self._data = temp
		for i in range(self._length, index - 1, -1):
			self._data[i] = self._data[i - 1]
		self._length += 1
		self._data[index] = e
	
	def remove(self, index):
		temp = self.data[index]
		self._length -= 1
		for i in range(index, self._length):
			self._data[i] = self._data[i + 1]
		return temp
	
	def erase(self, e):
		i = self.index(e)
		if i >= 0:
			self.remove(i)
			return True
		return False
	
	def clear(self):
		self._capacity = INITIAL_CAPACITY
		self._data = [None] * self._capacity
		self._length = 0
