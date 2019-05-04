class ArrayList {
	constructor() {
		this.data = [];
	}
	
	get length() {
		return this.data.length;
	}
	
	add(e) {
		this.data.push(e);
		this.length++;
	}
	
	set(e, index) {
		this.data[index] = e;
	}
	
	insert(e, index) {
		this.data.splice(index, 0, e);
	}
	
	remove(e) {
		for (let i = 0; i < this.data.length; i++) {
			if (this.data[i] == e) {
				let temp = this.data[i];
				this.data.splice(i, 1);
				return temp;
			}
		}
	}
	
	removeAt(index) {
		this.data.splice(index, 1);
	}
	
	indexOf(e) {
		return this.data.indexOf(e);
	}
	
	clear() {
		this.data = [];
	}
	
	toString() {
		return this.data.toString()
	}
}