#include "Stock.h"

Product* Stock::getProductByBarCode(BarCode barCode) {
	for (int i = 0; i < mProducts.getSize(); ++i) {
		if (mProducts[i].getBarCode() == barCode) {
			return &mProducts[i];
		}
	}
	return nullptr;
}