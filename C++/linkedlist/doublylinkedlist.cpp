#include "doublylinkedlist.hpp"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(T arr[], int length) : DoublyLinkedList() {
	for (int i = 0; i < length; ++i) {
		addFirst(arr[i]);
	}
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& list) : DoublyLinkedList() {
	DoublyNode<T>* current = list.head_;
	while (current != nullptr) {
		addLast(current->data);
	}
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	if (size_ == 0) {
		return;
	}
	
	DoublyNode<T>* current = head_;
	DoublyNode<T>* temp = head_->next;
	while (temp != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
}

template <typename T>
T& DoublyLinkedList<T>::operator[](int index) {
	return get(index);
}

template <typename T>
int DoublyLinkedList<T>::size() {
	return size_;
}

template <typename T>
bool DoublyLinkedList<T>::empty() {
	return size_ == 0;
}


template <typename T>
T& DoublyLinkedList<T>::getFirst() {
	if (head_ == nullptr) {
		return nullptr;
	}
	return head_->data;
}

template <typename T>
T& DoublyLinkedList<T>::getLast() {
	if (tail_ == nullptr) {
		return nullptr;
	}
	return tail_->data;
}

template <typename T>
T& DoublyLinkedList<T>::get(int index) {
	if (index == 0) {
		return getFirst();
	}
	else if (index == size_ - 1) {
		return getLast();
	}
	DoublyNode<T>* current = head_;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;
}

template <typename T>
void DoublyLinkedList<T>::setFirst(T& e) {
	if (size_ == 0) {
		addFirst(e);
	}
	else {
		head_->data = e;
	}
}

template <typename T>
void DoublyLinkedList<T>::setLast(T& e) {
	if (size_ == 0) {
		addLast(e);
	}
	else {
		tail_->data = e;
	}
}

template <typename T>
void DoublyLinkedList<T>::set(int index, T& e) {
	if (index == 0) {
		setFirst(e);
	}
	else if (index == size_ - 1) {
		setLast(e);
	}
	else {
		DoublyNode<T>* current = head_;
		for (int i = 0; i < index; ++i) {
			current = current->next;
		}
		current->data = e;
	}
}

template <typename T>
void DoublyLinkedList<T>::addFirst(T& e) {
	DoublyNode<T>* temp = new DoublyNode<T>(e);
	if (size_ == 0) {
		head_ = temp;
		tail_ = temp;
	}
	else {
		temp->next = head_;
		temp->previous = nullptr;
		head_ = temp;
	}
	++size_;
}

template <typename T>
void DoublyLinkedList<T>::addLast(T& e) {
	DoublyNode<T>* temp = new DoublyNode<T>(e);
	if (size_ == 0) {
		tail_ = temp;
		head_ = temp;
	}
	else {
		tail_->next = temp;
		temp->previous = tail_;
		tail_ = temp;
	}
	++size_;
}

template <typename T>
void DoublyLinkedList<T>::add(int index, T& e) {
	if (index == 0) {
		addFirst(e);
	}
	else if (index == size_ - 1) {
		addLast(e);
	}
	else {
		DoublyNode<T>* current = head_;
		for (int i = 0; i < index; ++i) {
			current = current->next;
		}
		DoublyNode<T>* temp = new DoublyNode<T>(e);
		current->previous->next = temp;
		temp->previous = current->previous;
		temp->next = current;
		++size_;
	}
}

template <typename T>
void DoublyLinkedList<T>::removeFirst() {
	if (head_ == tail_) {
		clear();
	}
	else {
		DoublyNode<T>* current = head_->next;
		delete head_;
		head_ = current;
		head_->previous = nullptr;
		--size_;
	}
}

template <typename T>
void DoublyLinkedList<T>::removeLast() {
	if (head_ == tail_) {
		clear();
	}
	else {
		DoublyNode<T>* current = tail_->previous;
		delete tail_;
		tail_ = current;
		tail_->next = nullptr;
		--size_;
	}
}

template <typename T>
void DoublyLinkedList<T>::remove(int index) {
	if (index == 0) {
		removeFirst();
	}
	else if (index == size_ - 1) {
		removeLast();
	}
	else {
		DoublyNode<T>* current = head_;
		for (int i = 0; i < index; ++i) {
			current = current->next;
		}
		current->previous->next = current->next;
		delete current;
		--size_;
	}
}

template <typename T>
bool DoublyLinkedList<T>::contains(T& e) {
	DoublyNode<T>* current = head_;
	while (current != nullptr) {
		if (current->data == e) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
int DoublyLinkedList<T>::index(T& e) {
	DoublyNode<T>* current = head_;
	for (int i = 0; current != nullptr; ++i) {
		if (current->data == e) {
			return i;
		}
		current = current->next;
	}
	return -1;
}

template <typename T>
bool DoublyLinkedList<T>::erase(T& e) {
	int index = index(e);
	if (index >= 0) {
		remove(index);
		return true;
	}
	return false;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
	if (size_ == 0) {
		return;
	}
	
	DoublyNode<T>* current = head_;
	DoublyNode<T>* temp = head_->next;
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
