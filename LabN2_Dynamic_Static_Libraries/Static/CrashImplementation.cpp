#include <iostream>
#include <string>

#include "Crash.h"

using namespace std;

namespace Records {
	
	Crash::Crash() {};
	
	Crash::Crash(int _modelCode, string _description, int _breakingType) {
		modelCode = _modelCode;
		description = _description;
		breakingType = _breakingType;
		price = 0;
		firstPartCode = secondPartCode = thirdPartCode = 0;
		makeRepair();
	};
	
	Crash::~Crash() {};
	
	void Crash::printRepairMethod() {
		cout << repairMethod << endl;
	}
	
	void Crash::print() {
		printf("+-----------------------------------------\n");
		printf("| Crash Model Code: %d\n", modelCode);
		cout<< "| Crash Description: " << description << "\n";
		cout<< "| Crash Method: " << repairMethod << "\n";
		printf("+-----------------------------------------\n");
		printf("\n");
	}
	
	void Crash::makeRepair() {
		if (breakingType == 1) {
			repair();
		} else {
			fix();
		}
	}
	
	void Crash::repair() {
		this->repairMethod = FIX_METHOD;
		this->price = 5000;
	}
	
	void Crash::fix() {
		this->repairMethod = REPAIR_METHOD;
		this->price = 1000;
	}
	
	Crash* Crash::makeArray(int length) {
		return new Crash[length];
	}
	
	int Crash::getPrice() {
		return price;
	}
	
	void Crash::setPrice(int price) {
		this->price = price;
	}
	
	int Crash::getBreakingType() {
		return breakingType;
	}
	
	void Crash::setBreakingType(int breakingType) {
		this->breakingType = breakingType;
	}
	
	int Crash::getModelCode() {
		return modelCode;
	}
	
	void Crash::setModelCode(int modelCode) {
		this->modelCode = modelCode;
	}
	
	string Crash::getDescription() {
		return description;
	}
	
	void Crash::setDescription(string description) {
		this->description = description;
	}
	
	int Crash::getFirstPartCode() {
		return firstPartCode;
	}
	
	void Crash::setFirstPartCode(int firstPartCode) {
		this->firstPartCode = firstPartCode;
	}
	
	int Crash::getSecondPartCode() {
		return secondPartCode;
	}
	
	void Crash::setSecondPartCode(int secondPartCode) {
		this->secondPartCode = secondPartCode;
	}
	
	int Crash::getThirdPartCode() {
		return thirdPartCode;
	}

	void Crash::setThirdPartCode(int thirdPartCode) {
		this->thirdPartCode = thirdPartCode;
	}
	
	string Crash::getRepairMethod() {
		return repairMethod;
	}
	
	void Crash::setRepairMethod(string repairMethod) {
		this->repairMethod = repairMethod;
	}
	
}
