#include "main.h"

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int patientfoundid;

	Hospital h;
	
	h.set_beds(60);
	h.initialize(5);
	h.print();
	std::cout << "===========================" << std::endl;
	std::cout << "ADD PATIENTS" << std::endl;
	std::cout << "===========================" << std::endl;
	h.add_patients(5);
	h.print();
	std::cout << "===========================" << std::endl;
	std::cout << "TIME PASSED" << std::endl;
	std::cout << "===========================" << std::endl;
	h.time_passed(20);
	h.print();
	std::cout << "===========================" << std::endl;
	std::cout << "ADD PATIENTS AGAIN" << std::endl;
	std::cout << "===========================" << std::endl;
	h.add_patients(5);
	h.print();
	std::cout << "===========================" << std::endl;
	std::cout << "ERASE PATIENTS" << std::endl;
	std::cout << "===========================" << std::endl;
	h.erase_patient(100069);
	h.erase_patient(100002);
	h.print();
	
	Patient p = new_patient();
	const bool foundpatient = h.find_patient(&p, &patientfoundid);
	std::cout << "Patient with id " << patientfoundid << " " << foundpatient << std::endl;
	
    return 0;
}
