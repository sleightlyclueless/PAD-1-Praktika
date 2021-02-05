#include "hospital.h"

#include "main.h"

Hospital::Hospital()
{
	
}


void Hospital::print()
{
	
	for (Patient p : patients_)
	{
		p.print();
	}
	
}

int Hospital::get_free_beds() const
{
	const int free_beds = get_beds() - get_patients().size();
	return free_beds;
}

void Hospital::initialize(int fillbeds)
{
	int b = get_free_beds();
	int patient_id = get_patients_handeled();
	const int overflow = fillbeds - b;

	if(overflow > 0)
	{
		std::cout << overflow << " less beds than people available!" << std::endl;
		fillbeds = fillbeds - overflow;
	}

	for (int i = 0; i < fillbeds; i++)
	{
		Patient p = new_patient(patient_id);
		patients_.push_back(p);
		patient_id++;
	}

	set_patients_handeled(patient_id);
}


void Hospital::add_patients(int p)
{
	int free = get_free_beds();
	const int overflow = p - free;

	if (overflow > 0)
	{
		std::cout << overflow << " less beds than people available!" << std::endl;
		p = p - overflow;
	}

	int patient_id = get_patients_handeled();

	for (int i = 0; i < p; i++)
	{
		Patient p = new_patient(patient_id);
		patients_.push_back(p);
		patient_id++;
	}

	set_patients_handeled(patient_id);

}

void Hospital::time_passed(int days)
{
	int counter = 0;
	for (Patient& p : patients_)
	{
		const int currtimetocure = p.get_time_to_cure();
		if (currtimetocure - days <= 0)
		{
			p.set_time_to_cure(0);
			p.set_diagnosis(cured);
			patients_.erase(patients_.begin() + counter);
			counter--;
		}
		else
		{
			p.set_time_to_cure(currtimetocure - days);
		}
		counter++;
	}

}
