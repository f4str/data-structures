#pragma once

template <typename T>
struct DequeNode {
	T data;
	DequeNode<T>* next;
	DequeNode<T>* previous;
	
	DequeNode(T& data) : data(data), next(nullptr), previous(nullptr) {};
};

template <typename T>
class Deque {
	private:
		DequeNode<T>* front;
		DequeNode<T>* back;
		int size_;
	
	public:
		Deque() : front(nullptr), back(nullptr), size_(0) {};
		Deque(T arr[], int length);
		Deque(const Deque& deque);
		~Deque();
		
		int size();
		bool empty();
		T& getFirst();
		T& getLast();
		void setFirst(T& e);
		void setLast(T& e);
		void addFirst(T& e);
		void addLast(T& e);
		void removeFirst();
		void removeLast();
		bool contains(T& e);
		bool erase(T& e);
		void clear();
};
