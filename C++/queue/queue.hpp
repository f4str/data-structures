#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
struct QueueNode {
	T data;
	QueueNode<T>* next;
	
	QueueNode(T& data) : data(data), next(nullptr) {};
};

template <typename T>
class Queue {
	private:
		QueueNode<T>* front_;
		QueueNode<T>* back_;
		int size_;
	
	public:
		Queue() : front_(nullptr), back_(nullptr), size_(0) {};
		Queue(T arr[], int length);
		~Queue();
		
		int size();
		bool empty();
		void enqueue(T& e);
		T& peek();
		void dequeue();
		bool contains(T& e);
		void clear();
};

#endif
