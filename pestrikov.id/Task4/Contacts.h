#pragma once
#include "Person.h"
#include "Array.h"
#include "Date.h"
#include <algorithm>
#include <Windows.h>
#include <fstream>

class Contacts
{
public:
	
	Contacts() {
		// do nothing
	}

	Contacts(const Array<Person> &persons);
	Contacts(Person * const persons, int size);

	void AddContact(const Person& contanct);
	void AddContact(const std::string lastName, const std::string firstName, const std::string middleName);
	void AddContact(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber);
	void AddContact(const std::string lastName, const std::string firstName, const std::string middleName, const Date birthday);
	void AddContact(const std::string lastName, const std::string firstName, const std::string middleName, const bool isChosenOne);
	void AddContact(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const Date birthday);
	void AddContact(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const bool isChosenOne);
	void AddContact(const std::string lastName, const std::string firstName, const std::string middleName, const std::string phoneNumber, const Date birthday, const bool isChosenOne);

	//returns pointer to Person if it exists
	//else returns nullptr
	Person* find(const std::string lastName, const std::string firstName, const std::string middleName);
	Person* find(const std::string phoneNumber);
	
	Array<Person*> getAllWithFirstLetter(char letter);
	int getCount() const { return contacts.getSize(); }
	void makeChosenOne(Person* person) { person->isChosenOne = true; }
	void makeNotChosenOne(Person* person) { person->isChosenOne = false; }
	Array<Person*> getAllChosenOnes();
	bool deleteContact(Person* person) { return contacts.eraseElement(person); }

	

	//wrapper methods for menu (work only in console)
	static void call_AddContact(Contacts& _this);
	static void call_FindByFullName(Contacts& _this);
	static void call_ChangeByFullName(Contacts& _this);
	static void call_FindByPhoneNumber(Contacts& _this);
	static void call_GetAllWithFirstLetter(Contacts& _this);
	static void call_GetCount(Contacts& _this);
	static void call_MakeChosenOne(Contacts& _this);
	static void call_MakeNotChosenOne(Contacts& _this);
	static void call_GetAllChosenOnes(Contacts& _this);
	static void call_deleteContact(Contacts& _this);
	static void call_ReadFromFile(Contacts& _this);
	static void call_WriteToFile(Contacts& _this);

	friend istream& operator>> (istream& in, Contacts& contacts);
	friend ostream& operator<< (ostream& out, const Contacts& contacts);

private:
	Array<Person> contacts;
	
	//Inputs last name, first name, middle name from console and returns the array containing them
	Array<std::string> inputFullName();	
};

