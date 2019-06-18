#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

template <typename T>
struct DoublyNode {
	T data;
	DoublyNode<T>* next;
	
	DoublyNode(T& data) : data(data), next(nullptr) {};
};

template <typename T>
class DoublyLinkedList {
	private:
		DoublyNode<T>* head_;
		DoublyNode<T>* tail_;
		int size_;
	
	public:
		DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {};
		DoublyLinkedList(T arr[], int length);
		DoublyLinkedList(const DoublyLinkedList& list);
		~DoublyLinkedList();
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
