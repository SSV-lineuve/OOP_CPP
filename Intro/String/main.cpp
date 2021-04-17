#include<iostream>
using namespace std;
//#define DECIMAL

#ifdef DECIMAL
Fraction(double decimal)
{
	this->integer = decimal; //избавляемся от дробной части
	this->numerator = (decimal - integer + 0.000000000001) * 1000000000; //0.000000000001 - оч. маленькое число, чтобы получилось 38.4000..., а не 38.3999... 
	this->denominator = 1E9; //1 000 000 000 - кол-во разрядов в int, к-рые мы в полной мере можем использовать (INT_MAX 2 147 483 647)
	//cout << a - integer << endl; //проверка
	if (decimal - integer) //если в decimal есть дробная часть ((decimal - integer) приводится к большему, т.е. к double)
	{
		while (numerator % 10 == 0) //пока в дробной части последняя цифра - ноль
		{
			numerator /= 10;
			denominator /= 10;
		}
	}
}
#endif // DECIMAL
class String
{
private:

	char* str;
	int length;

public:
	
	char* get_string()const
	{
		return str;
	}
	void set_string(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = 0;
	}

	String()
	{
		str = {};
		length = 0;
	}
	
	String(const char* str)
	{
		length = strlen(str);
		
		this->str = new char[length + 1];
		
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		
		this->str[length] = 0;

	}
	
	~String()
	{
		delete[] this->str;
	}
	
	String(const String& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = 0;
	}
	
	String& operator =(const String& other)
	{
		
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = 0;
		return *this;
	}
	
	String operator+(const String& other)
	{
		
		String result_str;		

		int this_length = strlen(this->str);
		int other_length = strlen(other.str);

		result_str.length = this_length + other_length;		
		result_str.str = new char[this_length + other_length + 1];
		
		int i = 0;
		for (; i < this_length; i++)
		{
			result_str.str[i] = this->str[i];
		}

		for (int j = 0; j < other_length; j++, i++)
		{
			result_str.str[i] = other.str[j];
		}

		result_str.str[this_length + other_length] = 0;		
		return result_str;
	}
	
	void Print()
	{
		cout << str << endl;
	}

	int Length()
	{
		return length;
	}

	bool operator ==(const String& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator !=(const String& other)
	{
		return !(this->operator==(other));
	}		
};

ostream& operator<<(ostream& os, const String& obj)
{	
	os << obj.get_string();
	return os;
}


void main()
{
	setlocale(LC_ALL, "");

	String str("First");
	String str1(" ");
	String str2("string");

	String result;
	result = str + str1 + str2;	

	result.Print();
	cout << str2 << endl;
	
	result = str.get_string();
	result.Print();

	str.set_string("Third");

	cout << str << endl;

	//*(str.get_string()) = "Hi";

	*(str.get_string()) = 'B';
	*(str.get_string()+1) = 'e';
	*(str.get_string()+2) = 'a';

	str.Print();
}