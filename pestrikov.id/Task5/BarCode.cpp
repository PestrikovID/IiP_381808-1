#include "BarCode.h"

const std::string BarCode::DEFAULT_BAR_CODE_VALUE = "0000";

BarCode::BarCode(std::string value) {
	if (!isValueCorrect(value)) {
		throw std::exception("Bar code value is incorrect");
	}
	mValue = value;
}

bool BarCode::isValueCorrect(std::string value) {
	if (value.size() != BAR_CODE_LENGTH) {
		return false;
	}
	for (int i = 0; i < value.size(); ++i) {
		if (value[i] < '0' || value[i] > '9') {
			return false;
		}
	}
	return true;
}

BarCode& BarCode::operator=(const BarCode& other) {
	if (*this == other) {
		return *this;
	}
	mValue = other.mValue;
	return *this;
}

