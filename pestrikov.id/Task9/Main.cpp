#include <iostream>
#include "Triangle.h"

using namespace std;

int main()
{
	Triangle tr(3, 4, 5);

	if (tr.Is_exist())
	{
		cout << "Triangle exists" << endl
			<< "Perimeter = " << tr.Perimeter() << endl
			<< "Area = " << tr.Area() << endl;
		
	}
	else
	{
		cout << "Triangle does not exist";
	}

	system("pause");
	return 0;
}