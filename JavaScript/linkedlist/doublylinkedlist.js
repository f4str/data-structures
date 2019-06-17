class DoublyNode {
	constructor(data) {
		this.data = data;
        this.next = null;
        this.previous = null;
	}
}

class DoublyLinkedList {
	constructor(elems = null) {
		this._head = null;
		this._tail = null;
		this._length = null;
		if (elems) {
			for (let e in elems) {
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
		if (this._head == null) {
			return null;
		}
		return this._head.data;
	}
	
	get last() {
		if (this._tail == null) {
			return null;
		}
		return this._tail.data;
	}
	
	get(index) {
		if (index == 0) {
			return this.first;
		}
		else if (index == this.length - 1) {
			return this.last;
		}
		else {
			let current = this._head;
			for (let i = 0; i < index; i++) {
				current = current.next;
			}
			return current.data;
		}
	}
	
	set first(e) {
		if (this._length == 0) {
			this.addFirst(e);
		}
		else {
			this._head.data = e;
		}
	}
	
	set last(e) {
		if (this._length == 0) {
			this.addLast(e);
		}
		else {
			this._tail.data = e;
		}
	}
	
	set(index, e) {
		if (index == 0) {
			let data = this.first;
			this.first = e;
			return data;
		}
		else if (index == this._length - 1) {
			let data = this.last;
			this.last = e;
			return data;
		}
		else {
			let current = this._head;
			for (let i = 0; i < index; i++) {
				current = current.next;
			}
			let data = current.data;
			current.data = e;
			return data;
		}
	}
	
	addFirst(e) {
		if (this._length == 0) {
			this._head = new DoublyNode(e);
			this._tail = this._head;
		}
		else {
			let temp = new DoublyNode(e);
            temp.next = this._head;
            this._head.previous = temp;
			this._head = temp;
		}
		this._length++;
	}
	
	addLast(e) {
		if (this._length == 0) {
			this._tail = new DoublyNode(e);
			this._head = this._tail;
		}
		else {
			let temp = new DoublyNode(e);
            this._tail.next = temp;
            temp.previous = this._tail;
			this._tail = temp;
		}
		this._length++;
	}
	
	add(index, e) {
		if (index == 0) {
			this.addFirst(e);
		}
		else if (index == this._length - 1) {
			this.addLast(e);
		}
		else {
			let current = this._head;
			for (let i = 0; i <= index; i++) {
				current = current.next;
			}
			let temp = new DoublyNode(e);
            current.previous.next = temp;
            temp.previous = current.previous;
			temp.next = current;
			this._length++;
		}
	}
	
	removeFirst() {
		let data = this.first;
		if (this._head == this._tail) {
			this.clear();
		}
		else {
            this._head = this._head.next;
            this._head.previous = null;
			this._length--;
		}
		return data;
	}
	
	removeLast() {
		let data = this.last;
		if (this._head == this._tail) {
			this.clear();
		}
		else {
            this._tail = this._tail.previous;
            this._tail.next = null;
            this._length--;
        }
        return data;
	}
	
	remove(index) {
		if (index == 0) {
			return this.removeFirst();
		}
		else if (index == this._length - 1) {
			return this.removeLast();
		}
		else {
			let current = this._head;
			for (let i = 0; i <= index; i++) {
				current = current.next;
			}
            current.previous.next = current.next;
            current.next.previous = current.previous;
			this._length--;
			return current.data;
		}
	}
	
	contains(e) {
		let current = this._head;
		while (current != null) {
			if (current.data == e) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	indexOf(e) {
		let current = this._head;
		for (let i = 0; current != null; i++) {
			if (current.data == e) {
				return i;
			}
			current = current.next;
		}
		return -1;
	}
	
	erase(e) {
		let i = this.indexOf(e)
		if (i >= 0) {
			this.remove(i);
			return true;
		}
		return false;
	}
	
	clear() {
		this._head = null;
		this._tail = null;
		this._length = 0;
	}
}
