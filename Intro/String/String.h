#pragma once
#pragma warning(disable : 4326)
#include<iostream>
using namespace std;

#define delimiter "----------------------------------------------"
//#define COPY_ELISION


#ifdef COPY_ELISION
int n = 0;

struct C {
	explicit C(int) {}
	C(const C&) { ++n; }  // the copy constructor has a visible side effect
};                      // it modifies an object with static storage duration

int main() {
	C c1(42);      // direct-initialization, calls C::C(int)
	C c2 = C(42);  // copy-initialization, calls C::C(const C&)

	std::cout << n << std::endl;  // prints 0 if the copy was elided, 1 otherwise
}
struct C {
	C() = default;
	C(const C&) { std::cout << "A copy was made.\n"; }
};

C f() {
	return C();
}

int main() {
	std::cout << "Hello World!\n";
	C obj = f();
}
#endif // COPY_ELISION


//class String; //Короткое объявление класса
//String operator+(const String& left, const String& right); //Объявление оператора
//ostream& operator<<(ostream& os, const String& obj);

//////////////////////////////////////////////////////////////////////////////////
//////////////////      CLASS DECLARATION - ОБЪЯВЛЕНИЕ КЛАССА    /////////////////

class String
{
	int size;  //Размер строки в Байтах
	char* str; //Указатель на строку в динамической памяти

public:

	int get_size()const;

	/* v возвращает константный указатель (нельзя изменить значение по адресу) */
	const char* get_str()const;
	char* get_str();

	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);

	~String();

	//Operators

	//char& operator[] (const int index);
	String& operator=(const String& other);
	String& operator=(String&& other);
	String operator+=(const String& other);

	// Methods
	void print()const;
};

String operator+(const String& left, const String& right); //Объявление оператора
ostream& operator<<(ostream& os, const String& obj);

///////////////////////////      CLASS DECLARATION END    ////////////////////////
//////////////////////////////////////////////////////////////////////////////////