аll: ServiceCentre

ServiceCentre: Service.o ServiceImplementation.o
	g++ Service.o ServiceImplementation.o -o Service

Service.o: Service.cpp
	g++ -c Service.cpp

ServiceImplementation.o: ServiceImplementation.cpp ServiceImplementation.h
	g++ -Wall -c ServiceImplementation.cpp

clean: 
		rm -rf *.o ServiceCentre