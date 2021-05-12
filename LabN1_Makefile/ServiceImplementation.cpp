#include <stdio.h>
#include <string>
#include "ServiceImplementation.h"

using namespace std;

ServiceImplementation::ServiceImplementation(int _typeCode, int _modelCode, string _description, int _breakingType) {
	typeCode = _typeCode;
	modelCode = _modelCode;
	description = _description;
	breakingType = _breakingType;
};

ServiceImplementation::~ServiceImplementation() {
	
}

// Setter
void ServiceImplementation::setPrice(int s) {
	price = s;
}

// Getter
int ServiceImplementation::getPrice() {
	return price;
}

void ServiceImplementation::repair() {
	if (this->breakingType == 0) {
		this->price = simpleFix();
	} else if (this->breakingType == 1) { // Small break
		this->price = smallFix();
	} else if (this->breakingType == 2) { // Medium break
		this->price = mediumFix();
	} else if (this->breakingType == 3) { // Large break
		this->price = largeFix();
	} else {
		this->price = uniqueFix();
	}
	printf("You need to pay: %d dollars\n\n", this->price);
}

int ServiceImplementation::simpleFix() {
	printf("Nothing to fix\n");
	return 0;
}

int ServiceImplementation::smallFix() {
	printf("We've made some minor changes\n");
	return 100;
}

int ServiceImplementation::mediumFix() {
	printf("To fix you need to buy new processor\n");
	return 1000;
}

int ServiceImplementation::largeFix() {
	printf("We cannot fix your device. You must buy new one!\n");
	return 5000;
}

int ServiceImplementation::uniqueFix() {
	printf("We can't identify any breaks. Nothing to fix.\n");
	return simpleFix();
}