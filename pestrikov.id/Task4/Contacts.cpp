#include "Contacts.h"



Contacts::Contacts(const Array<Person>& persons) {
	contacts = persons;
}

Contacts::Contacts(Person * const persons, int size) {
	if (size < 0) {
		throw exception("Size less than 0");
	}
	contacts.resize(size);
	for (int i = 0; i < size; ++i) {
		contacts[i] = persons[i];
	}
}

void Contacts::AddContact(const Person & contanct) {
	contacts.pushBack(contanct);
	contacts.sort();
}

void Contacts::AddContact(std::string firstName, std::string middleName, std::string lastName) {
	AddContact(Person(firstName, middleName, lastName));
}

void Contacts::AddContact(std::string firstName, std::string middleName, std::string lastName, std::string phoneNumber) {
	AddContact(Person(firstName, middleName, lastName, phoneNumber));
}

void Contacts::AddContact(std::string firstName, std::string middleName, std::string lastName, Date birthday) {
	AddContact(Person(firstName, middleName, lastName, birthday));
}

void Contacts::AddContact(std::string firstName, std::string middleName, std::string lastName, bool isChosenOne) {
	AddContact(Person(firstName, middleName, lastName, isChosenOne));
}

void Contacts::AddContact(std::string firstName, std::string middleName, std::string lastName, std::string phoneNumber, Date birthday) {
	AddContact(Person(firstName, middleName, lastName, phoneNumber, birthday));
}

void Contacts::AddContact(std::string firstName, std::string middleName, std::string lastName, std::string phoneNumber, bool isChosenOne) {
	AddContact(Person(firstName, middleName, lastName, phoneNumber, isChosenOne));
}

void Contacts::AddContact(std::string firstName, std::string middleName, std::string lastName, std::string phoneNumber, Date birthday, bool isChosenOne) {
	AddContact(Person(firstName, middleName, lastName, phoneNumber, birthday, isChosenOne));
}

Person * Contacts::find(const std::string lastName, const std::string firstName, const std::string middleName) {
	int i;
	for (i = 0; i < contacts.getSize(); ++i) 
	{
		if (contacts[i].lastName == lastName && contacts[i].firstName == firstName && contacts[i].middleName == middleName) {
			return &contacts[i];
		}
	}	
	return nullptr;
}

Person * Contacts::find(const std::string phoneNumber) {
	for (int i = 0; i < contacts.getSize(); ++i) {
		if (contacts[i].phoneNumber == phoneNumber) {
			return &contacts[i];
		}
	}
	return nullptr;
}

Array<Person*> Contacts::getAllWithFirstLetter(char letter) {
	Array<Person*> chosen;
	for (int i = 0; i < contacts.getSize(); ++i) {
		if (contacts[i].lastName[0] == letter) {
			chosen.pushBack(&contacts[i]);
		}
	}
	return chosen;
}

Array<Person*> Contacts::getAllChosenOnes() {
	Array<Person*> chosen;
	for (int i = 0; i < contacts.getSize(); ++i) {
		if (contacts[i].isChosenOne) {
			chosen.pushBack(&contacts[i]);
		}
	}
	return chosen;
}

void Contacts::call_AddContact(Contacts& _this) {
	Person person;
	Array<string> name = _this.inputFullName();
	person.lastName = name[0];
	person.firstName = name[1];
	person.middleName = name[2];
	std::cout << "Введите номер телефона: ";	
	std::cin >> person.phoneNumber;
	std::cout << std::endl;
	std::cout << "Введите день рождения (Формат 1.1.1): ";
	std::cin >> person.birthday;
	std::cout << std::endl;
	std::cout << "Введите является контакт избранным (1) или нет (0): ";
	std::cin >> person.isChosenOne;
	std::cout << std::endl;	
	_this.AddContact(person);
}

void Contacts::call_FindByFullName(Contacts& _this) {
	std::string lastName, firstName, middleName;
	Array<string> name = _this.inputFullName();
	lastName = name[0];
	firstName = name[1];
	middleName = name[2];
	Person* person = _this.find(lastName, firstName, middleName);
	if (person != nullptr) {
		std::cout << *person;
	}
	else {
		std::cout << "Такого человека нет в списке контактов";
	}
}

void Contacts::call_ChangeByFullName(Contacts & _this) {
	std::string lastName, firstName, middleName;
	Array<string> name = _this.inputFullName();
	lastName = name[0];
	firstName = name[1];
	middleName = name[2];
	Person* person = _this.find(lastName, firstName, middleName);
	if (person != nullptr) {
		std::cout << _this.deleteContact(person);
		std::cout << "Введите измененные данные контакта\n";
		call_AddContact(_this);
	}
	else {
		std::cout << "Такого человека нет в списке контактов";
	}

}

