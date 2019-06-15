package linkedlist;

public class SinglyLinkedList<E> {
	private class SinglyNode<E> {
		private E data;
		private SinglyNode<E> next;
		
		private SinglyNode(E e) {
			data = e;
			next = null;
		}
	}
	
	private SinglyNode<E> head;
	private SinglyNode<E> tail;
	private int size;
	
	public SinglyLinkedList() {
		head = null;
		tail = null;
		size = 0;
	}
	
	public SinglyLinkedList(E[] elems) {
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
			SinglyNode<E> current = head;
			for (int i = 0; i < index; i++) {
				current = current.next;
			}
			return current.data;
		}
	}
	
	public E setFirst(E e) {
		E data = getFirst();
		if (size == 0) {
			addFirst(e);
		}
		else {
			head.data = e;
		}
		return data;
	}
	
	public E setLast(E e) {
		E data = getLast()
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
			SinglyNode<E> current = head;
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
			head = new SinglyNode(e);
			tail = head;
		}
		else {
			SinglyNode<E> temp = new SinglyNode(e);
			temp.next = head;
			head = temp;
		}
		size++;
	}
	
	public void addLast(E e) {
		if (size == 0) {
			tail = new SinglyNode(e);
			head = tail;
		}
		else {
			SinglyNode<E> temp = new SinglyNode(e);
			tail.next = temp;
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
			SinglyNode<E> previous = head;
			SinglyNode<E> current = head.next;
			for (int i = 0; i < index; i++) {
				previous = current;
				current = current.next;
			}
			SinglyNode<E> temp = new SinglyNode(e);
			previous.next = temp;
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
			SinglyNode<E> current = head;
			while (current.next != tail) {
				current = current.next;
			}
			current.next = null;
			tail = current;
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
			SinglyNode<E> previous = head;
			SinglyNode<E> current = head.next;
			for (int i = 0; i < index; i++) {
				previous = current;
				current = current.next;
			}
			previous.next = current.next;
			size--;
			return current.data;
		}
	}
	
	public boolean contains(E e) {
		SinglyNode<E> current = head;
		while (current != null) {
			if (current.data.equals(e)) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	public int indexOf(E e) {
		SinglyNode<E> current = head;
		for (int i = 0; current != null; i++) {
			if (current.data.equals(e)) {
				return i;
			}
			current = current.next;
		}
		return -1;
	}
	
	public boolean erase(E e) {
		SinglyNode<E> previous = head;
		SinglyNode<E> current = head.next;
		while (current != null) {
			if (current.data.equals(e)) {
				previous.next = current.next;
				size--;
				return true;
			}
			previous = current;
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
