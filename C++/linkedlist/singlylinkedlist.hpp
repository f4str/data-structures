#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

template <typename T>
struct SinglyNode {
	T data;
	SinglyNode<T>* next;
	
	SinglyNode(T& data) : data(data), next(nullptr) {};
};

template <typename T>
class SinglyLinkedList {
	private:
		SinglyNode<T>* head_;
		SinglyNode<T>* tail_;
		int size_;
	
	public:
		SinglyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {};
		SinglyLinkedList(T arr[], int length);
		~SinglyLinkedList();
		T& operator[](int index);
		
		int size();
		bool empty();
		T& getFirst();
		T& getLast();
		T& get(int index);
		void setFirst(T& e);
		void setLast(T& e);
		void set(int index, T& e);
		void addFirst(T& e);
		void addLast(T& e);
		void add(int index, T& e);
		void removeFirst();
		void removeLast();
		void remove(int index);
		bool contains(T& e);
		int index(T& e);
		bool erase(T& e);
		void clear();
};

#endif
