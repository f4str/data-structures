#include "queue.hpp"

template <typename T>
Queue<T>::Queue(T arr[], int length) : Queue() {
	for (int i = 0; i < length; ++i) {
		enqueue(arr[i]);
	}
}

template <typename T>
Queue<T>::~Queue() {
	if (size_ == 0) {
		return;
	}
	
	QueueNode<T>* current = front_;
	QueueNode<T>* temp = front_->next;
	while (temp != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
}

template <typename T>
int Queue<T>::size() {
	return size_;
}

template <typename T>
bool Queue<T>::empty() {
	return size_ == 0;
}

template <typename T>
void Queue<T>::enqueue(T& e) {
	QueueNode<T>* temp = new QueueNode<T>(e);
	if (size_ == 0) {
		front_ = temp;
		back_ = temp;
	}
	else {
		back_->next = temp;
		back_ = temp;
	}
	++size_;
}

template <typename T>
T& Queue<T>::peek() {
	if (front_ == nullptr) {
		return nullptr;
	}
	return front_->data;
}

template <typename T>
void Queue<T>::dequeue() {
	if (front_ == back_) {
		clear();
	}
	else {
		QueueNode<T>* current = front_->next;
		delete front_;
		front_ = current;
		--size_;
	}
}

template <typename T>
bool Queue<T>::contains(T& e) {
	QueueNode<T>* current = front_;
	while (current != nullptr) {
		if (current->data == e) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
void Queue<T>::clear() {
	if (size_ == 0) {
		return;
	}
	QueueNode<T>* current = front_;
	QueueNode<T>* temp = front_->next;
	while (temp != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
	
	front_ = nullptr;
	back_ = nullptr;
	size_ = 0;
}
