#pragma once
#include "patient.h"

#include <vector>


class Hospital
{
	private:
		// Attributes
		int total_patients_handeled_ = 1;
		int beds_ = 0;
		std::vector<Patient> patients_;

	public:
	
		// Constructor
		Hospital();
	
		// Destructor
		~Hospital()
		= default;
	
		// Get Methods
		int get_beds() const { return beds_; }
		std::vector<Patient> get_patients() const { return patients_; }

		// Set Methods
		void set_beds(int b) { beds_ = b; }
		void set_patients_handeled(int p) { total_patients_handeled_ = p; }

		// Methods
		int get_free_beds() const; // Function to calculate how many free beds / slots in vector are left
		void add_patient(Patient& p); // Function to fill the beds (vector) of the hospital object
		void print(); // Print function to print patient data for each filled bed_ in vector from patient object
		void days_passed(int days); // Function to pass days and update patients in hospital accordingly
		void erase_patient(const int id); // Erase a patient by id from vector
		void change_patient_diagnosis(int id, Diagnosis d);
		bool find_patient(Patient* p, int* id); // Check a patient pointer is in hospital
};
