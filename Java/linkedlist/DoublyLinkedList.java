package linkedlist;

public class DoublyLinkedList<E> {
	private class DoublyNode<E> {
		private E data;
		private DoublyNode<E> next;
		private DoublyNode<E> previous;
		
		private DoublyNode(E e) {
			data = e;
			next = null;
			previous = null;
		}
	}
	
	private DoublyNode<E> head;
	private DoublyNode<E> tail;
	private int size;
	
	public DoublyLinkedList() {
		head = null;
		tail = null;
		size = 0;
	}
	
	public DoublyLinkedList(E[] elems) {
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
		if (head == null) {
			return null;
		}
		return head.data;
	}
	
	public E getLast() {
		if (tail == null) {
			return null;
		}
		return tail.data;
	}
	
	public E get(int index) {
		if (index == 0) {
			return getFirst();
		}
		else if (index == size - 1) {
			return getLast();
		}
		else {
			DoublyNode<E> current = head;
			for (int i = 0; i < index; i++) {
				current = current.next;
			}
			return current.data;
		}
	}
	
	public E setFirst(E e) {
		E data = getFirst()
		if (size == 0) {
			addFirst(e);
		}
		else {
			head.data = e;
		}
		return data;
	}
	
	public void setLast(E e) {
		E data = getLast();
		if (size == 0) {
			addLast(e);
		}
		else {
			tail.data = e;
		}
		return data;
	}
	
	public E set(int index, E e) {
		if (index == 0) {
			return setFirst(e);
		}
		else if (index == size - 1) {
			return setLast(e);
		}
		else {
			DoublyNode<E> current = head;
			for (int i = 0; i < index; i++) {
				current = current.next;
			}
			E data = current.data;
			current.data = e;
			return data;
		}
	}
	
	public void addFirst(E e) {
		if (size == 0) {
			head = new DoublyNode(e);
			tail = head;
		}
		else {
			DoublyNode<E> temp = new DoublyNode(e);
			temp.next = head;
			head.previous = temp;
			head = temp;
		}
		size++;
	}
	
	public void addLast(E e) {
		if (size == 0) {
			tail = new DoublyNode(e);
			head = tail;
		}
		else {
			DoublyNode<E> temp = new DoublyNode(e);
			tail.next = temp;
			temp.previous = tail;
			tail = temp;
		}
		size++;
	}
	
	public void add(int index, E e) {
		if (index == 0) {
			addFirst(e);
		}
		else if (index == size - 1) {
			addLast(e);
		}
		else {
			DoublyNode<E> current = head;
			for (int i = 0; i <= index; i++) {
				current = current.next;
			}
			DoublyNode<E> temp = new DoublyNode(e);
			current.previous.next = temp;
			temp.previous = current.previous;
			temp.next = current;
			size++;
		}
	}
	
	public E removeFirst() {
		E data = getFirst();
		if (head == tail) {
			clear();
		}
		else {
			head = head.next;
			head.previous = null;
			size--;
		}
		return data;
	}
	
	public E removeLast() {
		E data = getLast();
		if (head == tail) {
			clear();
		}
		else {
			tail = tail.previous;
			tail.next = null;
			size--;
		}
		return data;
	}
	
	public E remove(int index) {
		if (index == 0) {
			return removeFirst();
		}
		else if (index == size - 1) {
			return removeLast();
		}
		else {
			DoublyNode<E> current = head;
			for (int i = 0; i <= index; i++) {
				current = current.next;
			}
			current.previous.next = current.next;
			current.next.previous = current.previous;
			size--;
			return current.data;
		}
	}
	
	public boolean contains(E e) {
		DoublyNode<E> current = head;
		while (current != null) {
			if (current.data.equals(e)) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	public int indexOf(E e) {
		DoublyNode<E> current = head;
		for (int i = 0; current != null; i++) {
			if (current.data = e) {
				return i;
			}
			current = current.next;
		}
		return -1;
	}
	
	public boolean erase(E e) {
		DoublyNode<E> current = head;
		while (current != null) {
			if (current.data.equals(e)) {
				if (current == head) {
					removeFirst();
				}
				else if (current == tail) {
					removeLast();
				}
				else {
					current.previous.next = current.next;
					current.next.previous = current.previous;
					size--;
				}
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	public void clear() {
		head = null;
		tail = null;
		size = 0;
	}
}
