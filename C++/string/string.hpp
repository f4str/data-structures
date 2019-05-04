#ifndef STRING_HPP 
#define STRING_HPP

#include <iostream>

class String {
	private:
		char* string;
		int size;
	public:
		String();
		String(const char* str);
		String(const String& str);
		~String();
		int length() const;
		char& operator[](int i);
		void operator+(const String& str);
		bool operator==(const String& str);
		bool operator!=(const String& str);	

		friend std::ostream& operator<<(std::ostream& out, const String& str);
		friend std::istream& operator>>(std::istream& in, String& str);
};

#endif