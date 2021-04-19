#pragma once
#include "patient.h"

#include <vector>


class Hospital
{
	
	private:
		// Attributes
		int beds_ = 0;
		std::vector<Patient> patients_;

	public:

		static int total_patients_handeled;
	
		// Constructor
		Hospital();
	
		// Destructor
		~Hospital()
		= default;

		// TODO CONST CORR
		// Get Methods
		int get_beds() const { return beds_; }
		// TODO Better suited -> O(log(n)) Laufzeit
		// std::map<int, Patient> -> int = id
		// std::set / unordered_set http://www.cplusplus.com/reference/set/set/
		std::vector<Patient> get_patients() const { return patients_; }

		// Set Methods
		void set_beds(int b) { beds_ = b; }

		// Methods
		int get_free_beds() const; // Function to calculate how many free beds / slots in vector are left
		void add_patient(Patient& p); // Function to fill the beds (vector) of the hospital object
		void print() const; // Print function to print patient data for each filled bed_ in vector from patient object
		void days_passed(const int days); // Function to pass days and update patients in hospital accordingly
		void erase_patient(const int id); // Erase a patient by id from vector
		void change_patient_diagnosis(int id, Diagnosis d);
		bool find_patient(Patient* p, int* id); // Check a patient pointer is in hospital
	
};
