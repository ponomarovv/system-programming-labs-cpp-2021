#include "ServiceImplementation.h"
#include <stdio.h>
#include <iostream>

int main(void) {

	

	ServiceImplementation ssi1 = ServiceImplementation(1, 2, "Some description", 1);
	ssi1.repair();
	ServiceImplementation ssi2 = ServiceImplementation(2, 3, "Another description", 2);
	ssi2.repair();
	ServiceImplementation ssi3 = ServiceImplementation(3, 4, "No description", 3);
	ssi3.repair();
	ServiceImplementation ssi4 = ServiceImplementation(4, 5, "Without description", 4);
	ssi4.repair();
	ServiceImplementation ssi5 = ServiceImplementation(5, 6, "CAPS DESCRIPTION", 5);
	ssi5.repair();
	
	printf("\n");
	
	ServiceImplementation *hsi1 = new ServiceImplementation(1, 2, "Some description", 1);
	hsi1->repair();
	delete hsi1;
	ServiceImplementation *hsi2 = new ServiceImplementation(2, 3, "Another description", 2);
	hsi2->repair();
	delete hsi2;
	ServiceImplementation *hsi3 = new ServiceImplementation(3, 4, "No description", 3);
	hsi3->repair();
	delete hsi3;
	ServiceImplementation *hsi4 = new ServiceImplementation(4, 5, "Without description", 4);
	hsi4->repair();
	delete hsi4;
	ServiceImplementation *hsi5 = new ServiceImplementation(5, 6, "CAPS DESCRIPTION", 5);
	hsi5->repair();
	delete hsi5;
	
	printf("\n");
	ssi1.setPrice(100);
	
	int n = ssi1.getPrice();
	std::cout << n << "\n" << std::endl;
}