#pragma once
#pragma once
#include <cmath>

class Triangle
{
private:
	double a, b, c;

public:
	Triangle() : a(0), b(0), c(0)
	{}

	Triangle(double a, double b, double c)
	{
		Resize(a, b, c);
	}

	void Resize(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	bool Is_exist()
	{
		return (a < (b + c)) && (b < (a + c)) && (c < (a + b));
	}

	double Area()
	{
		int p = Perimeter() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	double Get_a() { return a; }
	double Get_b() { return b; }
	double Get_c() { return c; }

	double Perimeter()
	{
		return a + b + c;
	}

};



