UserInterface: UserInterface.o libdatabase.so
	g++ -L./ -Wall -o UserInterface UserInterface.o -ldatabase -Wl,-rpath,.

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

libdatabase.so: CrashImplementation.o DatabaseImplementation.o
	gcc -shared CrashImplementation.o DatabaseImplementation.o -o libdatabase.so

CrashImplementation.o: CrashImplementation.cpp
	g++ -fPIC -c CrashImplementation.cpp
	
DatabaseImplementation.o: DatabaseImplementation.cpp
	g++ -fPIC -c DatabaseImplementation.cpp

clean:
	rm -f *.o *.so binary