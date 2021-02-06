#include "patient.h"

int Patient::global_id_ = 100000;

Patient::Patient(Gender gender, std::string firstname, std::string lastname, Date birthdate, Diagnosis diagnosis)
    :gender_(gender), firstname_(firstname), lastname_(lastname), birthdate_(birthdate), diagnosis_(diagnosis)
{
    
    id_ = ++global_id_;
	
    switch (diagnosis_)
    {
    case infection:
        timetocure_ = 14;
        break;

    case fracture:
        timetocure_ = 42;
        break;

    case cured:
        timetocure_ = 0;
        break;

    default:
        timetocure_ = 2;
        break;
    }
}



void Patient::print() const
{    
    std::string day_str = std::to_string(get_birthdate().day);
    if (get_birthdate().day < 10)
    {

        if (get_birthdate().day == 1)
        {
            day_str = day_str + "st";
        }
        else if (get_birthdate().day == 2)
        {
            day_str = day_str + "nd";
        }
        else if (get_birthdate().day == 3)
        {
            day_str = day_str + "rd";
        }

    }
    else
    {
        day_str = day_str + "th";
    }

    std::cout << "Status for Patient Number: " << get_id() << std::endl
    << "Firstname: " << get_firstname() << std::endl
    << "Lastname: " << get_lastname() << std::endl
    << "Gender: " << get_gender() << std::endl
	<< "Birthday: " << day_str << " " << get_birthdate().mon << " " << get_birthdate().year << std::endl
	<< "Diagnosis: " << get_diagnosis() << std::endl
	<< "Days till cure: " << get_time_to_cure() << std::endl << std::endl
	<< "===========================" << std::endl;
}

void Patient::reduce_time_to_cure(int t)
{
    int timetocure = get_time_to_cure();
    timetocure = timetocure - t;

	if (timetocure < 1)
	{
        set_diagnosis(cured);
        set_time_to_cure(0);
	} else
	{
        set_time_to_cure(timetocure);
	}
}

void Patient::change_diagnosis(Diagnosis d)
{
    if(d == get_diagnosis())
    {
        return;
    }
	
    set_diagnosis(d);
	
    switch (diagnosis_)
    {
    case infection:
        set_time_to_cure(14);
        break;

    case fracture:
        set_time_to_cure(42);
        break;

    case cured:
        set_time_to_cure(0);
        break;

    default:
        set_time_to_cure(2);
        break;
    }
}

bool Patient::compare_patients(Patient* p1, Patient* p2)
{
	if (p1->get_firstname() == p2->get_firstname() && p1->get_lastname() == p2->get_lastname())
	{
        const int p1birthsum = p1->get_birthdate().day + p1->get_birthdate().mon + p1->get_birthdate().year;
        const int p2birthsum = p2->get_birthdate().day + p2->get_birthdate().mon + p2->get_birthdate().year;
        
		if (p1birthsum == p2birthsum)
		{
            return true;
		}
	}
	
    return false;
}
