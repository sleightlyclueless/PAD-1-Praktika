#include "hospital.h"

#include<iostream>

int Hospital::total_patients_handeled = 1;

// Constructor
Hospital::Hospital()
= default;


// Function to calculate how many free beds / slots in vector are left
int Hospital::get_free_beds() const
{
	// Calculate and return defined beds_ size - already filled slots (size) of patients_ vector
	return beds_ - patients_.size();
}

// Function to fill the beds (vector) of the hospital object
void Hospital::add_patient(Patient & p)
{
	// If no calculated space in vector for defined beds_ size left throw error
	if (get_free_beds() <= 0)
	{
		std::cout << "Hospital full!" << std::endl;
		p.~Patient();
		return;
	}

	// If space left add patient
	patients_.push_back(p);
	total_patients_handeled++;
}

// Print function to print patient data for each filled bed_ in vector from patient object
void Hospital::print()
{
	for (Patient &p : patients_)
	{
		p.print_patient_data();
	}
}

// Function to pass days and update patients in hospital accordingly
void Hospital::days_passed(const int days)
{
	int cured_patients = 0;
	// Iterate through each bed / patient object of vector
	for (size_t i=0; i < patients_.size(); i++)
	{
		// Get current patient object per adress
		Patient& p = patients_.at(i);
		
		// If we reach 0 days left to cure update object to cured and remove from beds
		// else evetything is set and we are done with the patient
		if (p.reduce_time_to_cure(days) == 0)
		{
			patients_.erase(patients_.begin() + i);
			cured_patients++;

			// If we removed an element from vector we have to reduce the counter again
			// Cause all other elements jump back in vector
			i--;
		}
	}

	std::cout << days << " passed.";
	if (cured_patients > 0)
	{
		std::cout << " " << cured_patients << " cured!" << std::endl;
	}

}

// Erase a patient by id from vector
void Hospital::erase_patient(const int id)
{
	// Iterate through patient objects in vector and look if id matches id to be deleted
	int counter = 0;
	bool found = false;
	for (Patient& p: patients_)
	{
		// If an id matches erase that patient
		if(p.get_id() == id)
		{
			patients_.erase(patients_.begin() + counter);
			found = true;
			std::cout << "Patient with ID " << id << " erased!" << std::endl;
			return;
		}
		counter++;
	}

	if (!found)
	{
		std::cout << "No patient with ID " << id << " in database!" << std::endl;
	}
}

void Hospital::change_patient_diagnosis(const int id, const Diagnosis d)
{
	for (Patient& p : patients_)
	{
		if (id == p.get_id())
		{
			p.set_diagnosis(d);
			p.set_time_to_cure(p.calc_time_to_cure());
		}
	}
}

// Check a patient pointer is in hospital
// Return according boolean and patient id
bool Hospital::find_patient(Patient* p, int* id)
{
	for (Patient currp : patients_)
	{
		if (Patient::compare_patients(&currp, p) == true)
		{
			*id = currp.get_id();
			return true;
		}
	}
	*id = -1;
	return false;
}
