//#include<iostream>
//using namespace std;
//
//void to_fraction(double a);
//
//void main()
//{
//	//double a = 38.40000000000000000085977835793;
//	//double a = 38.394769359938;
//	double a = 0.394769359938;
//	//double a = 2.000045;
//	//double a = 2;
//
//	to_fraction(a);
//}
//
//void to_fraction(double a) //������������� �����? ���� denominator ����� ���� (�� Fraction)
//{
//	int integer = a; //����������� �� ������� �����
//	int numerator = (a - integer + 0.000000000001) * 1000000000; //0.000000000001 - ��. ��������� �����, ����� ���������� 38.4000..., � �� 38.3999... 
//	int denominator = 1E9; //1 000 000 000 - ���-�� �������� � int, �-��� �� � ������ ���� ����� ������������ (INT_MAX 2 147 483 647)
//	//cout << a - integer << endl; //��������
//	if (a - integer) //���� � decimal ���� ������� ����� ((a - integer) ���������� � ��������, �.�. � double)
//	{
//		while (numerator % 10 == 0) //���� � ������� ����� ��������� ����� - ����
//		{
//			numerator /= 10;
//			denominator /= 10;
//		}
//		integer ? cout << integer << "(" << numerator << "/" << denominator << ")" << endl  //���� � decimal ���� ����� �����
//				: cout << numerator << "/" << denominator << endl;							//���� � decimal ��� ����� �����
//	}
//	else cout << integer << endl; //���� � decimal ������ ����� �����
//
//}
//
////void to_fraction(double a)
////{
////	int integer = a,
////	numerator = (a - integer + 0.000000000001) * 1000000000,
////	denominator = 1000000000;	
////	while (numerator % 10 == 0){numerator /= 10; denominator /= 10;}	
////}
//
////void to_fraction(double a) //������������� �����
////{
////	int integer = a;
////	int numerator = (a - integer + 0.000000000001) * 1000000000;
////	//����� ����������� ���� ��������� �������� � ������ ��� � ����� ����� � ����������
////	if (a - integer)
////	{
////		int denominator = 10;
////		while (numerator % 10 == 0) numerator /= 10;
////		int temp = numerator;
////		while (temp /= 10) denominator *= 10;
////		integer ? cout << integer << "(" << numerator << "/" << denominator << ")" << endl
////			: cout << numerator << "/" << denominator << endl;
////	}
////	else cout << integer << endl;
////}

/*
����������� ����� Fraction, ����������� ������� �����.
� ������ ������ ���� ��� ������������ ������, � ��� �� ������:
	- to_proper();		//������������ ����� ��������� � ����������: 11/4 => 2(3/4)
	- to_improper();	//��������� ���������� ����� � ������������: 2(3/4) => 11/4
	- reduce();			//��������� �����: 5/10 => 1/2;
1. �������������� ���������: +, -, *, /;
2. ��������� ������������: +=, -=, *=, /=;
3. Increment/Decrement (++/--);
4. ��������� ���������: ==, !=, >, <, >=, <=;
5. ��������� ��� ������ � ��������: <<, >>
*/

