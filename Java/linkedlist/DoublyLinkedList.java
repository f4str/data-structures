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
	
	public E getLast() {
		if (tail == null) {
			return null;
		}
		return tail.data;
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
	
	public E removeFirst() {
		DoublyNode<E> temp = head;
		if (head == tail) {
			head = null;
			tail = null;
			size = 0;
		}
		else {
			head = head.next;
			head.previous = null;
			size--;
		}
		return head.data;
	}
	
	public E removeLast() {
		DoublyNode<E> temp = tail;
		if (head == tail) {
			head = null;
			tail = null;
			size = 0;
		}
		else {
			tail = tail.previous;
			tail.next = null;
			size--;
		}
		return tail.data;
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
	
	public void insert(int index, E e) {
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
	
	public E erase(int index) {
		if (index == 0) {
			removeFirst();
		}
		else if (index == size - 1) {
			removeLast();
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
	
	public boolean remove(E e) {
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