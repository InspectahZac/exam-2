#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Tank {
	protected:
		int _treads;
		float _gas_level;
		int _missiles;
		std::string _model;
	
	public: //Unparam
		Tank() : _treads{2}, _gas_level{1.0}, _missiles{0}, _model{"Unknown"} {

		}

		//Param
		Tank(const int treads, const float init_gas, const int init_missles, const std::string model) : _treads{treads}, _gas_level{init_gas}, _missiles{init_missles}, _model{model} {

		}

		//Copy
		Tank(const Tank &t) :  _treads{t._treads}, _gas_level{t._gas_level}, _missiles{t._missiles}, _model{t._model} {

		}

		void change_treads(int new_treads) {
			if ((new_treads >= 0) && (new_treads <= 4)) {
				_treads = new_treads;
			}
			else {
				std::cout << "Too many treads (4 Max)!\n";
			}
		}

		void set_gas_level(float new_gas) {
			if((new_gas >= 0) && (new_gas <= 1.0)) {
				_gas_level = new_gas;
			}
		}

		void change_model(std::string new_model) {
			_model = new_model;
		}

		void add_missiles(int new_missiles) {
			if ((_missiles + new_missiles) <= 250) {
				_missiles = (_missiles + new_missiles);
			}
			else {
			std::cout << "Too many missiles (250 Max)!\n";
			}
		}

		int treads() const {
			return _treads;
		}

		float gas_level() const {
			return _gas_level;
		}

		int missiles() const {
			return _missiles;
		}

		void drive() {
			if(gas_level() == 0) {
				std::cout << "Cannot drive! Fuel is empty!\n";
			}

			srand(time(NULL) + rand());
			float gas_reduced = (float) rand() / (float) RAND_MAX;

			_gas_level -= gas_reduced;

			if(_gas_level < 0) {
				_gas_level = 0.0;
			}

			std::cout << "Gas level is " << gas_level() << '\n';
			
		}

		void fill_gas() {
			set_gas_level(1.0);
			std::cout << "Ready to roll!\n";
		}

		void fire_missiles() {
			if(missiles() == 0) {
				std::cout << "*click*... Not enough ammo.\n";
			}

			srand(time(NULL) + rand());
			int missiles_fired = rand() % missiles() + 1;

			_missiles -= missiles_fired;

			if(_missiles < 0) {
				_missiles = 0;
			}	
			

			for (missiles_fired>0; missiles_fired--;) {
				std::cout << "Blam!\n";
			}
			
			std::cout << "Missiles remaining: " << missiles() << '\n';
		
			}

		void fire_missiles(int amount) {
		 if (_missiles >= amount) {
			_missiles = _missiles - amount;
			for(amount>0; amount--;){
				std::cout << "Blam!\n";
			}
		 }
		 else {
			for(_missiles>0; _missiles--;) {
				std::cout << "Blam!\n";
			}
			for(int extra = amount - _missiles; extra>0; extra--) {
				std::cout << "*click*... Not enough ammo.";
			}

		 }
		}

		Tank operator=(const Tank &t) {
			_treads = t._treads;
			_gas_level = t._gas_level;
			_missiles = t._missiles;

			return *this;
		
		}

		friend std::ostream &operator<<(std::ostream &out, const Tank &t) {
			out << t._treads << " treads, " << t._missiles << " missiles, "<< "gas level: " << t._gas_level << '\n';

		return out;
		}

};
