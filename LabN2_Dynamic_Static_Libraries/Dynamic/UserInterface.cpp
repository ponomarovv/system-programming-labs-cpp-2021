#include <iostream>
#include <stdexcept>
#include <string>

#include "Database.h"

using namespace std;
using namespace Records;

void displayGreeting();
void displayMenu();
Crash getCrashFromUser();
bool userWantToAddCrashToDatabase();
void addCrashToDatabase(Database &database, Crash &crash);
int getCodeFromUser();

int main(int argc, char** argv) {
	
	Database database = Database();
	
	displayGreeting();
	displayMenu();
	
	int option = getCodeFromUser();
	
	while (option != 0) {
		switch (option) {
			case 1: {
				Crash crash = getCrashFromUser();
				if (userWantToAddCrashToDatabase()) {
					addCrashToDatabase(database, crash);
				}
				break;
			}
			case 2: {
				database.displayAllFromDatabase();
				break;
			}
			case 3: {
				int code = getCodeFromUser();
				database.displayByCode(code);
				break;
			}
			case 4: {
				int code = getCodeFromUser();
				Crash crash = database.getByCode(code);
				printf("Crash price: %d\n", crash.getPrice());
				break;
			}
			case 0: {
				break;
			}
		}
		displayMenu();
		option = getCodeFromUser();
	}
	
	return 0;
}

void displayGreeting() {
	printf("Welcome to the best Crash Database ever!!!\n");
}

void displayMenu() {
	printf("*******************MENU*******************\n");
	printf("-----------(Choose one option)------------\n");
	printf("1 - Create crash\n");
	printf("2 - Display all crashes from database\n");
	printf("3 - Get crash by code\n");
	printf("4 - Get crash price by crash code\n");
	printf("0 - Quit\n");
}

Crash getCrashFromUser() {
	int modelCode;
	string description;
	int breakingType;
	
	printf("Type your's model code: ");
	scanf("%d", &modelCode);
	
	cout << "Type decription: ";
	cin.clear();
	cin.sync();
	cin.ignore(256, '\n');
	getline(cin, description);
	
	printf("Breaking type: ");
	scanf("%d", &breakingType);
	
	return Crash(modelCode, description, breakingType);
}

bool userWantToAddCrashToDatabase() {
	printf("Do you want to add this crash to database?(1 - Yes, 2 - No): ");
	int option;
	scanf("%d", &option);
	return option == 1;
}

void addCrashToDatabase(Database &database, Crash &crash) {
	database.addCrash(crash);
}

int getCodeFromUser() {
	int code;
	printf("Type number: ");
	scanf("%d", &code);
	return code;
}


