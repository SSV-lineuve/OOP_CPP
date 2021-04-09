#include<iostream>
using namespace std;

class Fraction
{
	int chsl;
	int zntl;
public:
	int get_chsl()const
	{
		return chsl;
	}
	int get_zntl()const
	{
		return zntl;
	}
	void set_chsl(int chsl)
	{
		this->chsl = chsl;
	}
	void set_zntl(int zntl)
	{
		if (!zntl) return;
		this->zntl = zntl;
	}	
	Fraction(double chsl = 0, double zntl = 0)
	{		
		this->chsl = chsl;
		this->zntl = zntl;
		//set_zntl(zntl);
		//cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->chsl = other.chsl;
		this->zntl = other.zntl;
		//cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		//cout << "Destructor:\t\t" << this << endl;
	}

	// Operators:
	Fraction& operator = (const Fraction& other)
	{
		this->chsl = other.chsl;
		this->zntl = other.zntl;
		//cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{		
		if (this->zntl == other.zntl) this->chsl = this->chsl + other.chsl;
		else
		{
			this->chsl = this->chsl * other.zntl + this->zntl * other.chsl;
			this->zntl = this->zntl * other.zntl;
		}		
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		if (this->zntl == other.zntl) this->chsl = this->chsl - other.chsl;
		else
		{
			this->chsl = this->chsl * other.zntl - this->zntl * other.chsl;
			this->zntl = this->zntl * other.zntl;
		}
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		this->chsl = this->chsl * other.chsl;
		this->zntl = this->zntl * other.zntl;
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		this->chsl = this->chsl * other.zntl;
		this->zntl = this->zntl * other.chsl;
		return *this;
	}

	// Increment/Decrement
	Fraction& operator++() //Prefix increment
	{
		this->chsl = this->zntl + this->chsl;		
		return *this;
	}
	Fraction operator++(int) //Postfix increment
	{
		Fraction old = *this;		
		++* this;
		return old;
	}	
	// Methods:
	Fraction& reduce()
	{		
		int a = chsl; int b = zntl;
		while (a != b)
		{
			if (a > b) a-=b;
			else b-=a;				
		}
		zntl = zntl / a;
		chsl = chsl / a;
		return *this;		
	}
	void to_proper()
	{
		this->reduce();
		if (chsl == zntl) cout << chsl / zntl << endl;
		else cout << chsl / zntl << "(" << chsl % zntl << "/" << zntl << ")" << endl;
	}
	void Print() const
	{
		//if (chsl > zntl) this->to_proper();
		//if (chsl == zntl) cout << chsl / zntl << endl;
		//else
		cout << chsl << "/" << zntl << endl;
	}	
};

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	if (left.get_zntl() == right.get_zntl())
	{
		result.set_chsl(left.get_chsl() + right.get_chsl());
		result.set_zntl(left.get_zntl());
	}
	else
	{
		result.set_chsl(left.get_chsl() * right.get_zntl() + left.get_zntl() * right.get_chsl());
		result.set_zntl(left.get_zntl() * right.get_zntl());
	}
	return result;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;
	if (left.get_zntl() == right.get_zntl())
	{
		result.set_chsl(left.get_chsl() - right.get_chsl());
		result.set_zntl(left.get_zntl());
	}
	else
	{
		result.set_chsl(left.get_chsl() * right.get_zntl() - left.get_zntl() * right.get_chsl());
		result.set_zntl(left.get_zntl() * right.get_zntl());
	}
	return result;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_chsl(left.get_chsl() * right.get_chsl());
	result.set_zntl(left.get_zntl() * right.get_zntl());	
	return result;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_chsl(left.get_chsl() * right.get_zntl());
	result.set_zntl(left.get_zntl() * right.get_chsl());
	return result;
}
bool operator==(const Fraction& left, const Fraction& right)
{	
	if (left.get_zntl() == right.get_zntl()) return (left.get_chsl() == right.get_chsl());	
	else return (left.get_chsl() * right.get_zntl() == left.get_zntl() * right.get_chsl());	
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	if (left.get_zntl() == right.get_zntl()) return (left.get_chsl() > right.get_chsl());
	else return (left.get_chsl() * right.get_zntl() > left.get_zntl() * right.get_chsl());
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(right > left);
}
bool operator<(const Fraction& left, const Fraction& right)
{
	return (right > left);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
	/*if (obj.get_chsl() > obj.get_zntl())
		os << obj.get_chsl() / obj.get_zntl() << "(" << obj.get_chsl() % obj.get_zntl() << "/" << obj.get_zntl() << ")" << endl;
	if (obj.get_chsl() == obj.get_zntl()) os << obj.get_chsl() / obj.get_zntl() << endl;
	else*/
		os << obj.get_chsl() << "/" << obj.get_zntl();	
	return os;
}
istream& operator >>(istream& is, Fraction& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_chsl(x);
	obj.set_zntl(y);
	return is;
}

void main()
{
	setlocale(LC_ALL, "");

	Fraction A(5, 18);
	Fraction B(7, 12);	

	cout << "Дробь A: " << A << endl;	
	cout << "Дробь B: " << B << endl;

	Fraction C = A + B;	
	Fraction D = A - B;

	cout << "A + B = " << C << endl;
	cout << "Сокращенный вариант данной дроби: " << C.reduce() << endl;	
	cout << "A - B = " << D << endl;
	A /= B;	
	cout << "A /= B будет: " << A << endl;
	cout << "значение дроби A в результате постфиксного инкремента: ";
	A++.Print();
	cout << "значение дроби A после постфиксного инкремента: ";
	A.Print();
	cout << "Правильная дробь A: ";
	A.to_proper();

	(A <= B) ? cout << "A <= B " << endl : cout << "A > B" << endl;

	cout << A << " + " << B << " * " << C << " = " << A + B * C << endl;

	cout << Fraction(A + B * C).reduce() << endl;
	Fraction(A + B * C).to_proper();
}