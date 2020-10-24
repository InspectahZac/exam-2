#include <iostream>
//#include "vehicle.hpp"
#include "tank.hpp"

int main() {
	Vehicle v1;
	v1.change_model("Small car");
	std::cout << v1 << '\n';
	v1.drive();
	v1.drive();
	v1.fill_gas();
	v1.drive();

	Tank t1;
	t1.change_model("M4 Sherman");
	t1.add_missile(20);
	t1.fire_missiles();
	std::cout << t1 << '\n';
	t1.add_missile(10);
	t1.fire_missiles(5);
	std::cout << t1 << '\n';

	return 0;
}