#include <iostream>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:

	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	/*-------------------------------*/
	void set_integer(int x)
	{
		if (x >= 0)this->integer = x;
		else this->integer = -x;
	}
	void set_numerator(int x)
	{
		if (x >= 0)this->numerator = x;
		else this->numerator = -x;
	}
	void set_denominator(int x)
	{
		/*if (x > 0)this->denominator = x;
		else if(x<0) this->denominator = -x;
		else this->denominator = 1;*/
		if (x == 0)throw exception("Zero in denominator");	//������� ����������, � ��������� �� ������
		this->denominator = x;
	}
	/*--------------------------------*/
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "Constructor0:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor1:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		this->integer = decimal; //����������� �� ������� �����
		this->numerator = (decimal - integer + 0.000000000001) * 1000000000; //0.000000000001 - ��. ��������� �����, ����� ���������� 38.4000..., � �� 38.3999... 
		this->denominator = 1E9; //1 000 000 000 - ���-�� �������� � int, �-��� �� � ������ ���� ����� ������������ (INT_MAX 2 147 483 647)
		//cout << a - integer << endl; //��������
		if (decimal - integer) //���� � decimal ���� ������� ����� ((a - integer) ���������� � ��������, �.�. � double)
		{
			while (numerator % 10 == 0) //���� � ������� ����� ��������� ����� - ����
			{
				numerator /= 10;
				denominator /= 10;
			}
		}
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor2:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor3:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->integer = other.integer;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	/*-----------------------------------*/
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator * other.denominator + other.numerator * this->denominator);
		this->set_denominator(this->denominator * other.denominator);
		this->reduce();
		other.reduce();
		return *this;
	}
	Fraction& operator-=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator * other.denominator - other.numerator * this->denominator);
		this->set_denominator(this->denominator * other.denominator);
		this->reduce();
		other.reduce();
		return *this;
	}
	Fraction& operator*=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator * other.numerator);
		this->set_denominator(this->denominator * other.denominator);
		this->reduce();
		other.reduce();
		return *this;
	}
	Fraction& operator/=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator * other.denominator);
		this->set_denominator(this->denominator * other.numerator);
		this->reduce();
		other.reduce();
		return *this;
	}
	Fraction& operator++()
	{
		this->to_improper();
		this->set_numerator(this->numerator + this->denominator);
		this->reduce();
		return *this;

	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		this->to_improper();
		this->set_numerator(this->numerator + this->denominator);
		this->reduce();
		return old;
	}
	Fraction& operator--()
	{
		this->to_improper();
		this->set_numerator(this->numerator - this->denominator);
		this->reduce();
		return *this;

	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		this->to_improper();
		this->set_numerator(this->numerator - this->denominator);
		this->reduce();
		return old;
	}

	//				Type cast operators:
	explicit operator int()const	//explicit - �����
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	operator char()const
	{
		return integer + (double)numerator / denominator;
	}

	/*------------------------------------*/
	void to_proper()
	{
		int i = 1;
		for (; this->numerator >= this->denominator; i++)
		{
			this->numerator = this->numerator - this->denominator;
			this->integer = i;
		}
	}
	void to_improper()
	{
		this->numerator = this->integer * this->denominator + this->numerator;
		this->integer = 0;
	}
	void reduce()
	{
		int CommonMultiple;
		do {
			if ((this->numerator < this->denominator) && (this->numerator != 0))
				CommonMultiple = this->numerator;
			else if (this->numerator > this->denominator)
				CommonMultiple = this->denominator;
			else break;
			for (; CommonMultiple > 0; CommonMultiple--)
			{
				if (!(this->numerator % CommonMultiple) && !(this->denominator % CommonMultiple))
				{
					this->numerator = this->numerator / CommonMultiple;
					this->denominator = this->denominator / CommonMultiple;
					break;
				}
			}
		} while (CommonMultiple != 1);
		this->to_proper();

	}
	void print() const
	{

		if (this->numerator && this->integer)
		{
			cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
		}
		else if (!(this->integer) && this->numerator)
		{
			cout << numerator << "/" << denominator << endl;
		}

		else
			cout << integer << endl;
	}


};

Fraction operator+(Fraction left, Fraction right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator*(Fraction left, Fraction right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator/(Fraction left, Fraction right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	result.to_proper();
	result.reduce();
	return result;
}
/*------------------------------------------------------------*/
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() == right.get_numerator();
}
bool operator!=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() != right.get_numerator();
}
bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() <= right.get_numerator();
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() >= right.get_numerator();
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() > right.get_numerator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() < right.get_numerator();
}
/*-------------------------------------------------------------*/
ostream& operator<<(ostream& os, const Fraction& obj)
{

	if (!(obj.get_numerator()))
		os << obj.get_integer();
	else if (!(obj.get_integer()) && obj.get_numerator())
		os << obj.get_numerator() << "/" << obj.get_denominator();
	else if (obj.get_integer() && obj.get_numerator())
		os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";

	return os;

}
istream& operator>>(istream& is, Fraction& obj) //���� ������� , ����� ����������
{
	int x, y;
	char c;
	is >> x >> c >> y;
	while (c != '/')
	{
		cout << "������� ���������� ��������: "; is >> x >> c >> y;
	}
	obj.set_integer(0);
	obj.set_numerator(x);
	obj.set_denominator(y);
	return is;
}


