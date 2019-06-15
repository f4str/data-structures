#include "arraylist.hpp"

template <typename T>
ArrayList<T>::ArrayList(T arr[], int length) : ArrayList() {
	for (int i = 0; i < length; ++i) {
		data_[i] = arr[i];
	}
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& list) {
	size_ = list.size;
	capacity_ = list.capacity;
	data_ = new T[capacity_];
	for (int i = 0; i < size_; ++i) {
		data_[i] = list.data[i];
	}
}

template <typename T>
ArrayList<T>::~ArrayList() {
	delete[] data_;
}

template <typename T>
T& ArrayList<T>::operator[](int index) {
	return data_[index];
}

template <typename T>
int ArrayList<T>::size() {
	return size_;
}

template <typename T>
int ArrayList<T>::capacity() {
	return capacity_;
}

template <typename T>
bool ArrayList<T>::empty() {
	return size_ == 0;
}

template <typename T>
T& ArrayList<T>::get(int index) {
	return data_[index];
}

template <typename T>
void ArrayList<T>::set(int index, T& e) {
	data_[index] = e;
}

template <typename T>
bool ArrayList<T>::contains(T& e) {
	for (int i = 0; i < size_; ++i) {
		if (data_[i] == e) {
			return true;
		}
	}
	return false;
}

template <typename T>
int ArrayList<T>::index(T& e) {
	for (int i = 0; i < size_; ++i) {
		if (data_[i] == e) {
			return i;
		}
	}
	return -1;
}

template <typename T>
void ArrayList<T>::add(T& e) {
	if (size_ == capacity_) {
		capacity_ *= 2;
		T temp[] = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			temp[i] = data_[i];
		}
		delete[] data_;
		data_ = temp;
	}
	data_[size_] = e;
	++size_;
}

template <typename T>
void ArrayList<T>::insert(int index, T& e) {
	if (size_ == capacity_) {
		capacity_ *= 2;
		T temp[] = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			temp[i] = data_[i];
		}
		delete[] data_;
		data_ = temp;
	}
	
	for (int i = size_ - 1; i >= index; ++i) {
		data_[i + 1] = data_[i];
	}
	data_[index] = e;
	++size_;
}

template <typename T>
T& ArrayList<T>::remove(int index) {
	T& temp =data_[index];
	--size_;
	for (int i = index; i < size_; ++i) {
		data_[i] = data_[i + 1];
	}
	return temp;
}

template <typename T>
bool ArrayList<T>::erase(T& e) {
	int i = index(e);
	if (i >= 0) {
		remove(i);
		return true;
	}
	return false;
}

template <typename T>
void ArrayList<T>::clear() {
	delete[] data_;
	size_ = 0;
	capacity_ = INITAL_CAPACITY;
	data_ = new T[INITAL_CAPACITY];
}

