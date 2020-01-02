#include "deque.hpp"

template <typename T>
Deque<T>::Deque(T arr[], int length) : Deque() {
	for (int i = 0; i < length; ++i) {
		addFirst(arr[i]);
	}
}

template <typename T>
Deque<T>::Deque(const Deque& deque) : Deque() {
	DequeNode<T>* current = deque.front;
	while (current != nullptr) {
		addLast(current->data);
	}
}

template <typename T>
Deque<T>::~Deque() {
	if (size_ == 0) {
		return;
	}
	
	DequeNode<T>* current = front;
	DequeNode<T>* temp = front->next;
	while (temp != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
}

template <typename T>
int Deque<T>::size() {
	return size_;
}

template <typename T>
bool Deque<T>::empty() {
	return size_ == 0;
}


template <typename T>
T& Deque<T>::getFirst() {
	if (front == nullptr) {
		return nullptr;
	}
	return front->data;
}

template <typename T>
T& Deque<T>::getLast() {
	if (tail_ == nullptr) {
		return nullptr;
	}
	return tail_->data;
}

template <typename T>
void Deque<T>::setFirst(T& e) {
	if (size_ == 0) {
		addFirst(e);
	}
	else {
		front->data = e;
	}
}

template <typename T>
void Deque<T>::setLast(T& e) {
	if (size_ == 0) {
		addLast(e);
	}
	else {
		tail_->data = e;
	}
}

template <typename T>
void Deque<T>::addFirst(T& e) {
	DequeNode<T>* temp = new DequeNode<T>(e);
	if (size_ == 0) {
		front = temp;
		tail_ = temp;
	}
	else {
		temp->next = front;
		temp->previous = nullptr;
		front = temp;
	}
	++size_;
}

template <typename T>
void Deque<T>::addLast(T& e) {
	DequeNode<T>* temp = new DequeNode<T>(e);
	if (size_ == 0) {
		tail_ = temp;
		front = temp;
	}
	else {
		tail_->next = temp;
		temp->previous = tail_;
		tail_ = temp;
	}
	++size_;
}

template <typename T>
void Deque<T>::removeFirst() {
	if (front == tail_) {
		clear();
	}
	else {
		DequeNode<T>* current = front->next;
		delete front;
		front = current;
		front->previous = nullptr;
		--size_;
	}
}

template <typename T>
void Deque<T>::removeLast() {
	if (front == tail_) {
		clear();
	}
	else {
		DequeNode<T>* current = tail_->previous;
		delete tail_;
		tail_ = current;
		tail_->next = nullptr;
		--size_;
	}
}

template <typename T>
bool Deque<T>::contains(T& e) {
	DequeNode<T>* current = front;
	while (current != nullptr) {
		if (current->data == e) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
int Deque<T>::index(T& e) {
	DequeNode<T>* current = front;
	for (int i = 0; current != nullptr; ++i) {
		if (current->data == e) {
			return i;
		}
		current = current->next;
	}
	return -1;
}

template <typename T>
void Deque<T>::clear() {
	if (size_ == 0) {
		return;
	}
	
	DequeNode<T>* current = front;
	DequeNode<T>* temp = front->next;
	while (temp != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
	
	front = nullptr;
	tail_ = nullptr;
	size_ = 0;
}
