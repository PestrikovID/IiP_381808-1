#include <iostream>
#include "Array.h"
#include "Menu.h"
#include <conio.h>
#include <fstream>
#include <vector>

int main()
{
	

	Menu menu;
	menu.addCommand("Bubble sort");
	menu.addCommand("Merge sort");
	menu.addCommand("Quick sort");
	menu.addCommand("Insertion sort");
	menu.addCommand("Heap sort");
	menu.addCommand("Selection sort");
	
	//Input and output in file test
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	in >> menu;
	out << menu;

	while (true) {
		menu.startSelection(0, 0);
		std::cout << "Selected clause is " << menu.getSelected() << std::endl;
	}

	//system("pause");
	return 0;
}