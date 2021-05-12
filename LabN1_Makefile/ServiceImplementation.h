#include <stdio.h>
#include <string>

using namespace std;

class ServiceImplementation {
	
	public:
		ServiceImplementation(int _typeCode, int _modelCode, string _description, int _breakingType);
		~ServiceImplementation();
		void repair();
		
		void setPrice(int s);
		int getPrice();
	
	private:
		string description;
		int typeCode;
		int modelCode;
		int breakingType;
		int sparePart;
		int firstSparePartCode;
		int secondSparePartCode;
		int thirdSparePartCode;
		int price;
		int simpleFix();
		int smallFix();
		int mediumFix();
		int largeFix();
		int uniqueFix();
};