#include "singlylinkedlist.hpp"

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(T arr[], int length) : SinglyLinkedList() {
	for (int i = 0; i < length; ++i) {
		addFirst(arr[i]);
	}
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	if (size_ == 0) {
		return;
	}
	
	SinglyNode<T>* current = head_;
	SinglyNode<T>* temp = head_->next;
	while (temp != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
}

template <typename T>
T& SinglyLinkedList<T>::operator[](int index) {
	return get(index);
}

template <typename T>
int SinglyLinkedList<T>::size() {
	return size_;
}

template <typename T>
bool SinglyLinkedList<T>::empty() {
	return size_ == 0;
}


template <typename T>
T& SinglyLinkedList<T>::getFirst() {
	if (head_ == nullptr) {
		return nullptr;
	}
	return head_->data;
}

template <typename T>
T& SinglyLinkedList<T>::getLast() {
	if (tail_ == nullptr) {
		return nullptr;
	}
	return tail_->data;
}

template <typename T>
T& SinglyLinkedList<T>::get(int index) {
	if (index == 0) {
		return getFirst();
	}
	else if (index == size_ - 1) {
		return getLast();
	}
	SinglyNode<T>* current = head_;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;
}

template <typename T>
void SinglyLinkedList<T>::setFirst(T& e) {
	if (size_ == 0) {
		addFirst(e);
	}
	else {
		head_->data = e;
	}
}

template <typename T>
void SinglyLinkedList<T>::setLast(T& e) {
	if (size_ == 0) {
		addLast(e);
	}
	else {
		tail_->data = e;
	}
}

template <typename T>
void SinglyLinkedList<T>::set(int index, T& e) {
	if (index == 0) {
		setFirst(e);
	}
	else if (index == size_ - 1) {
		setLast(e);
	}
	else {
		SinglyNode<T>* current = head_;
		for (int i = 0; i < index; ++i) {
			current = current->next;
		}
		current->data = e;
	}
}

template <typename T>
void SinglyLinkedList<T>::addFirst(T& e) {
	SinglyNode<T>* temp = new SinglyNode<T>(e);
	if (size_ == 0) {
		head_ = temp;
		tail_ = temp;
	}
	else {
		temp->next = head_;
		head_ = temp;
	}
	++size_;
}

template <typename T>
void SinglyLinkedList<T>::addLast(T& e) {
	SinglyNode<T>* temp = new SinglyNode<T>(e);
	if (size_ == 0) {
		tail_ = temp;
		head_ = temp;
	}
	else {
		tail_->next = temp;
		tail_ = temp;
	}
	++size_;
}

template <typename T>
void SinglyLinkedList<T>::add(int index, T& e) {
	if (index == 0) {
		addFirst(e);
	}
	else if (index == size_ - 1) {
		addLast(e);
	}
	else {
		SinglyNode<T>* previous = head_;
		SinglyNode<T>* current = head_->next;
		for (int i = 0; i < index; ++i) {
			previous = current;
			current = current->next;
		}
		SinglyNode<T>* temp = new SinglyNode<T>(e);
		previous->next = temp;
		temp->next = current;
		++size_;
	}
}

template <typename T>
void SinglyLinkedList<T>::removeFirst() {
	if (head_ == tail_) {
		clear();
	}
	else {
		SinglyNode<T>* current = head_->next;
		delete head_;
		head_ = current;
		--size_;
	}
}

template <typename T>
void SinglyLinkedList<T>::removeLast() {
	if (head_ == tail_) {
		clear();
	}
	else {
		SinglyNode<T>* current = head_;
		while (current->next != tail_) {
			current = current->next;
		}
		delete tail_;
		current->next = nullptr;
		tail_ = current;
		--size_;
	}
}

template <typename T>
void SinglyLinkedList<T>::remove(int index) {
	if (index == 0) {
		removeFirst();
	}
	else if (index == size_ - 1) {
		removeLast();
	}
	else {
		SinglyNode<T>* previous = head_;
		SinglyNode<T>* current = head_->next;
		for (int i = 0; i < index; ++i) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
		--size_;
	}
}

template <typename T>
bool SinglyLinkedList<T>::contains(T& e) {
	SinglyNode<T>* current = head_;
	while (current != nullptr) {
		if (current->data == e) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
int SinglyLinkedList<T>::index(T& e) {
	SinglyNode<T>* current = head_;
	for (int i = 0; current != nullptr; ++i) {
		if (current->data == e) {
			return i;
		}
		current = current->next;
	}
	return -1;
}

template <typename T>
bool SinglyLinkedList<T>::erase(T& e) {
	int index = index(e);
	if (index >= 0) {
		remove(index);
		return true;
	}
	return false;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
	if (size_ == 0) {
		return;
	}
	
	SinglyNode<T>* current = head_;
	SinglyNode<T>* temp = head_->next;
	while (temp != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
	
	head_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
}
