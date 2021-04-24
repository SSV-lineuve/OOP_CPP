#include "String.h"

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATOR_PLUS_CHECK
//#define CONSTRUCTORS_COLLING

void main()
{
	//setlocale(LC_ALL, "");
	
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

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	//cout << delimiter << endl;
	//String str3 = str1 + str2; //Operator + будет выполнять конкатенацию (слияние, объекдинение) строк
	//cout << delimiter << endl;
	//cout << str3 << endl;

	cout << delimiter << endl;
	str1 += str2;
	cout << str1;
#endif // OPERATOR_PLUS_CHECK

#ifdef CONSTRUCTORS_COLLING
	String str; //Default constructor
	str.print();
	String str1(5);
	str1.print();
	String str2 = "Hello"; //Single-argument constructor
	str2.print();
	String str3("Hello"); //Single-argument constructor
	str3.print();

	String str4(); //Здесь не вызывается конструктор по умолчанию
				   //здесь объявляется функция str4, которая ничего не принимает,
				   //и возвращает значение тип String
	//str4.
	String str5; //Неявный вызов конструктора по умолчанию
	str5.print();
	String str6{}; //Явный вызов конструктора по умолчанию
	str6.print();

	String str7{ "Hello" };
	String("Привет").print(); //Явный вызов конструктора для создания временного безымянного объекта

	String("Привет") == str3;
#endif // CONSTRUCTORS_COLLING
}


