#pragma once
#include "Date.h"
#include <string>
#include <exception>

using namespace std;

class Calendar
{
public:
	//Constructors--------------------------------------------------------------------
	Calendar();
	//Creates calendar only with one event
	Calendar(Date date, string event_name);
	Calendar(short day, short month, short year, string event_name);
	Calendar(short day, Date::Month month, short year, string event_name);
	Calendar(const Calendar& other);

	//Destructor----------------------------------------------------------------------
	~Calendar();

	//Getters-------------------------------------------------------------------------
	//returns count of events in calendar
	size_t Get_events_count() { return current_size; }

	//Methods-------------------------------------------------------------------------
	void SetEvent(Date date, string event_name);
	const Date& DateOfEvent(string event_name);
	//Returns Difference between date and date of event_name in days
	long long Difference(Date date, string event_name);
	void Shift_date_forward(string event_name, Date shift);
	void Shift_date_backward(string event_name, Date shift);

	//Operators-----------------------------------------------------------------------
	Calendar & operator= (const Calendar & other);

	friend istream & operator>> (istream & in, Calendar & calendar);
	friend ostream & operator<< (ostream & out, const Calendar & calendar);
private:

	Date* dates;
	string* events;
	size_t current_size;
	size_t max_size;

	void Increase_max_size();
	void clear();

	const int BEGIN_SIZE = 10;

	//returns nullptr if no such event exist in the calendar
	//else returns pointer on the date of the event
	Date* does_event_exist(string event_name);
};

