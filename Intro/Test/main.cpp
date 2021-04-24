#include<iostream>
using namespace std;

//#define ASSIGNMENT

void main()
{
	setlocale(LC_ALL, "");

	int b = 2;

	cout << &++b << '\t' << &(b=b+++b) << endl;
	cout << &"Hello" << endl;
}

#ifdef ASSIGNMENT
//Деструктор с nullptr
~Intvec()
{
	log("destructor");
	if (m_data) {
		delete[] m_data;
		m_data = 0;
	}
}

//swap вместо копирования
Intvec& operator=(const Intvec& other)
{
	log("copy assignment operator");
	Intvec tmp(other);
	std::swap(m_size, tmp.m_size);
	std::swap(m_data, tmp.m_data);
	return *this;
}

Intvec& operator=(Intvec&& other)
{
	log("move assignment operator");
	std::swap(m_size, other.m_size);
	std::swap(m_data, other.m_data);
	return *this;
}
#endif // ASSIGNMENT
