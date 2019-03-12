#pragma once
#include <exception>
#include <iostream>

class Rational
{
public:
	//Constructors-------------------------------------------------------------------
	Rational(long long n, long long m = 1);
		
	//Getters------------------------------------------------------------------------
	long long Get_n() const { return n; }
	long long Get_m() const { return m; }
	
	void Change_to(long long n, long long m = 1);
	
	//Arithmetical operators----------------------------------------------------------
	Rational operator + (const Rational & other);
	Rational operator - (const Rational & other);
	Rational operator * (const Rational & other);
	Rational operator / (const Rational & other);
	Rational & operator += (const Rational & other);
	Rational & operator -= (const Rational & other);
	Rational & operator *= (const Rational & other);
	Rational & operator /= (const Rational & other);

	Rational & operator++();
	Rational operator++(int);
	Rational & operator--();
	Rational operator--(int);	

	//Comparison operators------------------------------------------------------------
	bool operator== (const Rational & other);
	bool operator!= (const Rational & other);
	bool operator> (const Rational & other);
	bool operator< (const Rational & other);
	bool operator>= (const Rational & other);
	bool operator<= (const Rational & other);
	
	//Types convert operators---------------------------------------------------------
	explicit operator long long() const;

	//Operator = ---------------------------------------------------------------------
	Rational & operator = (const Rational & other);
	
	//Stream input, output operators--------------------------------------------------
	friend std::ostream & operator<< (std::ostream & out, const Rational & rational);
	friend std::istream & operator>> (std::istream & in, Rational & rational);
	
private:
	long long n; //numerator
	long long m; //denominator (can't be = 0, if m = 0 Exception will be thrown)
	
	//Divides n and m by their GCD
	void Reduct_fraction();
	
	//returns Greatest Common Divisor of a and b
	long long GCD(long long a, long long b);	
};

