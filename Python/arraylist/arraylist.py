class ArrayList:
	def __init__(self):
		self._capacity = 16
		self._data = [None] * self._capacity
		self._size = 0
	
	def __len__(self):
		return self._size
	
	def __getitem__(self, key):
		return self._data[key]
	
	def __contains__(self, key):
		return key in self._data
	
	@property
	def capacity(self):
		return self._capacity
	
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
		self._size += 1
		i = self._size
		while i >= index:
			self._data[i] = self._data[i - 1]
		self._data[index] = e
	
	def clear(self):
		self._capacity = 16
		self._data = [None] * self._capacity
		self._size = 0
	
	def index(self, e):
		for i in len(self._data):
			if self._data[i] == e:
				return i
		return -1
	
	def remove(self, e):
		i = self.index(e)
		if i >= 0:
			self.pop(i)
			return True
		return False
	
	def pop(self, index = None):
		if index is None:
			self._size -= 1
			return self._data[self._size]
		temp = self.data[index]
		self._size -= 1
		for i in range(index, self._size):
			self._data[i] = self._data[i + 1]
		return temp
	
