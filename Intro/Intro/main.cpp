#include<iostream>
using namespace std;

#define tab '\t'

class Point //��� ������ Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	//Point(double x)
	//{
	//	//����������� � ����� ���������� ������� ����� �� ������
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgumentConstructor: " << this << endl;
	//}
	/*Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}*/
	//��� ����������� ��� ������ ����������� �� ��������� (� ����� ���� �� ������)
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Operators:
	void operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
	}
	
	// Methods:

	void Print()
	{
		cout << "X = " << x << '\t' << "Y = " << y << endl;
	}
};


//����� - ��� ��� ������
//��������� - ��� ��� ������

//#define STRUCT

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT
	int a;		//��������� ���������� 'a' ���� 'int'
	Point A;	//��������� ���������� 'A' ���� 'Point'
				//��������� ������ ��������� Point
				//������� ��������� ��������� Point
	A.x = 2;
	A.y = 3;

	Point* pA = &A; // ������� ��������� �� 'Point'
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT

	Point A; //��������� ������ ������ Point
	/*A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;*/
	A.Print();

	Point B(2,3);
	B.Print();

	Point C = 5; //Single argument cinstructor
	C.Print();

	Point D = B; //Copy constructor
	D.Print();

	Point E; //Default constructor
	E = D; //Copy assignment
	E.Print();
}