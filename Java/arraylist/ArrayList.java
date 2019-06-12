package arraylist;

public class ArrayList<E> {
	public static final int INITIAL_CAPACITY = 16;
	private E[] data;
	private int size;
	
	public ArrayList() {
		data = (E[])(new Object[INITIAL_CAPACITY]);
		size = 0;
	}
	
	public ArrayList(E[] objects) {
		this();
		for (E e : objects) {
			add(e);
		}
	}
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
	
	public int capacity() {
		return data.length;
	}
	
	public E get(int index) {
		return data[index];
	}
	
	public E set(int index, E e) {
		E temp = data[index];
		data[index] = e;
		return temp;
	}
	
	public void add(E e) {
		if (size == data.length) {
			E[] temp = (E[])(new Object[size * 2]);
			System.arraycopy(data, 0, temp, 0, size);
			data = temp;
		}
		data[size] = e;
		size++;
	}
	
	public void insert(int index, E e) {
		if (size == data.length) {
			E[] temp = (E[])(new Object[size * 2]);
			System.arraycopy(data, 0, temp, 0, size);
			data = temp;
		}
		
		for (int i = size - 1; i >= index; i--) {
			data[i + 1] = data[i];
		}
		data[index] = e;
		size++;
	}
	
	public boolean contains(E e) {
		for (E elem : data) {
			if (e.equals(elem)) {
				return true;
			}
		}
		return false;
	}
	
	public E erase(int index) {
		E elem = data[index];
		size--;
		for (int i = index; i < size; i++) {
			data[i] = data[i + 1];
		}
		data[size] = null;
		return elem;
	}
	
	public int indexOf(E e) {
		for (int i = 0; i < size; i++) {
			if (e.equals(data[i])) {
				return i;
			}
		}
		return -1;
	}
	
	public boolean remove(E e) {
		int index = indexOf(e);
		if (index >= 0) {
			remove(index);
			return true;
		}
		return false;
	}
	
	public void clear() {
		data = (E[])(new Object[INITIAL_CAPACITY]);
		size = 0;
	}
}
