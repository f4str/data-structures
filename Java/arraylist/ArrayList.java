package arraylist;

public class ArrayList<E> {
	public static final int INITIAL_CAPACITY = 16;
	private E[] data = (E[])(new Object[INITIAL_CAPACITY]);
	private int size = 0;
	
	public ArrayList() {
	}
	
	public ArrayList(E[] objects) {
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
	
	public void add(E e) {
		ensureCapacity();
		data[size++] = e;
	}
	
	public void add(int index, E e){
		index = checkIndex(index);
		ensureCapacity();
		
		for (int i = size - 1; i >= index; i--) {
			data[i + 1] = data[i];
		}
		data[index] = e;
		size++;
	}
	
	public E get(int index) {
		checkIndex(index);
		return data[index];
	}
	
	public boolean contains(E e) {
		for (E elem : data) {
			if (e.equals(elem)) {
				return true;
			}
		}
		return false;
	}
	
	public void clear() {
		data = (E[])(new Object[INITIAL_CAPACITY]);
		size = 0;
	}
	
	public int indexOf(E e) {
		for (int i = 0; i < size; i++) {
			if (e.equals(data[i])) {
				return i;
			}
		}
		return -1;
	}
	
	public E set(int index, E e) {
		checkIndex(index);
		E temp = data[index];
		data[index] = e;
		return temp;
	}
	
	public E remove(int index) {
		checkIndex(index);
		E elem = data[index];
		size--;
		for (int i = index; i < size; i++) {
			data[i] = data[i + 1];
		}
		data[size] = null;
		return elem;
	}
	
	public boolean remove(E e) {
		int index = indexOf(e);
		if (index >= 0) {
			remove(index);
			return true;
		}
		return false;
	}
	
	public void trimToSize() {
		if (size != data.length) {
			E[] temp = (E[])(new Object[size]);
			System.arraycopy(data, 0, temp, 0, size);
			data = temp;
		}
	}
	
	private void ensureCapacity() {
		if (size == data.length) {
			E[] temp = (E[])(new Object[size * 2]);
			System.arraycopy(data, 0, temp, 0, size);
			data = temp;
		}
	}
	
	private void checkIndex(int index) {
		if (index < 0 || index > size) {
			throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
		}
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder("[");
		for (E e : data) {
			sb.append(e);
			sb.append(", ");
		}
		sb.replace(sb.length() - 1, sb.length(), "]");
		return sb.toString();
	}
}
