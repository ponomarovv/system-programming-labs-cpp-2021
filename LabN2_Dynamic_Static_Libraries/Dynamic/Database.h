#include <iostream>
#include <map>

#include "Crash.h"

using namespace std;

namespace Records {
	const int maxCrashes = 1000000;
	
	class Database {
		
		public:
			Database();
			~Database();
			bool addCrash(Crash &crash);
			Crash getByCode(int code);
			void displayAllFromDatabase();
			void displayByCode(int code);
			
		private:
			Crash* readAll();
			void printCrash(int code);
			
		protected:
			int recordsCount;
			Crash* data;
		
	};
	
}
