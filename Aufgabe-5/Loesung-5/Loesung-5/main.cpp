#include "main.h"

#include <iostream>

int main()
{
	setlocale(LC_ALL, ""); // Enable utf-8 output in console
	srand(time(nullptr));  // NOLINT(clang-diagnostic-shorten-64-to-32, cert-msc51-cpp)
	int patientfoundid; // Global patientid integer if we search and output one
	bool foundpatient = false; // Global bool value if we searched for a patient

	// Create hospital object
	Hospital h;

	// Set hospital bedsize to 60 and initialize it with 61
	std::cout << "===============================================================" << std::endl << std::endl;
	std::cout << "INITIALIZE HOSPITAL OBJECT" << std::endl;
	h.set_beds(60);
	for (int i=0; i<h.get_beds() + 1; i++)
	{
		Patient p = new_patient();
		h.add_patient(p);
	}
	h.print();
	
	// Let some time pass to treat some patients
	std::cout << "===============================================================" << std::endl << std::endl;
	std::cout << "TIME PASSED" << std::endl;
	h.days_passed(20);
	h.print();

	// Add 5 more patients
	std::cout << "===============================================================" << std::endl << std::endl;
	std::cout << "ADD PATIENTS AGAIN" << std::endl;
	for (int i = 0; i <=5; i++)
	{
		Patient p = new_patient();
		h.add_patient(p);
	}
	h.print();

	// Erase some patients by their id
	std::cout << "===============================================================" << std::endl << std::endl;
	std::cout << "ERASE PATIENTS" << std::endl;
	h.erase_patient(h.get_patients().at(5).get_id());
	h.erase_patient(1000051);
	h.print();

	// Change diagnosis for some patients
	std::cout << "===============================================================" << std::endl << std::endl;
	std::cout << "CHANGE PATIENT DIAGNOSES" << std::endl;
	h.change_patient_diagnosis(h.get_patients().at(1).get_id(), simulant);
	h.change_patient_diagnosis(h.get_patients().back().get_id(), fracture);
	h.print();


	// =Add manually created patient - not found=
	Date birthday = { 8, mai, 1998 };
	Patient pdef = Patient(male, "Sebastian", "Zill", birthday);
	foundpatient = h.find_patient(&pdef, &patientfoundid);
	if (!foundpatient)
	{
		h.add_patient(pdef);
	} else
	{
		std::cout << "Patient with id " << patientfoundid << " already in hospital!" << std::endl;
	}
	h.print();
	
	// =Add manually created patient - now found=
	foundpatient = h.find_patient(&pdef, &patientfoundid);
	if (!foundpatient)
	{
		h.add_patient(pdef);
		std::cout << "Patient with id " << patientfoundid << " already in hospital!" << std::endl;
	}
	else
	{
		std::cout << "Patient with id " << patientfoundid << " already in hospital!" << std::endl;
	}


	std::cout << std::endl << "Simulation over -" << Hospital::total_patients_handeled << "- Patients handeled!" << std::endl;
	
    return 0;
}
