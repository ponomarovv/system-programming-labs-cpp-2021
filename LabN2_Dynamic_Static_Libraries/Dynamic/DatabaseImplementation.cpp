#include <iostream>
#include <stdio.h>
#include <string>

#include "Database.h"

using namespace std;

namespace Records {
	
	Database::Database() {
		recordsCount = 0;
		data = readAll();
	}
	
	Database::~Database() {
		delete[] data;
	}
	
	bool Database::addCrash(Crash &crash) {
		FILE *out;
		out = fopen("database/data.txt", "a");
		data[recordsCount] = crash;
		recordsCount++;
		fprintf(
			out,
			"%d | %d | %d | %d | %d | %d | %d | %s | %s\n",
			recordsCount,
			crash.getBreakingType(),
			crash.getModelCode(),
			crash.getFirstPartCode(),
			crash.getSecondPartCode(),
			crash.getThirdPartCode(),
			crash.getPrice(),
			crash.getRepairMethod().c_str(),
			crash.getDescription().c_str()
		);
		
		fclose(out);
		return true;
	}
	
	Crash Database::getByCode(int code) {
		return data[code - 1];
	}
	
	Crash* Database::readAll() {
		Crash *data = Crash::makeArray(maxCrashes);
		
		FILE *in;
		in = fopen("database/data.txt", "r");
		int code, breakingType, modelCode, firstPartCode, secondPartCode, thirdPartCode, price;
		char repairMethod[256];
		char description[256];
		recordsCount = 0;
		while (!feof(in)) {
			code = 0;
			
			fscanf(
				in,
				"%d | %d | %d | %d | %d | %d | %d | %[^|]| %[^\n]s",
				&code, &breakingType, &modelCode, &firstPartCode, &secondPartCode, &thirdPartCode, &price, repairMethod, description
			);
			
			if (code == 0) {
				continue;
			}
			
			string sRepairMethod = repairMethod;
			string sDescription = description;
			
			Crash crash = Crash(modelCode, description, breakingType);
			crash.setFirstPartCode(firstPartCode);
			crash.setSecondPartCode(secondPartCode);
			crash.setThirdPartCode(thirdPartCode);
			crash.setPrice(price);
			crash.setRepairMethod(sRepairMethod);
			crash.setDescription(sDescription);
			
			data[recordsCount] = crash;
			
			recordsCount++;
		}
		fclose(in);
		
		return data;
	}
	
	void Database::displayAllFromDatabase() {
		for (int i = 0; i < recordsCount; i++) {
			printCrash(i + 1);
		}
	}
	
	void Database::displayByCode(int code) {
		printCrash(code);
	}
	
	void Database::printCrash(int code) {
		printf("\n");
		printf("Crash code: %d\n", code);
		Crash crash = data[code - 1];
		crash.print();
	}
	
}
