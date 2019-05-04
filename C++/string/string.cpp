#include "string.hpp"

String::String() {
	string = nullptr;
	size = 0;
}

String::String(const char* str) {
	size = 0;
	const char* temp = str;
	while (*temp) {
		++size;
	}
	string = new char[size];
	for (int i = 0; i < size; ++i) {
		string[i] = str[i];
	}
}

String::String(const String& str) {
	size = str.size;
	string = new char[size];
	for (int i = 0; i < size; ++i) {
		string[i] = str.string[i];
	}
}

String::~String() {
	delete[] string;
}

int String::length() const {
	return size;
}

char& String::operator[](int i) {
	if (i >= 0) {
		return string[i];
	}
	else {
		return string[size - i];
	}
}

bool String::operator==(const String& str2) {
	if (size != str2.size) {
		return false;
	}
	for (int i = 0; i < size; ++i) {
		if (string[i] != str2.string[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator!=(const String& str) {
	return !(*this == str);
}

int main() {
	//String* s = new String("hello");
	//std::cout << s << std::endl;
	String s;
	std::cout << s << std::endl;
	return 0;
}
