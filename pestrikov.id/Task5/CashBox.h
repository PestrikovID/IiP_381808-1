#pragma once
#include "Array.h"
#include "Stock.h"
#include <iostream>
#include "Check.h"
#include "BarCode.h"

class CashBox
{
public:
	CashBox(const Stock& stock);
	
	void scanProduct(BarCode barCode);	
	int getFinalTotalCost() { return mCheck.calculateFinalTotalCost(); }
	Check getCheck() { return mCheck; }

private:
	Check mCheck;
	Stock mStock;
};


CashBox::CashBox(const Stock& stock) : mStock(stock) {
	/* do nothing */
}

void CashBox::scanProduct(BarCode barCode) {
	mCheck.addProduct(*mStock.getProductByBarCode(barCode));
}





