аll: CrashCenter

CrashCenter: UserInterface.o crashlib.a
	g++ UserInterface.o CrashImplementation.o DatabaseImplementation.o -o UserInterface

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

crashlib.a: CrashImplementation.o DatabaseImplementation.o
	ar cr crashlib.a CrashImplementation.o DatabaseImplementation.o

CrashImplementatition.o: CrashImplementatition.cpp Crash.h
	g++ -c CrashImplementatition.cpp

DatabaseImplementation.o: DatabaseImplementation.cpp Database.h
	g++ -c DatabaseImplementation.cpp


clean: 
		rm -rf *.o CrashCenter