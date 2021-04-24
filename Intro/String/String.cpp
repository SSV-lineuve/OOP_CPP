#include "String.h"

//////////////////////////////////////////////////////////////////////////////////
//////////////////      CLASS DEFINITION - ОПРЕДЕЛЕНИЕ КЛАССА    /////////////////


int String::get_size()const
{
	return size;
}

/* v возвращает константный указатель (нельзя изменить значение по адресу) */
const char* String::get_str()const//Показывает, что это константный метод
{
	return str;
}
char* String::get_str() //Показывает, что это константный метод
{
	return str;
}

String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size]{};//Это выполнит первый конструктор
	for (int i = 0; str[i]; i++)
		this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i<size; i++)
		this->str[i] = other.str[i];*/
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	/*this->size = other.size;
	this->str = other.str;*/
	other.str = nullptr;  //Указатель на ноль (NULL pointer)
	cout << "MoveConstructor:\t" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//Operators

//char& operator[] (const int index) const
//{
//	return str[index];
//}

String& String::operator=(const String& other)
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

String& String::operator=(String&& other)
{
	if (this == &other) return *this;
	delete[] this->str;

	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;  //Указатель на ноль (NULL pointer)
	cout << "MoveConstructor:\t" << this << endl;

	return *this;
}

String String::operator+=(const String& other)
{
	return *this = *this + other; //Непонятно почему нельзя вернуть просто (*this + other)
}

// Methods
void String::print()const
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

//bool operator ==(const String& left, const String& right)
//{
//	if (left.get_size() != right.get_size())
//	{
//		return false;
//	}
//
//	for (int i = 0; i < left.get_size(); i++)
//	{
//		if (left[i] != right[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}

//bool operator !=(const String& left, const String& right)
//{
//	return !(left==right);
//}

//bool operator<(const String& left, const String& right)
//{
//	if (left.get_size() < right.get_size())
//	{
//		return true;
//	}
//	else if (left.get_size() > right.get_size()) return false;
//
//	for (int i = 0; i < left.get_size(); i++)
//	{
//		if (left[i] < right[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//bool operator<=(const String& left, const String& right)
//{
//	return !(right < left);
//}
//bool operator>(const String& left, const String& right)
//{
//	return right < left;
//}
//bool operator>=(const String& left, const String& right)
//{
//	return !(left < right);
//}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1); //Конструктор принимает размер слова
	for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}

///////////////////////////      CLASS DEFINITION END    /////////////////////////
//////////////////////////////////////////////////////////////////////////////////