#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

template <typename T>
class ArrayList {
	private:
		T* data_;
		int size_;
		int capacity_;
	public:
		static const int INITAL_CAPACITY = 16;
		
		ArrayList() : data_(new T[INITAL_CAPACITY]), size_(0), capacity_(INITAL_CAPACITY) {};
		ArrayList(T arr[], int length);
		~ArrayList();
		T& operator[](int index);
		
		int size();
		int capacity();
		bool empty();
		T& get(int index);
		void set(int index, T& e);
		bool contains(T& e);
		int index(T& e);
		void add(T& e);
		void insert(int index, T& e);
		void remove(int index);
		bool erase(T& e);
		void clear();
};

#endif
