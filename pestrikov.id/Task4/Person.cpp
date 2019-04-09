#include "Person.h"


Person::Person(const std::string lastName, const std::string firstName, const std::string middleName) :
	firstName(firstName),
	middleName(middleName),
	lastName(lastName)
{}

Person::Person(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber) :
	Person(firstName, middleName, lastName)
{
	this->phoneNumber = phoneNumber;
}

Person::Person(const std::string lastName, const std::string firstName, const std::string middleName, const Date birthday):
	Person(firstName, middleName, lastName) 
{
	this->birthday = birthday;
}
Person::Person(const std::string lastName, const std::string firstName, const std::string middleName, const bool isChosenOne) :
	Person(firstName, middleName, lastName) 
{
	this->isChosenOne = isChosenOne;
}

Person::Person(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const Date birthday):
	Person(firstName, middleName, lastName, phoneNumber) 
{
	this->birthday = birthday;
}

Person::Person(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const bool isChosenOne) :
	Person(firstName, middleName, lastName, phoneNumber) {
	this->isChosenOne = isChosenOne;
}
Person::Person(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const Date birthday, const bool isChosenOne) :
	Person(firstName, middleName, lastName, phoneNumber, birthday) 
{
	this->isChosenOne = isChosenOne;
}

bool Person::operator<(const Person & other) {
	if (lastName < other.lastName) {
		return true;
	}
	if (lastName > other.lastName) {
		return false;
	}

	//if lastName == other.lastName
	if (firstName < other.firstName) {
		return true;
	}
	if (firstName > other.firstName) {
		return false;
	}

	//if firstName == other.firstName
	return middleName < other.middleName;
}

istream & operator>>(istream & in, Person & person) {
	//input format:
	//lastName (type: string)
	//firstName (type: string)
	//middleName (type: string)
	//phoneNumber (type: string)
	//birthday (type: Date) : Date format is day.month.year
	//isChosenOne (type: bool)
	in >> person.lastName >> person.firstName >> person.middleName >> 
		person.phoneNumber >> person.birthday >> person.isChosenOne;
	return in;
}

ostream & operator<<(ostream & out, const Person & person) {
	//output format:
	//lastName (type: string)
	//firstName (type: string)
	//middleName (type: string)
	//phoneNumber (type: string)
	//birthday (type: Date) : Date format is day.month.year
	//isChosenOne (type: bool)
	out << person.lastName << " " << person.firstName << " " << person.middleName << " " 
		<< person.phoneNumber << " " << person.birthday << " " << person.isChosenOne;
	return out;
}
