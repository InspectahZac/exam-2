#include <iostream>
#include <cstdlib>		// rand(), srand()
#include <ctime>		// time()
#include "vehicle.hpp"

Vehicle::Vehicle() : _wheels{4}, _gas_level{1.0}, _model{"Unkown"} {

}

Vehicle::Vehicle(const int wheels, const float init_gas, 
		const std::string model) :
			_wheels{4}, _gas_level{1.0}, _model{"Unkown"} {
	change_wheels(wheels);
	set_gas_level(init_gas);
	change_model(model);
}

Vehicle::Vehicle(const Vehicle &v) : _wheels{v._wheels},
		_gas_level{v._gas_level}, _model{v._model} {

}

Vehicle::~Vehicle() { }

// Cannot have negative vehicle and the vehicle class can repersent an 18-wheeler
void Vehicle::change_wheels(int new_wheels) {
	if ((new_wheels > 0) && (new_wheels < 19)) {
		_wheels = new_wheels;
	}
}

// Gas is represented as a percentage. It is between 0 and 1.
void Vehicle::set_gas_level(float new_gas) {
	if ((new_gas > -1) && (new_gas <= 1.0)) {
		_gas_level = new_gas;
	}
}

void Vehicle::change_model(std::string new_model) {
	_model = new_model;
}

int Vehicle::wheels() const {
	return _wheels;
}

float Vehicle::gas_level() const {
	return _gas_level;
}

// Drive in a nutshell lowers gas level by a random number between 0 and 1.
// It generates a random number between 0 and 1 for gas_reduced, then subtracts it from the gas_level attribute.
// If it turns out that our gas level is negative, we set the gas level to zero.
void Vehicle::drive() {
	if (gas_level() == 0) {
		std::cout << "Cannot drive! Fuel is empty!\n";
	}

	// This line below creates a random seed (adds more randomness to generating random numbers)
	srand(time(NULL) + rand());
	float gas_reduced = (float) rand() / (float) RAND_MAX;

	_gas_level -= gas_reduced;

	if (_gas_level < 0) {
		_gas_level = 0.0;
	}
	std::cout << "Gas level is " << gas_level() << '\n';
}

void Vehicle::fill_gas() {
	set_gas_level(1.0);
	std::cout << "Gas is full!\n";
}

Vehicle &Vehicle::operator=(const Vehicle &v) {
	_wheels = v._wheels;
	_gas_level = v._gas_level;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Vehicle &v) {
	out << v._wheels << " wheels, " << "gas level: ";
	out << v._gas_level << '\n';
	return out;
}
