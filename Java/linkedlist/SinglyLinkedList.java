package linkedlist;

public class SinglyLinkedList<E> {
	private class Node<E> {
		private E data;
		private Node<E> next;
		
		private Node(E e) {
			data = e;
			next = null;
		}
	}
	
	private Node<E> head;
	private Node<E> tail;
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
			size--;
		}
		return temp.data;
	}
	
	public E removeLast() {
		Node<E> temp = tail;
		if (head == tail) {
			head = null;
			tail = null;
			size = 0;
		}
		else {
			Node<E> current = head;
			while (current.next != tail) {
				current = current.next;
			}
			current.next = null;
			tail = current;
			size--;
		}
		return temp.data;
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
			if (current.data.equals(e)) {
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
			Node<E> previous = head;
			Node<E> current = head.next;
			for (int i = 0; i < index; i++) {
				previous = current;
				current = current.next;
			}
			Node<E> temp = new Node(e);
			previous.next = temp;
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
			Node<E> previous = head;
			Node<E> current = head.next;
			for (int i = 0; i < index; i++) {
				previous = current;
				current = current.next;
			}
			previous.next = current.next;
			size--;
			return current.data;
		}
	}
	
	public boolean remove(E e) {
		Node<E> previous = head;
		Node<E> current = head.next;
		while (current.next != null) {
			if (current.data.equals(e)) {
				previous.next = current.next;
				size--;
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