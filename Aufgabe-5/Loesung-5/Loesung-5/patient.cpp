#include "patient.h"

#include <iostream>

// Initialize global static id to six digits
int Patient::global_id = 100000;

// Constructor implementation - expects valid patient data, cant be empty
Patient::Patient(const Gender gender, const std::string firstname, const std::string lastname, const Date birthdate, const Diagnosis diagnosis)
    :gender_(gender), firstname_(firstname), lastname_(lastname), birthdate_(birthdate), diagnosis_(diagnosis)
{
    id_ = ++global_id;

    // Depending on diagnosis set the remaining timetocure during construction
    timetocure_ = calc_time_to_cure();
}

// Constructor implementation - expects valid patient data, cant be empty
Patient::Patient(const Gender gender, const std::string firstname, const std::string lastname, const Date birthdate)
						:gender_(gender), firstname_(firstname), lastname_(lastname), birthdate_(birthdate)
{
    id_ = ++global_id;
    diagnosis_ = simulant;

	// Depending on diagnosis set the remaining timetocure during construction
    timetocure_ = calc_time_to_cure();
}


// Print patient data
void Patient::print_patient_data() const
{
	// Build a string for the day with english endings
    std::string day_str = std::to_string(birthdate_.day);
    if (birthdate_.day < 10)
    {

        if (birthdate_.day == 1)
        {
            day_str = day_str + "st";
        }
        else if (birthdate_.day == 2)
        {
            day_str = day_str + "nd";
        }
        else if (birthdate_.day == 3)
        {
            day_str = day_str + "rd";
        }

    }
    else
    {
        day_str = day_str + "th";
    }

	// Print patient data into console. Output of enums is handeled by ostream in header
    std::cout << "Status for Patient Number: " << id_ << std::endl
    << "Firstname: " << firstname_ << std::endl
    << "Lastname: " << lastname_ << std::endl
    << "Gender: " << gender_ << std::endl
	<< "Birthday: " << day_str << " " << birthdate_.mon << " " << birthdate_.year << std::endl
	<< "Diagnosis: " << diagnosis_ << std::endl
	<< "Days till cure: " << timetocure_ << std::endl << std::endl
	<< "===========================" << std::endl;
}

int Patient::calc_time_to_cure() const
{
    switch (diagnosis_)
    {
    case infection:
        return 14;
    case fracture:
        return 42;
    case cured:
        return 0;
    case simulant:
        return 2;
    }
    return 0;
}


// Function to reduce the cure time. Used from hospital when a day passes
void Patient::reduce_time_to_cure(const int t)
{
	// Get remaining timetocure and reduce it by the passed var
    int timetocure = timetocure_;
    timetocure = timetocure - t;

	// If timetocure is below 1 the patient counts as cured - changes accordingly
	if (timetocure < 1)
	{
        set_diagnosis(cured);
        set_time_to_cure(0);
	} else
	{
        set_time_to_cure(timetocure);
	}
}

// Change diagnosis and reset timetocure accordingly again
void Patient::change_diagnosis(const Diagnosis d)
{
	// If diagnosis is the same we dont need to change anything and return
    if(d == diagnosis_)
    {
        std::cout << "Patient with ID " << id_ << " already diagnosed with " << d << std::endl;
        return;
    }

	// Change diagnosis to new one
    set_diagnosis(d);

	// Reset timetocure
    set_time_to_cure(calc_time_to_cure());
}

// Compare two patients per pointer and return bool if they are the same
// Comparison of firstname, lastname and birthdate
// Used in hospital find() function to search for a patient
bool Patient::compare_patients(Patient* p1, Patient* p2)
{
	// if names identicaly check birthday
	if (p1->firstname_ == p2->firstname_ && p1->lastname_ == p2->lastname_)
	{
		// Get int values from struct Date and simply add them up into their unique number combination
		// That way we do not need to convert to string and compare those
        const int p1_birthsum = p1->birthdate_.day + p1->birthdate_.mon + p1->birthdate_.year;
        const int p2_birthsum = p2->birthdate_.day + p2->birthdate_.mon + p2->birthdate_.year;

		// Names and Birthday the same - return bool true
		if (p1_birthsum == p2_birthsum)
		{
            return true;
		}
	}

	// Patients not equal - return false
    return false;
}
