#include <iostream>
#include "Rational.h"
#include <vector>
#include <string>

using namespace std;

void print_border()
{
	cout << endl << "----------------------------------" << endl << endl;
}

void Test()
{
	

	//Output of true/false instead of 1/0
	std::cout << std::boolalpha;

	//Test of constructors
	cout << "Test of constructors" << endl;

	//Creation of rational numbers
	Rational rat1(12, 2), rat2(2, 3);
	cout << "rat1 = " << rat1 << endl << "rat2 = " << rat2 << endl;

	//Creation of rational number only with integer part
	Rational rat3(10);
	cout << "rat3 = " << rat3 << endl;

	print_border();

	//Attempt to create rational number with denominator = 0
	try
	{
		Rational rat4(4, 0);
	}
	catch (const exception & ex)
	{
		cout << "rat4(4,0) can't be created - " << ex.what() << endl;
	}

	print_border();

	//Test of input and output
	cout << "Input and output test" << endl;
	Rational rat5(1, 1);
	cout << "Enter (input format n/m): rat5 = ";
	cin >> rat5;
	cout << endl << "rat5 = " << rat5 << endl;

	print_border();

	//Test of arithmetical operators
	cout << "Test of arithmetical operators" << endl;
	cout << rat1 << " + " << rat2 << " = " << rat1 + rat2 << endl;
	cout << rat1 << " - " << rat2 << " = " << rat1 - rat2 << endl;
	cout << rat1 << " * " << rat2 << " = " << rat1 * rat2 << endl;
	cout << rat1 << " / " << rat2 << " = " << rat1 / rat2 << endl;

	print_border();

	//Attempt to divide by 0
	cout << "Attempt to divide by 0" << endl;
	try
	{
		cout << "4/3 / 0 = ";
		//Answer will not be printed
		//You can't divide rational number by 0

		cout << Rational(4, 3) / Rational(0);
	}
	catch (const std::exception& ex)
	{
		cout << endl << ex.what() << endl;
	}

	print_border();

	//Test of shorten arithmetical operators
	cout << "Test of shorten arithmetical operators" << endl;
	cout << rat1 << " += " << rat2 << " -> ";
	rat1 += rat2;
	cout << "rat1 = " << rat1 << endl;
	cout << rat1 << " -= " << rat2 << " -> ";
	rat1 -= rat2;
	cout << "rat1 = " << rat1 << endl;
	cout << rat1 << " *= " << rat2 << " -> ";
	rat1 *= rat2;
	cout << "rat1 = " << rat1 << endl;
	cout << rat1 << " /= " << rat2 << " -> ";
	rat1 /= rat2;
	cout << "rat1 = " << rat1 << endl;

	print_border();

	//Attempt to divide by 0
	cout << "Attempt to divide by 0" << endl;
	try
	{
		cout << "rat1 /= 0 -> rat1 = ";
		//Answert will not be printed
		//You can't divide rational number by 0
		rat1 /= Rational(0);
		cout << rat1 << endl;
	}
	catch (const std::exception& ex)
	{
		cout << endl << ex.what() << endl;
	}

	print_border();

	//Test of operators ++, --
	cout << "Test of operators ++, --" << endl;
	rat1.Change_to(5, 4);

	cout << "rat1 = " << rat1 << endl;
	cout << "++rat1 = " << ++rat1 << endl;

	cout << "rat1 = " << rat1 << endl;
	cout << "rat1++ = " << rat1++ << endl;

	cout << "rat1 = " << rat1 << endl;
	cout << "--rat1 = " << --rat1 << endl;

	cout << "rat1 = " << rat1 << endl;
	cout << "rat1-- = " << rat1-- << endl;
	cout << "rat1 = " << rat1 << endl;

	print_border();
	
	//Test of comparison operators
	cout << "Test of comparison operators" << endl;
	cout << "2/3 == 2/3 ? " << (Rational(2, 3) == Rational(2, 3)) << endl;
	cout << "2/3 != 2/3 ? " << (Rational(2, 3) != Rational(2, 3)) << endl;
	cout << endl;

	//Test of operator >
	cout << "2/3 > 1/3 ? " << (Rational(2, 3) > Rational(1, 3)) << endl;
	cout << "2/3 > 4/3 ? " << (Rational(2, 3) > Rational(4, 3)) << endl;
	cout << "2/3 > 2/3 ? " << (Rational(2, 3) > Rational(2, 3)) << endl;
	cout << endl;

	//Test of operator <
	cout << "2/3 < 1/3 ? " << (Rational(2, 3) < Rational(1, 3)) << endl;
	cout << "2/3 < 4/3 ? " << (Rational(2, 3) < Rational(4, 3)) << endl;
	cout << "2/3 < 2/3 ? " << (Rational(2, 3) < Rational(2, 3)) << endl;
	cout << endl;

	//Test of operator >=
	cout << "2/3 >= 2/3 ? " << (Rational(2, 3) >= Rational(2, 3)) << endl;
	cout << "5/4 >= 2/3 ? " << (Rational(5, 4) >= Rational(2, 3)) << endl;
	cout << "1/3 >= 2/3 ? " << (Rational(1, 3) >= Rational(2, 3)) << endl;
	cout << endl;

	//Test of operator <=
	cout << "2/3 <= 2/3 ? " << (Rational(2, 3) <= Rational(2, 3)) << endl;
	cout << "5/4 <= 2/3 ? " << (Rational(5, 4) == Rational(2, 3)) << endl;
	cout << "1/3 <= 2/3 ? " << (Rational(1, 3) <= Rational(2, 3)) << endl;

	print_border();

	//Test of operator =
	cout << "Test of operator =" << endl;
	cout << "rat1 = " << rat1 << " rat2 = " << rat2 << endl;
	cout << "rat1 = rat2 -> rat1 = ";
	rat1 = rat2;
	cout << rat1 << endl;

	print_border();


	//Test of type convert operator (to int)
	cout << "Test of type convert operator (to int)" << endl;
	//cout << "(int)5/2 = " << Rational(5, 2) << endl;

	print_border();
}

int main()
{
	Test();

	system("pause");
	return 0;
}