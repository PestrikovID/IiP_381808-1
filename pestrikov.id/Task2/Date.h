#pragma once
#include <string>
#include <exception>
#include <iostream>

using namespace std;

class Date
{
public:
	enum Month
	{
		January = 1, February, March,
		April, May, June,
		July, August, September,
		October, November, December
	};

	//Constuctors------------------------------------------------------------
	Date() : day(1), month(1), year(1)
	{}
	//You can create Date using Word form (e.g. January) or a number (e.g. 1)
	Date(short day, Month month, short year);
	Date(short day, short month, short year);
	
	//Destructor-------------------------------------------------------------
	~Date();

	//Getters----------------------------------------------------------------
	short Get_day() const { return day; }
	short Get_month() const { return month; }
	short Get_year() const { return year; }
	//unsigned char CountOfDays(unsigned char month, short year) const;
		
public:
	void Change_to(short day, short month, short year);
	long long toDays() const;

	//Operators---------------------------------------------------------------- 
	Date operator+(const  Date & other) const;
	Date operator-(const  Date & other) const;

	friend ostream & operator<< (ostream & out, const Date & date);
	friend istream & operator>> (istream & in, Date & date);

private:
	short day, month, year;
		

	// Checks if date is correct returns ""
	// else returns description of error
	string is_correct(short day, short month, short year) const;
	bool is_year_leap(int year) const;
	unsigned char CountOfDays(short month, short year) const;
	string toString() const;
};

