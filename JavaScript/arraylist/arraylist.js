class ArrayList {
	static INITIAL_CAPACITY = 16;
	
	constructor(elems = null) {
		this._data = new Array(INITIAL_CAPACITY);
		this._length = 0;
		this._capacity = INITIAL_CAPACITY;
		if (elems) {
			for (let e in elems) {
				this.add(e);
			}
		}
	}
	
	get length() {
		return this._length;
	}
	
	get capacity() {
		return this._capacity;
	}
	
	isEmpty() {
		return this._length == 0;
	}
	
	get(index) {
		return this._data[index];
	}
	
	set(index, e) {
		let temp = this._data[index];
		this._data[index] = e;
		return temp;
	}
	
	contains(e) {
		for (let v in this._data) {
			if (v == e) {
				return true;
			}
		}
		return false;
	}
	
	indexOf(e) {
		for (let i = 0; i < this._length; i++) {
			if (this._data[i] == e) {
				return i;
			}
		}
		return -1;
	}
	
	add(e) {
		if (this._length == this._capacity) {
			this._capacity *= 2;
			let temp = new Array(this._capacity);
			for (let i = 0; i < this._length; i++) {
				temp[i] = this._data[i];
			}
			this._data = temp;
		}
		this._data[this._length] = e;
		this._length++;
	}
	
	insert(index, e) {
		if (this._length == this._capacity) {
			this._capacity *= 2;
			let temp = new Array(this._capacity);
			for (let i = 0; i < this._length; i++) {
				temp[i] = this._data[i];
			}
			this._data = temp;
		}
		
		for (let i = this._size - 1; i >= index; i--) {
			this._data[i + 1] = this._data[i];
		}
		this._data[index] = e;
		this._length++;
	}
	
	remove(index) {
		let temp = self.data[index]
		self._size--
		for (let i = index; i < self._length; i++) {
			self._data[i] = self._data[i + 1];
		}
		return temp
	}
	
	erase(e) {
		let i = self.indexOf(e)
		if (i >= 0) {
			self.remove(i);
			return true;
		}
		return false;
	}
	
	clear() {
		this._data = new Array(INITIAL_CAPACITY);
		this._length = 0;
		this._capacity = INITIAL_CAPACITY;
	}
}