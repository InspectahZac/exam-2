// Students should create a car and motorcycle class
#include <iostream>
#include <string>

class Vehicle {
	protected:
		int _wheels;
		float _gas_level;
		std::string _model;
	public:
		// Constructors
		Vehicle();
		Vehicle(const int wheels, const float init_gas, 
			const std::string model);
		Vehicle(const Vehicle &v);

		// Destructor
		virtual ~Vehicle();

		// Setters
		virtual void change_wheels(int new_wheels);
		virtual void set_gas_level(float new_gas);
		virtual void change_model(std::string new_model);

		// Getters
		int wheels() const;
		float gas_level() const;
		std::string model() const;

		// General Methods
		virtual void drive();
		virtual void fill_gas();

		// Overloading operators
		Vehicle &operator=(const Vehicle &v);

		friend std::ostream &operator<<(std::ostream &out, const Vehicle &v);
};
