GPP=g++ -std=c++17

all: Vehicle.o main.o
	$(GPP) Vehicle.o main.o -o drive_time	

Vehicle.o: Vehicle.cpp vehicle.hpp
	$(GPP) -c Vehicle.cpp

main.o: main.cpp vehicle.hpp tank.hpp
	$(GPP) -c main.cpp

clean:
	rm *.o
	rm drive_time
