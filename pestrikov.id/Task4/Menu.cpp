#include "Menu.h"

Menu::Menu() {
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	selected = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

Menu::Menu(int count) : Menu() {
	commands.resize(count);
}

void Menu::printInPosition(int x, int y) {
	for (size_t i = 0; i < commands.getSize(); ++i) {
		SetConsoleCursorPosition(hout, {(SHORT)x, (SHORT)(y + i)});
		if (i == selected) {
			changeConsoleColors(LightGray, LightGreen);
			std::cout << commands[i] << std::endl;
			changeConsoleColors(LightGray, Black);
			continue;
		}
		std::cout << commands[i] << std::endl;
	}
}



void Menu::startSelection(int x, int y, Contacts& contacts) {
	printInPosition(x, y);

	while (true) {
		//_getch returns 2 values, key get the first one (useless)
		int key = _getch();

		//Enter is pressed
		if (key == 13) {
			system("cls");
			commands_methods[selected](contacts);
			std::cout << std::endl << "Нажмите escape, чтобы вернуться в главное меню";
			while (_getch() != 27) {
				// do nothing
			}
			system("cls");
			printInPosition(x, y);
			continue;
		}
		switch (_getch()) {

			//Up key is pressed
		case 72:
			--selected;
			if (selected < 0) {
				selected = commands.getSize() - 1;
			}
			printInPosition(x, y);
			break;

			//Down key is pressed
		case 80:
			++selected;
			if (selected == commands.getSize()) {
				selected = 0;
			}
			printInPosition(x, y);
			break;
		}

	}
}


void Menu::changeConsoleColors(ConsoleColor text, ConsoleColor background) {
	HANDLE hConslole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConslole, (WORD)(background << 4 | text));
}

std::istream & operator>>(std::istream & in, Menu & menu) {
	menu.clear();
	//input format:
	//size
	//commandSize1 commandName1
	//commandSize2 commandName2
	//....
	//commandSizeN commandNameN
	//-----------------------------------------------------------------------------
	//IMPORTATNT: on each line must be only one construction (commandSize commandName)
	//ELSE IT WON'T WORK CORRECT
	//-----------------------------------------------------------------------------
	size_t size;
	in >> size;
	menu.commands.resize(size);

	for (int i = 0; i < menu.commands.getSize(); ++i) {
		int commandSize;
		in >> commandSize;
		char commandName[1000];
		in.getline(commandName, commandSize + 2);
		menu.commands[i] = commandName;
		menu.commands[i].erase(menu.commands[i].begin());
	}

	return in;
}

std::ostream & operator<<(std::ostream & out, const Menu & menu) {
	//output format:
	//size
	//commandSize1 commandName1
	//commandSize2 commandName2
	//....
	//commandSizeN commandNameN
	out << menu.commands.getSize() << std::endl;

	for (int i = 0; i < menu.commands.getSize(); ++i) {
		out << menu.commands[i].size() << " " << menu.commands[i] << std::endl;
	}

	return out;
}
