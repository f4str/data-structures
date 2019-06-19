#include "stack.hpp"

template <typename T>
Stack<T>::Stack(T arr[], int length) : Stack() {
	for (int i = 0; i < length; ++i) {
		push(arr[i]);
	}
}

template <typename T>
Stack<T>::~Stack() {
	if (size_ == 0) {
		return;
	}
	
	StackNode<T>* current = top_;
	StackNode<T>* temp = top_->next;
	while (current != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
}

template <typename T>
int Stack<T>::size() {
	return size_;
}

template <typename T>
bool Stack<T>::empty() {
	return size_ == 0;
}

template <typename T>
void Stack<T>::push(T& e) {
	StackNode<T>* temp = new StackNode<T>(e);
	if (size_ == 0) {
		top_ = temp;
	}
	else {
		temp->next = top_;
		top_ = temp;
	}
	++size_;
}

template <typename T>
T& Stack<T>::peek() {
	if (top_ == nullptr) {
		return nullptr;
	}
	return top_->data;
}

template <typename T>
void Stack<T>::pop() {
	if (size_ == 0) {
		return;
	}
	StackNode<T>* current = top_->next;
	delete top_;
	top_ = current;
}

template <typename T>
bool Stack<T>::contains(T& e) {
	StackNode<T>* current = top_;
	while (current != nullptr) {
		if (current->data == e) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
void Stack<T>::clear() {
	if (size_ == 0) {
		return;
	}
	
	StackNode<T>* current = top_;
	StackNode<T>* temp = top_->next;
	while (temp != nullptr) {
		delete current;
		current = temp;
		temp = temp->next;
	}
	delete current;
	
	top_ = nullptr;
	size_ = 0;
}
