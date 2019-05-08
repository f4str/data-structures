#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>

template <typename T>
class ArrayList {
	private:
		T* data;
		int size;
		int capacity;
	public:
		ArrayList();
		ArrayList(T[] array);
		ArrayList(const ArrayList& list);
		~ArrayList();
		int size();
		int capacity();
		void add(T& e);
		void insert(T& e, int index);
		bool remove(T& e);
		T& erase(int index); 
		
		T& operator[](int index);
		friend std::ostream& operator<<(std::ostream& out, const ArrayList& list);
		friend std::istream& operator>>(std::istream& in, ArrayList& list);
};

#endif