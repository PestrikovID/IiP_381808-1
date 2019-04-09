#pragma once
#include <string>
#include "Date.h"
#include <fstream>

class Person
{
public:
	Person(){}
	Person(const std::string lastName, const std::string firstName, const std::string middleName);
	Person(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber);
	Person(const std::string lastName, const std::string firstName, const std::string middleName, const Date birthday);
	Person(const std::string lastName, const std::string firstName, const std::string middleName, const bool isChosenOne);
	Person(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const Date birthday);
	Person(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const bool isChosenOne);
	Person(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const Date birthday, const bool isChosenOne);

	bool operator<(const Person& other);
	
	std::string lastName = "Не указано";
	std::string firstName = "Не указано";
	std::string middleName = "Не указано";
	std::string phoneNumber = "Не указано";
	Date birthday = Date(1, 1, 1);
	bool isChosenOne = false;

	friend std::istream& operator>> (std::istream& in, Person& person);
	friend std::ostream& operator<< (std::ostream& out, const Person& person);
};

