#include <iostream>
#include "Contacts.h"
#include "Person.h"
#include <fstream>
#include <Windows.h>
#include "Menu.h"
#include <functional>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	std::ifstream in("Menu commands.txt");
	std::ofstream out("output.txt");
	
	Contacts contacts;
	Menu menu;

	while (!in.eof()) {
		std::string commandName;
		std::getline(in, commandName);
		menu.addCommand(commandName);
	}
	
	menu.addCommandMethod(contacts.call_AddContact);
	menu.addCommandMethod(contacts.call_FindByFullName);
	menu.addCommandMethod(contacts.call_ChangeByFullName);
	menu.addCommandMethod(contacts.call_FindByPhoneNumber);
	menu.addCommandMethod(contacts.call_GetAllWithFirstLetter);
	menu.addCommandMethod(contacts.call_GetCount);
	menu.addCommandMethod(contacts.call_MakeChosenOne);
	menu.addCommandMethod(contacts.call_MakeNotChosenOne);
	menu.addCommandMethod(contacts.call_GetAllChosenOnes);
	menu.addCommandMethod(contacts.call_deleteContact);
	menu.addCommandMethod(contacts.call_WriteToFile);
	menu.addCommandMethod(contacts.call_ReadFromFile);
	in.close();
	menu.startSelection(0, 0, contacts);
	

	return 0;
}