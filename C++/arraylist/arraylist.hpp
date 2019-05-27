#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

template <typename T>
class ArrayList {
	private:
		T* data;
		int size;
		int capacity;
	public:
		ArrayList() : data(new T[10]), size(0), capacity(10);
		ArrayList(const ArrayList& list);
		~ArrayList();
		int size();
		int capacity();
		bool empty();
		T& get(int index);
		void set(T& e, int index);
		void add(T& e);
		void insert(T& e, int index);
		bool remove(T& e);
		void erase(int index); 
		T& operator[](int index);
};

#endif