//#define HOME_WORK
//#define TYPE_CONVERSIONS

void main()
{
	setlocale(LC_ALL, "");
#ifdef HOME_WORK
	Fraction a;
	cout << "������� ����� 'a' � ������� x/y: "; cin >> a;
	cout << "�� ����� ����� 'a': "; cout << a;
	a.to_proper();
	cout << endl;
	cout << "��������� ������������ ����� � ����������: "; a.print();
	a.to_improper();
	cout << "��������� ���������� ����� � ������������: "; a.print();
	a.reduce();
	cout << "��������� �����: "; a.print();
	Fraction b;
	cout << "������� ����� 'b' � ������� x/y: "; cin >> b;
	cout << "�� ����� ����� 'b': "; cout << b << endl;
	cout << "�������� ��������� (a+=b) ����� : "; (a += b).print();
	cout << "�������� ��������� (a-=b) ����� : "; (a -= b).print();
	cout << "�������� ��������� (a*=b) ����� : "; (a *= b).print();
	cout << "�������� ��������� (a/=b) ����� : "; (a /= b).print();
	Fraction c = a + b;
	cout << "�������� ��������� (a+b) ����� : "; c.print();
	c = a - b;
	cout << "�������� ��������� (a-b) ����� : "; c.print();
	c = a * b;
	cout << "�������� ��������� (a*b) ����� : "; c.print();
	c = a / b;
	cout << "�������� ��������� (a/b) ����� : "; c.print();
	cout << "�������� ��������� (++a) ����� : "; (++a).print();
	cout << "�������� ��������� (a++) ����� : "; a++.print();
	cout << "�������� ��������� (--a) ����� : "; (--a).print();
	cout << "�������� ��������� (a--) ����� : "; a--.print();
	cout << "�������� ��������� (a == b) ����� : " << (a == b) << endl;
	cout << "�������� ��������� (a != b) ����� : " << (a != b) << endl;
	cout << "�������� ��������� (a <= b) ����� : " << (a <= b) << endl;
	cout << "�������� ��������� (a >= b) ����� : " << (a >= b) << endl;
	cout << "�������� ��������� (a > b) ����� : " << (a > b) << endl;
	cout << "�������� ��������� (a < b) ����� : " << (a < b) << endl;
#endif // HOME_WORK

#ifdef TYPE_CONVERSIONS
	////����� �������������� �������� 43 � char:
	//cout << (char)43 << endl;	//C-like style
	//cout << char(44) << endl;	//Functional style

	////������� ��������������:
	//int a = 2;		//No conversion
	//double b = 3.4;	//
	//cout << sizeof(a) << endl;
	//cout << sizeof(b) << endl;
	//cout << a / b << endl;	//�������� * ������ ����������� ���������� 'a' � ��� double, 
	//						//����� ������� ��������� double
	//double c = 4;	//�� �������� � ��������
	//int d = c;		//�� �������� � ��������, ��� ������ ������
	//int e = 2.5;	//�� �������� � ��������, � ������� ������

	/*Fraction A(2, 3, 444);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
	double b = A;
	cout << b << endl;
	int c = A;
	cout << c << endl;*/

	Fraction B = (Fraction)3;	//�onversion from 'int' to 'Fraction'
						//�������������� �������� '3' ���� 'int' �� Fraction
						//��� �������������� �������� ��������� ������������ � ����� ����������.
	cout << B << endl;
	B.to_proper();
	cout << B << endl;
	Fraction C(5);
	cout << C << endl;
	Fraction D = Fraction(8);

	Fraction E = 2.754;
	cout << E << endl;
#endif // TYPE_CONVERSIONS

	Fraction A;		//Default constructor
	Fraction B = 3;	//Single argument constructor
	Fraction C(1, 2);
	Fraction D(3, 4, 5);

	//Fraction E = 2.754;
	//Fraction E = 38.40000000000000000085977835793;
	Fraction E = 38.394769359938;
	//Fraction E = 0.394769359938;
	//Fraction E = 2.000045;
	//Fraction E = 2;
	cout << E << endl;
}

/*
-------------------------
operator type()
{
	....
	...
	..
	return value;
}
operator int()
{
	return value;
}
-------------------------
*/