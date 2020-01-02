package deque;

public class Deque<E> {
	private class DequeNode<E> {
		private E data;
		private DequeNode<E> next;
		private DequeNode<E> previous;
		
		private DequeNode(E e) {
			data = e;
			next = null;
			previous = null;
		}
	}
	
	private DequeNode<E> front;
	private DequeNode<E> back;
	private int size;
	
	public Deque() {
		front = null;
		back = null;
		size = 0;
	}
	
	public Deque(E[] elems) {
		this();
		for (E e : elems) {
			addLast(e);
		}
	}
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
	
	public E getFirst() {
		if (front == null) {
			return null;
		}
		return front.data;
	}
	
	public E getLast() {
		if (back == null) {
			return null;
		}
		return back.data;
	}
	
	public E setFirst(E e) {
		E data = getFirst()
		if (size == 0) {
			addFirst(e);
		}
		else {
			front.data = e;
		}
		return data;
	}
	
	public void setLast(E e) {
		E data = getLast();
		if (size == 0) {
			addLast(e);
		}
		else {
			back.data = e;
		}
		return data;
	}
	
	public void addFirst(E e) {
		if (size == 0) {
			front = new DequeNode<E>(e);
			back = front;
		}
		else {
			DequeNode<E> temp = new DequeNode<E>(e);
			temp.next = front;
			front.previous = temp;
			front = temp;
		}
		size++;
	}
	
	public void addLast(E e) {
		if (size == 0) {
			back = new DequeNode<E>(e);
			front = back;
		}
		else {
			DequeNode<E> temp = new DequeNode<E>(e);
			back.next = temp;
			temp.previous = back;
			back = temp;
		}
		size++;
	}
	
	public E removeFirst() {
		E data = getFirst();
		if (front == back) {
			clear();
		}
		else {
			front = front.next;
			front.previous = null;
			size--;
		}
		return data;
	}
	
	public E removeLast() {
		E data = getLast();
		if (front == back) {
			clear();
		}
		else {
			back = back.previous;
			back.next = null;
			size--;
		}
		return data;
	}
	
	public boolean contains(E e) {
		DequeNode<E> current = front;
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
