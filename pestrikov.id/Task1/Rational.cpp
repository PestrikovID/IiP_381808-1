#include "Rational.h"


Rational::Rational(long long n, long long m)
{
	Change_to(n, m);
}

void Rational::Change_to(long long n, long long m)
{
	if (m == 0)
	{
		throw std::exception("Denominator is 0!!!");
	}
	this->n = n;
	this->m = m;
	Reduct_fraction();
}

Rational Rational::operator+(const Rational & other)
{
	return Rational(n * other.m + m * other.n, m * other.m);
}

Rational Rational::operator-(const Rational & other)
{
	return Rational(n * other.m - m * other.n, m * other.m);
}

Rational Rational::operator*(const Rational & other)
{
	return Rational(n * other.n, m * other.m);
}

Rational Rational::operator/(const Rational & other)
{
	if (other.n == 0)
	{
		throw std::exception("Exception: Can't divide rational number by 0!!!");
	}
	return Rational(n * other.m, m * other.n);
}

Rational & Rational::operator+=(const Rational & other)
{
	n = n * other.m + m * other.n;
	m *= other.m;
	Reduct_fraction();
	return *this;
}

Rational & Rational::operator-=(const Rational & other)
{
	n = n * other.m - m * other.n;
	m *= other.m;
	Reduct_fraction();
	return *this;
}

Rational & Rational::operator*=(const Rational & other)
{
	n *= other.n;
	m *= other.m;
	Reduct_fraction();
	return *this;
}

Rational & Rational::operator/=(const Rational & other)
{
	if (other.n == 0)
	{
		throw std::exception("Exception: Can't divide rational number by 0!!!");
	}
	n *= other.m;
	m *= other.n;
	Reduct_fraction();
	return *this;
}

Rational & Rational::operator++()
{
	n += m;
	return *this;
}

Rational Rational::operator++(int)
{
	Rational temp(*this);
	++(*this);
	return temp;
}

Rational & Rational::operator--()
{
	n -= m;
	return *this;
}

Rational Rational::operator--(int)
{
	Rational temp(*this);
	--(*this);
	return temp;
}

bool Rational::operator==(const Rational & other)
{
	return n == other.n && m == other.m;
}

bool Rational::operator!=(const Rational & other)
{
	return !(*this == other);
}

bool Rational::operator>(const Rational & other)
{
	return n * other.m > m * other.n;
}

bool Rational::operator<(const Rational & other)
{
	return n * other.m < m * other.n;
}

bool Rational::operator>=(const Rational & other)
{
	return !(*this < other);
}

bool Rational::operator<=(const Rational & other)
{
	return !(*this > other);
}

Rational::operator long long() const
{
	return (long long)(n / m);
}

Rational & Rational::operator=(const Rational & other)
{
	if (*this == other)
	{
		return *this;
	}
	n = other.n;
	m = other.m;
	return *this;
}

void Rational::Reduct_fraction()
{
	long long divisor = GCD(abs(n), abs(m));
	n /= divisor;
	m /= divisor;
}

long long Rational::GCD(long long a, long long b)
{
	while (b > 0)
	{
		a = a % b;
		std::swap(a, b);
	}
	return a;
}

std::ostream & operator<<(std::ostream & out, const Rational & rational)
{
	if (rational.n != 0 && rational.m != 1)
	{
		out << rational.n << "/" << rational.m;
	}
	else
	{
		out << rational.n << "/" << 1;
	}
	return out;
}

std::istream & operator>>(std::istream & in, Rational & rational)
{
	//format of input: n/m
	char separator;
	in >> rational.n >> separator >> rational.m;
	return in;
}
