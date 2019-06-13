package linkedlist;

public class DoublyLinkedList<E> {
	private class Node<E> {
		private E data;
		private Node<E> next;
		private Node<E> previous;
		
		private Node(E e) {
			data = e;
			next = null;
			previous = null;
		}
	}
	
	private Node<E> head;
	private Node<E> tail;
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
	
	public E head() {
		if (head == null) {
			return null;
		}
		return head.data;
	}
	
	public E tail() {
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
			Node<E> current = head;
			for (int i = 0; i < index; i++) {
				current = current.next;
			}
			return current.data;
		}
	}
	
	public void addFirst(E e) {
		if (size == 0) {
			head = new Node(e);
			tail = head;
		}
		else {
			Node<E> temp = new Node(e);
			temp.next = head;
			head.previous = temp;
			head = temp;
		}
		size++;
	}
	
	public void addLast(E e) {
		if (size == 0) {
			tail = new Node(e);
			head = tail;
		}
		else {
			Node<E> temp = new Node(e);
			tail.next = temp;
			temp.previous = tail;
			tail = temp;
		}
		size++;
	}
	
	public E removeFirst() {
		Node<E> temp = head;
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
		Node<E> temp = tail;
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
		Node<E> current = head;
		while (current != null) {
			if (current.data.equals(e)) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	public int indexOf(E e) {
		Node<E> current = head;
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
			Node<E> current = head;
			for (int i = 0; i <= index; i++) {
				current = current.next;
			}
			Node<E> temp = new Node(e);
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
			Node<E> current = head;
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
		Node<E> current = head;
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
		}
		return false;
	}
	
	public void clear() {
		head = null;
		tail = null;
		size = 0;
	}
}