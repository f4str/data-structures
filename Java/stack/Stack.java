package stack;

public class Stack<E> {
	private class StackNode<E> {
		private E data;
		private StackNode<E> next;
	
		private StackNode(E e) {
			data = e;
			next = null;
		}
	}
	
	private StackNode<E> top;
	private int size;
	
	public Stack() {
		top = null;
		size = 0;
	}
	
	public Stack(E[] elems) {
		this();
		for (E e : elems) {
			push(e);
		}
	}
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
	
	public void push(E e) {
		if (size == 0) {
			top = new StackNode<E>(e);
		}
		else {
			StackNode<E> temp = new SinglyNode<E>(e);
			temp.next = top;
			top = temp;
		}
		size++;
	}
	
	public E peek() {
		if (top == null) {
			return null;
		}
		return top.data;
	}
	
	public E pop() {
		if (size == 0) {
			return null;
		}
		E data = top.data;
		top = top.next;
		size--;
		return data;
	}
	
	public boolean contains(E e) {
		StackNode<E> current = top;
		while (current != null) {
			if (current.data.equals(e)) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	public void clear() {
		top = null;
		size = 0;
	}
}
