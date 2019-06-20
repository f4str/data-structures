class QueueNode {
	constructor(data) {
		this.data = data;
		this.next = null;
	}
}

class Queue {
	constructor(elems = null) {
		this._front = null;
		this._back = null;
		this._length = 0;
		if (elems) {
			for (let e in elems) {
				this.enqueue(e);
			}
		}
	}
	
	get length() {
		return this._length;
	}
	
	isEmpty() {
		return this._length == 0;
	}
	
	enqueue(e) {
		if (this._length == 0) {
			this._back = new QueueNode(e);
			this._front = this._back;
		}
		else {
			let temp = new QueueNode(e);
			this._back.next = temp;
			this._back = temp;
		}
		this._length++;
	}
	
	peek() {
		if (this._front == null) {
			return null;
		}
		return this._front.data;
	}
	
	dequeue() {
		let data = this.peek();
		if (this._front == this._back) {
			this.clear();
		}
		else {
			this._front = this._front.next;
			this._length++;
		}
		return data;
	}
	
	clear() {
		this._front = null;
		this._back = null;
		this._length = 0;
	}
}