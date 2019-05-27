#include "arraylist.hpp"

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& list) {
	size = list.size;
	capacity = list.capacity;
	data = new T[capacity];
	for (int i = 0; i < size; ++i) {
		data[i] = list.data[i];
	}
}

template <typename T>
ArrayList<T>::~ArrayList() {
	delete[] data;
}

template <typename T>
int ArrayList<T>::size() {
	return size;
}

template <typename T>
int ArrayList<T>::capacity() {
	return capacity;
}

template <typename T>
bool ArrayList<T>::empty() {
	return size == 0;
}

template <typename T>
T& ArrayList<T>::get(int index) {
	return data[index];
}

template <typename T>
void ArrayList<T>::set(T& e, int index) {
	data[index] = e;
}

template <typename T>
void ArrayList<T>::add(T& e);

template <typename T>
void ArrayList<T>::insert(T& e, int index);

template <typename T>
bool ArrayList<T>::remove(T& e);

template <typename T>
T& ArrayList<T>::erase(int index); 

template <typename T>
T& ArrayList<T>::operator[](int index) {
	return data[index];
}
