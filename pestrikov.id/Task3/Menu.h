#pragma once
#include <string>
#include <iostream>
#include "Array.h"
#include <Windows.h>
#include <conio.h>

class Menu
{
public:

	//Constructors---------------------------------------------------------------
	Menu();
	Menu(size_t count); 


	//Operators------------------------------------------------------------------
	std::string& operator[](size_t index) { return commands[index]; }
	const std::string& operator[](size_t index) const { return commands[index]; }
	friend std::istream& operator>>(std::istream& in, Menu& menu);
	friend std::ostream& operator<<(std::ostream& out, const Menu& menu);


	//Public methods-------------------------------------------------------------
	void setCommandsCount(size_t count) { commands.resize(count); }
	size_t getCommandsCount() { return commands.getSize(); }
	void printInPosition(int x, int y);
	int getSelected() { return selected; }
	void addCommand(std::string commandName) { commands.pushBack(commandName); }
	
	//Draws menu in (x, y) position and allows to select some clause
	void startSelection(int x, int y);

private:
	Array<std::string> commands;

	int selected;
	HANDLE hout;

	enum ConsoleColor
	{
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};

	void changeConsoleColors(ConsoleColor text, ConsoleColor background);
	void clear() { commands.clear(); }
};

