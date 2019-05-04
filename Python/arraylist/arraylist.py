class ArrayList:
	def __init__(self):
		self.data = []
	
	def __len__(self):
		return len(data)
	
	def __getitem__(self, key):
		return self.data[key]
	
	def __contains__(self, key):
		return key in self.data
	
	def add(self, e):
		self.data.append(e)
	
	def insert(self, index, e):
		self.data.insert(index, e)
	
	def clear(self):
		self.data.clear()
	
	def index(self, e):
		for i in len(self.data):
			if self.data[i] == e:
				return i
		return -1
	
	def remove(self, e):
		if e in self.data:
			self.data.remove(e)
			return True
		return False
	
	def remove_at(self, index):
		temp = self.data[index]
		self.data.remove(temp)
		return temp
	
