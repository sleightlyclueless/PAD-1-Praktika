#include "hospital.h"
#include <iostream>



int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	Hospital h;
	
	h.set_beds(60);
	h.initialize(55);
	h.add_patients(5);
	h.print();
	std::cout << "===========================" << std::endl;
	std::cout << "===========================" << std::endl;
	h.time_passed(20);
	std::cout << "===========================" << std::endl;
	std::cout << "===========================" << std::endl;
	h.print();
	h.add_patients(5);
	std::cout << "===========================" << std::endl;
	std::cout << "===========================" << std::endl;
	h.print();


	/*Patient p = new_patient(global_id);
	global_id++;
	p.print();
	std::cout << std::endl << "================" << std::endl;
	p.reduce_time_to_cure(5);
	p.print();
	std::cout << std::endl << "================" << std::endl;
	p.change_diagnosis(fracture);
	p.print();*/

    return 0;
}






