#include<iostream>
using namespace std;

#define tab '\t'

class Point //тип данных Point
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
	//	//Конструктор с одним параметром создает точку на прямой
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
	//Для компилятора это второй конструктор по умолчанию (а этого быть не должно)
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
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		/*this->x += other.x;
		this->y += other.y;*/
		this->set_x(this->x + other.x);
		this->set_y(this->y + other.y);
		return *this;
	}

	// Increment/Decrement
	Point& operator++() //Prefix increment
	{
		++this->x;
		++this->y;
		return *this;
	}
	Point operator++(int) //Postfix increment
	{
		Point old = *this;
		/*this->x++;
		this->y++;*/
		++*this;
		return old;
	}

	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}
	
	// Methods:

	void Print()
	{
		cout << "X = " << x << '\t' << "Y = " << y << endl;
	}

	//Friends
	//friend Point operator+(const Point& left, const Point& right);
	//friend ostream& operator<<(ostream& os, const Point& obj);

	//Type cast operator

	explicit operator int()const
	{
		return x/y; //просто для примера
	}
	//explicit
		operator double()const
	{
		return x/y; //просто для примера
	}
		operator char()const
		{
			return x / y; //просто для примера
		}


};


Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
bool operator!=(const Point& left, const Point& right)
{	
	return !(left == right);
}


ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X= " << obj.get_x() << tab << "Y = " << obj.get_y();
	//os << "X= " << obj.x << tab << "Y = " << obj.y;
	return os;
}
istream& operator >>(istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

//Класс - это тип данных
//Структура - это тип данных

//#define STRUCT
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define STREAMS
#define TYPE_CONVERSIONS

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT
	int a;		//Объявляем переменную 'a' типа 'int'
	Point A;	//Объявляем переменную 'A' типа 'Point'
				//Объявляем объект структуры Point
				//Создаем экземпляр структуры Point
	A.x = 2;
	A.y = 3;

	Point* pA = &A; // Создаем указатель на 'Point'
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT

#ifdef CONSTRUCTORS_CHECK
	Point A; //Объявляем объект класса Point
/*A.set_x(2);
A.set_y(3);
cout << A.get_x() << tab << A.get_y() << endl;*/
	A.Print();

	Point B(2, 3);
	B.Print();

	Point C = 5; //Single argument cinstructor
	C.Print();

	Point D = B; //Copy constructor
	D.Print();

	Point E; //Default constructor
	E = D; //Copy assignment
	E.Print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point(2, 3);

	A.Print();
	B.Print();
	C.Print();
#endif // ASSIGNMENT_CHECK

#ifdef STREAMS
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	/*Point C = A + B;
	C.Print();
	A.Print();
	B.Print();

	A += B;
	A.Print();
	++A;
	A.Print();
	A++;
	A.Print();*/

	cout << A << tab << B << endl;
	cout << "Введите координаты точки: ";
	cin >> A;
	cout << "Вы ввели: " << A << endl;
#endif // STREAMS

	//Point A(2, 3);
	//Point B(3 ,4);
	///*if (A == B) cout << "Точки равны" << endl;
	//else cout << "Точки разные" << endl;*/

	//cout << (A == B) << endl;

	//cout << A << endl;
	///*A.set_x(33);
	//A.set_y(44);*/

	//A(33, 44);
	//cout << A << endl;

#ifdef TYPE_CONVERSIONS
	////явное преобразование значения в char
	//cout << (char)43 << endl; //C-like style
	//cout << char(44) << endl; //Functional style  

	////Неявные преобразования
	//int a = 2; //No conversion
	//double b = 3.4; //No conversion
	//cout << sizeof(a) << endl;
	//cout << sizeof(b) << endl;
	//cout << a * b << endl; //Оператор * неявно преобразует переменную 'a' в тип double, чтобы вернуть тип double 

	//double c = 4;	//От меньшего к большему
	//int d = c;		//От большего к меньшему без потери данных (в данном случае)
	//int e = 2.5;	//От большего к меньшему с потерей данных

	Point A(1, 3);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
	double b = (double)A;
	cout << b << endl;

	Point B = 3;	//(Implicit) conversion from 'int' to 'Point'
					//Преобразование значения '3' типа int в Point
					//Это преобразование возможно благодаря конструктору с одним параметром
	cout << B << endl;


#endif // TYPE_CONVERSIONS
}

