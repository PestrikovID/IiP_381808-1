#include "Calendar.h"


Calendar::Calendar()
{
	dates = new Date[BEGIN_SIZE];
	events = new string[BEGIN_SIZE];
	current_size = 0;
	max_size = BEGIN_SIZE;
}

Calendar::Calendar(Date date, string event_name) : Calendar()
{
	dates[current_size] = date;
	events[current_size] = event_name;
	current_size = 1;
}

Calendar::Calendar(short day, short month, short year, string event_name) 
	: Calendar(Date(day, month, year), event_name)
{}

Calendar::Calendar(short day, Date::Month month, short year, string event_name)
	: Calendar(Date(day, month, year), event_name)
{}

Calendar::Calendar(const Calendar & other)
{
	max_size = other.max_size;
	current_size = other.current_size;
	dates = new Date[max_size];
	events = new string[max_size];

	for (int i = 0; i < current_size; ++i)
	{
		dates[i] = other.dates[i];
		events[i] = other.events[i];
	}
}


Calendar::~Calendar()
{
	clear();
}

void Calendar::SetEvent(Date date, string event_name)
{
	if (does_event_exist(event_name) != nullptr)
	{
		throw exception("Such event is already in calendar!");
	}

	if (current_size == max_size)
	{
		Increase_max_size();
	}

	dates[current_size] = date;
	events[current_size] = event_name;
	++current_size;
}

const Date & Calendar::DateOfEvent(string event_name)
{
	Date* result = does_event_exist(event_name);
	if (result == nullptr)
	{
		throw exception("No such event is calendar!");
	}

	return *result;
}

long long Calendar::Difference(Date date, string event_name)
{
	Date* result = does_event_exist(event_name);
	if (result == nullptr)
	{
		throw exception("No such event is calendar!");
	}

	return date.toDays() - result->toDays();
}

void Calendar::Shift_date_backward(string event_name, Date shift)
{
	Date* result = does_event_exist(event_name);
	if (result == nullptr)
	{
		throw exception("Can't shift event date: event does not exist!");
	}

	*result = *result - shift;
}

void Calendar::Shift_date_forward(string event_name, Date shift)
{
	Date* result = does_event_exist(event_name);
	if (result == nullptr)
	{
		throw exception("Can't shift event date: event does not exist!");
	}

	*result = *result + shift;


}

Calendar & Calendar::operator=(const Calendar & other)
{
	if (this == &other)
	{
		return *this;
	}
	
	clear();
	max_size = other.max_size;
	current_size = other.current_size;
	dates = new Date[max_size];
	events = new string[max_size];

	for (int i = 0; i < current_size; ++i)
	{
		dates[i] = other.dates[i];
		events[i] = other.events[i];
	}

	return *this;
}

void Calendar::Increase_max_size()
{
	max_size *= 1.5;
	Date* new_dates = new Date[max_size];
	string* new_events = new string[max_size];

	for (int i = 0; i < current_size; ++i)
	{
		new_dates[i] = dates[i];
		new_events[i] = events[i];
	}

	clear();
	dates = new_dates;
	events = new_events;
}

void Calendar::clear()
{
	delete[] dates;
	delete[] events;
} 

Date * Calendar::does_event_exist(string event_name)
{
	for (int i = 0; i < current_size; ++i)
	{
		if (events[i] == event_name)
		{
			return &dates[i];
		}
	}
	return nullptr;
}

istream & operator>>(istream & in, Calendar & calendar)
{
	//input format:
	//size
	//date1 event_name_size1 event_name1
	//date2 event_name_size2 event_name2
	//....
	//dateSize event_name_sizeSize event_nameSize
	//-----------------------------------------------------------------------------
	//IMPORTATNT: on each line must be only one construction (date event_name_size event_name)
	//ELSE IT WON'T WORK CORRECT
	//-----------------------------------------------------------------------------

	calendar.clear();
	in >> calendar.current_size;
	calendar.dates = new Date[calendar.current_size];
	calendar.events = new string[calendar.current_size];
	calendar.max_size = calendar.current_size;
	for (int i = 0; i < calendar.current_size; ++i)
	{
		int event_size;
		in >> calendar.dates[i] >> event_size;
		char event_name[100];
		in.getline(event_name, event_size + 2);
		calendar.events[i] = event_name;
		//delete the first symbol - space before the event name
		calendar.events[i].erase(calendar.events[i].begin());
	}
	return in;
}

ostream & operator<<(ostream & out, const Calendar & calendar)
{
	//output format:
	//size
	//date1 event_name_size1 event_name1
	//date2 event_name_size2 event_name2
	//....
	//dateSize event_name_sizeSize event_nameSize
	out << calendar.current_size << endl;
	for (int i = 0; i < calendar.current_size; ++i)
	{
		out << calendar.dates[i] << " " << calendar.events[i].size() << " " << calendar.events[i] << endl;
	}
	return out;
}