void Contacts::call_FindByPhoneNumber(Contacts& _this) {
	std::string phoneNumber;
	std::cout << "Введите номер телефона: ";
	std::cin >> phoneNumber;
	std::cout << std::endl;
	
	Person* person = _this.find(phoneNumber);
	if (person != nullptr) {
		std::cout << *person;
	}
	else {
		std::cout << "Такого человека нет в списке контактов";
	}
}

void Contacts::call_GetAllWithFirstLetter(Contacts& _this) {
	std::cout << "Введите букву, по которой будет осуществляться поиск";
	char letter;
	std::cin >> letter;

	Array<Person*> persons = _this.getAllWithFirstLetter(letter);
	for (int i = 0; i < persons.getSize(); ++i) {
		std::cout << *(persons[i]) << std::endl;
	}
	if (persons.getSize() == 0) {
		std::cout << "Таких людей нет в списке контактов";
	}
}

void Contacts::call_GetCount(Contacts& _this) {
	std::cout << "Количество контактов: " << _this.getCount();
}

void Contacts::call_MakeChosenOne(Contacts& _this) {
	std::string lastName, firstName, middleName;
	Array<string> name = _this.inputFullName();
	lastName = name[0];
	firstName = name[1];
	middleName = name[2];
	Person* person = _this.find(lastName, firstName, middleName);
	if (person == nullptr) {
		std::cout << "Такого человека нет в списке контактов";
	}
	else {
		_this.makeChosenOne(_this.find(lastName, firstName, middleName));
		std::cout << "Контакт добавлен в списко избранных";
	}
}

void Contacts::call_MakeNotChosenOne(Contacts& _this) {
	std::string lastName, firstName, middleName;
	Array<string> name = _this.inputFullName();
	lastName = name[0];
	firstName = name[1];
	middleName = name[2];
	Person* person = _this.find(lastName, firstName, middleName);
	if (person == nullptr) {
		std::cout << "Такого человека нет в списке контактов";
	}
	else {
		if (person->isChosenOne == false) {
			std::cout << "Контакт уже не в списке избранных";
		}
		else {
			_this.makeNotChosenOne(_this.find(lastName, firstName, middleName));
			std::cout << "Контакт удален из списка избранных";
		}
	}
}

void Contacts::call_GetAllChosenOnes(Contacts& _this) {
	Array<Person*> persons = _this.getAllChosenOnes();
	for (int i = 0; i < persons.getSize(); ++i) {
		std::cout << *(persons[i]) << std::endl;
	}
	if (persons.getSize() == 0) {
		std::cout << "Таких людей нет в списке контактов";
	}
}

void Contacts::call_deleteContact(Contacts& _this) {
	std::string phoneNumber;
	std::cout << "Введите номер телефона: ";
	std::cin >> phoneNumber;
	std::cout << std::endl;

	Person* person = _this.find(phoneNumber);
	if (person != nullptr) {
		_this.deleteContact(person);
		std::cout << "Контакт удален";
	}
	else {
		std::cout << "Такого человека нет в списке контактов";
	}
}

void Contacts::call_ReadFromFile(Contacts& _this) {
	std::cout << "Введите название файла: ";
	std::string fileName;
	std::cin >> fileName;
	ifstream in(fileName);
	in >> _this;
}

void Contacts::call_WriteToFile(Contacts& _this) {
	std::cout << "Введите название файла: ";
	std::string fileName;
	std::cin >> fileName;
	ofstream out(fileName);
	out << _this;
}

Array<std::string> Contacts::inputFullName() {
	const int NAMES_COUNT = 3;
	Array<string> name(NAMES_COUNT);
	std::cout << "Введите фамилию: ";
	std::cin >> name[0];
	std::cout << std::endl;
	std::cout << "Введите имя: ";
	std::cin >> name[1];
	std::cout << std::endl;
	std::cout << "Введите отчество: ";
	std::cin >> name[2];
	std::cout << std::endl;
	return name;
}


istream & operator>>(istream & in, Contacts & contacts) {
	//input format:
	//size
	//Person1
	//Person2
	//....
	//PersonSize
	
	size_t size;
	in >> size;
	contacts.contacts.resize(size);
	for (int i = 0; i < size; ++i) {
		in >> contacts.contacts[i];
	}
	contacts.contacts.sort();
	return in;
}

ostream & operator<<(ostream & out, const Contacts & contacts) {
	//output format:
	//size
	//Person1
	//Person2
	//....
	//PersonSize
		
	out << contacts.getCount() << "\n";
	for (int i = 0; i < contacts.getCount(); ++i) {
		out << contacts.contacts[i] << "\n";
	}
	return out;
}
