class DequeNode {
	constructor(data) {
		this.data = data;
        this.next = null;
        this.previous = null;
	}
}

class Deque {
	constructor(elems = null) {
		this._front = null;
		this._back = null;
		this._length = 0;
		if (elems) {
			for (const e of elems) {
				this.addLast(e);
			}
		}
	}
	
	get length() {
		return this._length;
	}
	
	isEmpty() {
		return this._length == 0;
	}
	
	get first() {
		if (this._front == null) {
			return null;
		}
		return this._front.data;
	}
	
	get last() {
		if (this._back == null) {
			return null;
		}
		return this._back.data;
	}
	
	set first(e) {
		if (this._length == 0) {
			this.addFirst(e);
		}
		else {
			this._front.data = e;
		}
	}
	
	set last(e) {
		if (this._length == 0) {
			this.addLast(e);
		}
		else {
			this._back.data = e;
		}
	}
	
	addFirst(e) {
		if (this._length == 0) {
			this._front = new DequeNode(e);
			this._back = this._front;
		}
		else {
			let temp = new DequeNode(e);
            temp.next = this._front;
            this._front.previous = temp;
			this._front = temp;
		}
		this._length++;
	}
	
	addLast(e) {
		if (this._length == 0) {
			this._back = new DequeNode(e);
			this._front = this._back;
		}
		else {
			let temp = new DequeNode(e);
            this._back.next = temp;
            temp.previous = this._back;
			this._back = temp;
		}
		this._length++;
	}
	
	removeFirst() {
		let data = this.first;
		if (this._front == this._back) {
			this.clear();
		}
		else {
            this._front = this._front.next;
            this._front.previous = null;
			this._length--;
		}
		return data;
	}
	
	removeLast() {
		let data = this.last;
		if (this._front == this._back) {
			this.clear();
		}
		else {
            this._back = this._back.previous;
            this._back.next = null;
            this._length--;
        }
        return data;
	}
	
	contains(e) {
		let current = this._front;
		while (current != null) {
			if (current.data == e) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	clear() {
		this._front = null;
		this._back = null;
		this._length = 0;
	}
}
