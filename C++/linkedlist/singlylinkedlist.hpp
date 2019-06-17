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
		SinglyLinkedList(const SinglyLinkedList* list);
		~SinglyLinkedList();
		T& operator[](int index);
		
		int size();
		bool empty();
		T& getFirst();
		T& getLast();
		T& get(int index);
		T& setFirst(T& e);
		T& setLast(T& e);
		T& set(int index, T& e);
		void addFirst(T& e);
		void addLast(T& e);
		void add(int index, T& e);
		T& removeFirst();
		T& removeLast();
		T& remove(int index);
		bool contains(T& e);
		int index(T& e);
		bool erase(T& e);
		void clear();
};

#endif