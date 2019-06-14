class ArrayList:
	INITIAL_CAPACITY = 16
	
	def __init__(self, elems = None):
		self._capacity = INITIAL_CAPACITY
		self._data = [None] * self._capacity
		self._size = 0
		if elems:
			for e in elems:
				self.add(e)
	
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
	
	@property
	def capacity(self):
		return self._capacity
	
	def empty(self):
		return self._size == 0
	
	def get(self, index):
		return self._data[index]
	
	def set(self, index, e):
		temp = self._data[index]
		self._data[index] = e
		return temp
	
	def add(self, e):
		if self._capacity == self._size:
			self._capacity *= 2
			temp = [None] * self._capacity
			for i in range(self._size):
				temp[i] = self._data[i]
			self._data = temp
		self._data[self._size] = e
		self._size += 1
	
	def insert(self, index, e):
		if self._capacity == self._size:
			self._capacity *= 2
			temp = [None] * self._capacity
			for i in range(self._size):
				temp[i] = self._data[i]
			self._data = temp
		for i in range(self._size, index - 1, -1):
			self._data[i] = self._data[i - 1]
		self._size += 1
		self._data[index] = e
	
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
	
	def erase(self, index):
		temp = self.data[index]
		self._size -= 1
		for i in range(index, self._size):
			self._data[i] = self._data[i + 1]
		return temp
	
	def remove(self, e):
		i = self.index(e)
		if i >= 0:
			self.erase(i)
			return True
		return False
	
	def clear(self):
		self._capacity = INITIAL_CAPACITY
		self._data = [None] * self._capacity
		self._size = 0
