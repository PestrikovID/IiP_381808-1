#include <iostream>
#include <fstream>
#include <string>
#include "Calendar.h"
#include <algorithm>
#include <vector>

void DateClassTest();
void CalendarClassTest();
void PrintBorder()
{
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
}
void IncorrectDateTest(short day, short month, short year);
//bool Is_year_leap_test();
void IncorrectSubstractionTest(const Date & date1, const Date & date2);

int main()
{
	DateClassTest();
	PrintBorder();
	CalendarClassTest();

	
	return 0;
}

void DateClassTest()
{
	cout << "------------DATE CLASS TEST----------------" << endl;
	//Constructors test-------------------------------------------------------
	cout << "Constructors test" << endl;
	Date date1;
	cout << "date1: " << date1 << endl;
	Date date2(10, 10, 10);
	cout << "date2: " << date2 << endl;
	Date date3(10, Date::January, 20);
	cout << "date3: " << date3 << endl;
	
	PrintBorder();

	//Attempts to create incorrect dates--------------------------------------
	cout << "Attempts to create incorrect dates" << endl;
	IncorrectDateTest(0, 10, 20); // Day must be > 0 - incorrect
	IncorrectDateTest(1, 10, 20); // Day must be > 0 - correct
	IncorrectDateTest(-1, 10, 20); // Day must be > 0 - incorrect

	IncorrectDateTest(32, 1, 20); // Day must be < 32 - incorrect
	IncorrectDateTest(31, 1, 20); // Day must be < 32 - correct
	IncorrectDateTest(30, 2, 2012); // Day must be < 30 - incorrect
	IncorrectDateTest(29, 2, 2012); // Day must be < 30 - correct
	IncorrectDateTest(29, 2, 2011); // Day must be < 29 - incorrect
	IncorrectDateTest(28, 2, 2011); // Day must be < 29 - correct
	IncorrectDateTest(31, 11, 2012); // Day must be < 31 - incorrect
	IncorrectDateTest(30, 11, 2012); // Day must be < 31 - correct

	IncorrectDateTest(1, 1, 0); // Year must be > 0
	
	IncorrectDateTest(1, 0, 1); // Month musht be > 0 
	IncorrectDateTest(1, -1, 1); // Month musht be > 0
	IncorrectDateTest(1, 13, 1); // Month musht be < 13 

	PrintBorder();

	////Test of Date::is_year_leap()
	//cout << "Test of Date::is_year_leap()" << endl;
	//cout << "Verdict: works " << (Is_year_leap_test() ? "Correct" : "Incorrect!") << endl;
	
	PrintBorder();

	//Arithmetical operators test
	cout << "Arithmetical operators test" << endl;
	cout << "10.2.10 + 4.1.15 = " << Date(10, 2, 10) + Date(4, 1, 15) << endl;
	cout << "10.12.10 + 4.1.15 = " << Date(10, 12, 10) + Date(4, 1, 15) << endl;
	cout << "31.1.10 + 4.1.15 = " << Date(31, 1, 10) + Date(4, 1, 15) << endl;
	cout << "31.12.10 + 4.1.15 = " << Date(31, 12, 10) + Date(4, 1, 15) << endl;
	cout << "28.2.10 + 4.1.15 = " << Date(28, 2, 10) + Date(4, 1, 15) << endl;
	cout << endl;
	
	cout << "1.1.10 - 4.4.5 = " << Date(1, 1, 10) - Date(4, 4, 5) << endl;
	IncorrectSubstractionTest(Date(10, 10, 10), Date(9, 9, 20));
	IncorrectSubstractionTest(Date(10, 10, 10), Date(9, 10, 9));
	IncorrectSubstractionTest(Date(10, 1, 10), Date(11, 12, 8));
	IncorrectSubstractionTest(Date(10, 1, 10), Date(11, 12, 7));

	PrintBorder();

	//Input test
	cout << "Input test" << endl;
	Date date5;
	cout << "Enter date5 (input format is day.month.year) : ";
	cin >> date5;
	cout << endl << "date5 = " << date5 << endl;

	PrintBorder();
}

void IncorrectDateTest(short day, short month, short year)
{
	try
	{
		Date incorrect_date(day, month, year);	
		cout << incorrect_date << "is correct" << endl;
	}
	catch (const exception & ex)
	{
		cout << "date(" << day << ", " << month <<
			", " << year << ") can't be created: " << endl << ex.what() << endl << endl;
	}
}

//bool Is_year_leap_test()
//{
//	ifstream in("Leap years.txt");
//	vector<int> leap_years;
//	while (!in.eof())
//	{
//		int tmp;
//		in >> tmp;
//		leap_years.push_back(tmp);
//	}
//
//	for (int i = 1; i <= 3000; ++i)
//	{
//		if ((binary_search(leap_years.begin(), leap_years.end(), i) != Date::is_year_leap(i)))
//		{
//
//			cout << binary_search(leap_years.begin(), leap_years.end(), i) << " " << i << Date::is_year_leap(i) << endl;
//			return false;
//		}
//	}
//
//	return true;
//}

void IncorrectSubstractionTest(const Date & date1, const Date & date2)
{
	try
	{
		cout << date1 << " - " << date2 << " = ";
		cout << date1 - date2 << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

void CalendarClassTest()
{
	cout << "----------------CALENDAR CLASS TEST---------------------" << endl;

	//Constructors test
	Calendar calendar1;
	Calendar calendar2(Date(1, 1, 1), "new year");
	Calendar calendar3(1, 1, 1, "new year");
	Calendar calendar4(calendar1);

	//Methods test
	cout << "Methods test-----------------------------------------------------" << endl << endl;
	
	calendar1.SetEvent(Date(1, 2, 1), "event");
	cout << "Date of event is " << calendar1.DateOfEvent("event") << endl;
	//Attempt to add the same event twice
	cout << "Attempt to add the same event twice" << endl;
	try
	{
		calendar1.SetEvent(Date(1, 2, 1), "event");
		cout << "Date of event is " << calendar1.DateOfEvent("event") << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	cout << "The difference between " << Date(10, 12, 25) << " and " << calendar1.DateOfEvent("event") <<
		" = " << calendar1.Difference(Date(10, 12, 25), "event") << " days" << endl;

	//Shift date test
	cout << "Shift date test" << endl;
	cout << calendar1.DateOfEvent("event") << " shift forward on 10.10.10 : ";
	calendar1.Shift_date_forward("event", Date(10, 10, 10));
	cout << "event date is " << calendar1.DateOfEvent("event") << endl;
	cout << calendar1.DateOfEvent("event") << " shift backward on 10.10.10 : ";
	calendar1.Shift_date_backward("event", Date(10, 10, 10));
	cout << "event date is " << calendar1.DateOfEvent("event") << endl;

	PrintBorder();

	//Input/output test
	cout << "Input/output test" << endl;
	ifstream in("input.txt");
	in >> calendar1;
	cout << "calendar1:" << endl << calendar1;
	in >> calendar2;
	cout << "calendar2:" << endl << calendar2;


}

