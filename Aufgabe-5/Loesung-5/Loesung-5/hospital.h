#pragma once
#include <vector>
#include <iostream>

#include "patient.h"
#include "main.h"

class Hospital
{
	private:
		int patients_handeled_ = 1;
		int beds_ = 60;
		std::vector<Patient> patients_;

	public:

		Hospital();

		~Hospital()
		= default;
	
		// Get Methods
		int get_beds() const { return beds_; }
		int get_patients_handeled() const { return patients_handeled_; }
		std::vector<Patient> get_patients() const { return patients_; }

		// Set Methods
		void set_beds(int b) { beds_ = b; }
		void set_patients_handeled(int p) { patients_handeled_ = p; }

		// Methods
		void print();
		int get_free_beds() const;
		void initialize(int fillbeds);
		void add_patients(int p);
		void time_passed(int days);
		void erase_patient(int id);
		bool find_patient(Patient* p, int* id);
};
