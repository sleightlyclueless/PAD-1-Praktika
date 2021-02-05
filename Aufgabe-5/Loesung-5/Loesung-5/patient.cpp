#include "patient.h"
#include <iostream>

Patient::Patient(Gender gender, std::string firstname, std::string lastname, Date birthdate, Diagnosis diagnosis)
{
    switch (diagnosis)
    {
    case infection:
        timetocure = 14;
        break;

    case fracture:
        timetocure = 42;
        break;

    case cured:
        timetocure = 0;
        break;

    default:
        timetocure = 2;
        break;
    }
}