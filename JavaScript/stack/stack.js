class StackNode {
	constructor(data) {
		this.data = data;
		this.next = null;
	}
}

class Stack {
	constructor(elems = null) {
		this._top = null;
		this._length = 0;
		if (elems) {
			for (const e of elems) {
				this.push(e);
			}
		}
	}
	
	get length() {
		return this._length;
	}
	
	isEmpty() {
		return this._length == 0;
	}
	
	push(e) {
		if (this._length == 0) {
			this._top = new StackNode(e);
		}
		else {
			let temp = new StackNode(e);
			temp.next = this._top;
			this._top = temp;
		}
		this._length++;
	}
	
	peek() {
		if (this._top == null) {
			return null;
		}
		return this._top.data;
	}
	
	pop() {
		if (this._length == 0) {
			return null;
		}
		let data = this._top.data;
		this._top = this._top.next;
		this._length--;
		return data;
	}
	
	contains(e) {
		let current = this._top;
		while (current != null) {
			if (current.data == e) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	clear() {
		this._top = null;
		this._length = 0;
	}
}