#include <iostream>
#include <string>

using namespace std;

namespace Records {
	const string FIX_METHOD = "fix";
	const string REPAIR_METHOD = "repair";
	
	class Crash {
		public:
			Crash(int _modelCode, string _description, int _breakingType);
			~Crash();
			
			void printRepairMethod();
			void repair();
			void fix();
			static Crash* makeArray(int length);
			
			int getPrice();
			void setPrice(int price);
			
			int getBreakingType();
			void setBreakingType(int breakingType);
			
			int getModelCode();
			void setModelCode(int modelCode);
			string getDescription();
			void setDescription(string description);
			int getFirstPartCode();
			void setFirstPartCode(int firstPartCode);
			int getSecondPartCode();
			void setSecondPartCode(int secondPartCode);
			int getThirdPartCode();
			void setThirdPartCode(int thirdPartCode);
			string getRepairMethod();
			void setRepairMethod(string repairMethod);
			void print();
		
		private:
			Crash();
			static int counter;
			int code;
			int breakingType;
			int price;
			int modelCode;
			string description;
			int firstPartCode;
			int secondPartCode;
			int thirdPartCode;
			string repairMethod;
			
			void makeRepair();
	};
}
