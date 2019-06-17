class SinglyNode {
	constructor(data) {
		this.data = data;
		this.next = null;
	}
}

class SinglyLinkedList {
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
			this._head = new SinglyNode(e);
			this._tail = this._head;
		}
		else {
			let temp = new SinglyNode(e);
			temp.next = this._head;
			this._head = temp;
		}
		this._length++;
	}
	
	addLast(e) {
		if (this._length == 0) {
			this._tail = new SinglyNode(e);
			this._head = this._tail;
		}
		else {
			let temp = new SinglyNode(e);
			this._tail.next = temp;
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
			let previous = this._head;
			let current = this._head.next;
			for (let i = 0; i < index; i++) {
				previous = current;
				current = current.next;
			}
			let temp = new SinglyNode(e);
			previous.next = temp;
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
			let current = this._head;
			while (current.next != this._tail) {
				current = current.next;
			}
			current.next = null;
			this._tail = current;
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
			let previous = this._head;
			let current = this._head.next;
			for (let i = 0; i < index; i++) {
				previous = current;
				current = current.next;
			}
			previous.next = current.next;
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
