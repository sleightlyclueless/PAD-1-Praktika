#include "hospital.h"

#include<iostream>

// Constructor
Hospital::Hospital()
= default;


// Function to calculate how many free beds / slots in vector are left
int Hospital::get_free_beds() const
{
	// Calculate and return defined beds_ size - already filled slots (size) of patients_ vector
	const int free_beds = beds_ - patients_.size();
	return free_beds;
}

// Function to fill the beds (vector) of the hospital object
void Hospital::add_patient(Patient & p)
{
	// If no calculated space in vector for defined beds_ size left throw error
	if (get_free_beds() == 0)
	{
		std::cout << "Hospital full!" << std::endl;
		p.~Patient();
		return;
	}

	// If space left add patient
	patients_.push_back(p);
	set_patients_handeled(total_patients_handeled_ + 1);
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
void Hospital::days_passed(int days)
{
	int cured_patients = 0;
	// Iterate through each bed / patient object of vector
	for (size_t i=0; i < patients_.size(); i++)
	{
		// Get current patient object per adress
		Patient& p = patients_.at(i);
		
		// Get patients remaining timetocure and reduce it by passed days
		const int currtimetocure = p.get_time_to_cure();
		// If we reach 0 days left to cure update object to cured and remove from beds
		if (currtimetocure - days <= 0)
		{
			p.set_time_to_cure(0);
			p.set_diagnosis(cured);
			patients_.erase(patients_.begin() + i);
			cured_patients++;

			// If we removed an element from vector we have to reduce the counter again
			// Cause all other elements jump back in vector
			i--;
		}
		// If patient not cured just update remaining cure time
		else
		{
			p.set_time_to_cure(currtimetocure - days);
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
