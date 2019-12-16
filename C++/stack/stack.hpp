#pragma once

template <typename T>
struct StackNode {
	T data;
	StackNode<T>* next;
	
	StackNode(T& data) : data(data), next(nullptr) {};
};

template <typename T>
class Stack {
	private:
		StackNode<T>* top_;
		int size_;
		
	public:
		Stack() : top_(nullptr), size_(0) {};
		Stack(T arr[], int length);
		~Stack();
		
		int size();
		bool empty();
		void push(T& e);
		T& peek();
		void pop();
		bool contains(T& e);
		void clear();
};
