package queue;

public class Queue<E> {
	private class QueueNode<E> {
		private E data;
		private QueueNode<E> next;
		
		private QueueNode(E e) {
			data = e;
			next = null;
		}
	}
	
	private QueueNode<E> front;
	private QueueNode<E> back;
	private int size;
	
	public Queue() {
		front = null;
		back = null;
		size = 0;
	}
	
	public Queue(E[] elems) {
		this();
		for (E e : elems) {
			enqueue(e);
		}
	}
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
	
	public void enqueue(E e) {
		if (size == 0) {
			back = new QueueNode<E>(e);
			front = back;
		}
		else {
			QueueNode<E> temp = new QueueNode<E>(e);
			back.next = temp;
			back = temp;
		}
		size++;
	}
	
	public E peek() {
		if (front = null) {
			return null;
		}
		return front.data;
	}
	
	public E dequeue() {
		E data = peek();
		if (front == back) {
			clear();
		}
		else {
			front = front.next;
			size--;
		}
		return data;
	}
	
	public boolean contains(E e) {
		QueueNode<E> current = front;
		while (current != null) {
			if (current.data.equals(e)) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	public void clear() {
		front = null;
		back = null;
		size = 0;
	}
}
