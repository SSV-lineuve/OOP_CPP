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
//ƒеструктор с nullptr
~Intvec()
{
	log("destructor");
	if (m_data) {
		delete[] m_data;
		m_data = 0;
	}
}

//swap вместо копировани€
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


//кстати говор€, если бы написали напр.: str1 += 2;
//и при этом конструктор String(int size = 80) не был бы explicit,
//то этот конструктор отработал бы(в результате изменилс€ бы размер Сstr1Т на 2 байта)???
//Ѕольше того Ц это возможно даже если конструктор explicit Ц если передать:
//str1 += String(2);

//в динамических массивах тоже можно скопировать указатетль, а старому присвоить nulptr?

//такую же логику, как в MoveConstructor можно реализовать в CopyConstructor?