#pragma once
#include "hospital.h"
#include "names.h"

// Generate random values for a patient and return patient object with these values
inline Patient new_patient()
{
    Gender gender;
    std::string firstname;
    // ReSharper disable once CppInitializedValueIsAlwaysRewritten
    Date birthday{};
    Diagnosis diagnosis;

    // Get rand gender and name
    switch (rand() % 3)
    {
    case 0:
        //male
        firstname = first_names_male.at(rand() % 50);
        gender = male;
        break;

    case 1:
        //female
        firstname = first_names_female.at(rand() % 50);
        gender = female;
        break;

    default:
        // diverse
        gender = diverse;
        switch (rand() % 2)
        {
        case 0:
            //female
            firstname = first_names_female.at(rand() % 50);
            break;

        default:
            //male
            firstname = first_names_male.at(rand() % 50);
            break;
        }
        break;
    }

    // Get random lastname
    const std::string lastname = last_names.at(rand() % 50);

    // Get random diagnose (never initialized with diagnose cured)
    switch (rand() % 3)
    {
    case 0:
        diagnosis = simulant;
        break;

    case 1:
        diagnosis = infection;
        break;

    default:
        diagnosis = fracture;
        break;
    }

    // Get random bdate
    birthday.day = rand() % 30;
    birthday.mon = static_cast<Month>(rand() % 13);
    birthday.year = 1950 + rand() % 70;

    return Patient(gender, firstname, lastname, birthday, diagnosis);
}
