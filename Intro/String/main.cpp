#include<iostream>
using namespace std;

#define delimiter "----------------------------------------------"
//#define COPY_ELISION


#ifdef COPY_ELISION
//int n = 0;
//
//struct C {
//	explicit C(int) {}
//	C(const C&) { ++n; }  // the copy constructor has a visible side effect
//};                      // it modifies an object with static storage duration
//
//int main() {
//	C c1(42);      // direct-initialization, calls C::C(int)
//	C c2 = C(42);  // copy-initialization, calls C::C(const C&)
//
//	std::cout << n << std::endl;  // prints 0 if the copy was elided, 1 otherwise
//}
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


class String;
String operator+(const String& left, const String& right);

class String
{
	int size;  //Размер строки в Байтах
	char* str; //Указатель на строку в динамической памяти

public:

	int get_size()const
	{
		return size;	}

	
	/* v возвращает константный указатель (нельзя изменить значение по адресу) */ 
	const char* get_str()const//Показывает, что это константный метод
	{
		return str;
	}
	char* get_str() //Показывает, что это константный метод
	{
		return str;
	}

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size]{};
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i<size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;  //Указатель на ноль (NULL pointer)
		cout << "MoveConstructor:\t" << this << endl;
	}
	
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//Operators

	char& operator[] (const int index) const
	{
		return str[index];
	}

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		if (this == &other) return *this;		
		delete[] this->str;

		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;  //Указатель на ноль (NULL pointer)
		cout << "MoveConstructor:\t" << this << endl;

		return *this;
	}

	String operator+=(const String& other)	
	{
		return *this = *this + other; //Непонятно почему нельзя вернуть просто (*this + other)
	}

	// Methods
	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

bool operator ==(const String& left, const String& right)
{
	if (left.get_size() != right.get_size())
	{
		return false;
	}

	for (int i = 0; i < left.get_size(); i++)
	{
		if (left[i] != right[i])
		{
			return false;
		}
	}
	return true;
}

bool operator !=(const String& left, const String& right)
{
	return !(left==right);
}

bool operator<(const String& left, const String& right)
{
	if (left.get_size() < right.get_size())
	{
		return true;
	}
	else if (left.get_size() > right.get_size()) return false;

	for (int i = 0; i < left.get_size(); i++)
	{
		if (left[i] < right[i])
		{
			return false;
		}
	}
	return true;
}
bool operator<=(const String& left, const String& right)
{
	return !(right < left);
}
bool operator>(const String& left, const String& right)
{
	return right < left;
}
bool operator>=(const String& left, const String& right)
{
	return !(left < right);
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();	
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size()-1); //Конструктор принимает размер слова
	for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i+left.get_size()-1] = right.get_str()[i];
	return result;
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef CONSTRUCTORS_CHECK
	String str; //Default constructor
	str.print();

	String str1 = "Hello";
	str1.print();
	cout << "str1: " << str1 << endl;
	String str2 = str1;
	cout << "str2: " << str2 << endl;

	str = str2;  //Copy assignment
	cout << str << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
#endif // ASSIGNMENT_CHECK

	String str1 = "Hello";
	String str2 = "World";
	//cout << delimiter << endl;
	//String str3 = str1 + str2; //Operator + будет выполнять конкатенацию (слияние, объекдинение) строк
	//cout << delimiter << endl;
	//cout << str3 << endl;

	cout << delimiter << endl;
	str1 += str2;
	cout << str1;

	
}

