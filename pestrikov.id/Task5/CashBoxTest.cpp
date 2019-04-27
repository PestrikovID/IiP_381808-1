#include "CashBox.h"
#include <iostream>
#include <fstream>
#include "Array.h"
#include <ctime>

int main() {
	
	Stock stock;
	stock.addProduct(BarCode("0001"), "Product 1", 843, 2);
	stock.addProduct(BarCode("0002"), "Product 2", 823, 99);
	stock.addProduct(BarCode("0003"), "Product 3", 143, 26);
	stock.addProduct(BarCode("0004"), "Product 4", 6643, 42);
	stock.addProduct(BarCode("0005"), "Product 5", 813, 1);
	Array<BarCode> barCodes = {BarCode("0001"), BarCode("0002"), BarCode("0003"), BarCode("0004"), BarCode("0005")};
	
	CashBox cashBox(stock);
	srand(time(0));
	for (int i = 0; i < 15; ++i) {
		cashBox.scanProduct(barCodes[rand() % barCodes.getSize()]);
	}

	Check check = cashBox.getCheck();
	std::cout << check.getDescription();

	return 0;
}


