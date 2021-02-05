#include "patient.h"
#include <iostream>


int main()
{
	srand(time(NULL));

	Date date;
	date.day = rand() % 30;
	date.mon = static_cast<Month>(rand() % 13);
	date.year = 1950 + rand() % 99;
	

	std::cout << "Hi" << std::endl;

    return 0;
}





/*Patient newPatient()
{

    Gender gender;
    std::string firstname;
    Date birthday;
    Diagnosis diagnosis;

    // Get random lastname
    const std::string lastname = lastNames.at(rand() % 50);

    // Get rand gender and name
    switch (rand() % 3)
    {
    case 0:
        //male
        firstname = firstNames_male.at(rand() % 50);
        gender = male;
        break;

    case 1:
        //female
        firstname = firstNames_female.at(rand() % 50);
        gender = female;
        break;

    case 2:
        gender = diverse;
        switch (rand() % 2)
        {
        case 0:
            //female
            firstname = firstNames_female.at(rand() % 50);
            break;

        case 1:
            //male
            firstname = firstNames_male.at(rand() % 50);
            break;
        }
        break;
    }
    // Get random diagnose
    switch (rand() % 4)
    {
    case 0:
        diagnosis = simulant;
        break;

    case 1:
        diagnosis = infection;
        break;

    case 2:
        diagnosis = fracture;
        break;

    case 3:
        diagnosis = cured;
        break;
    }


    // Get random bdate
    birthday.day = rand() % 30;
    birthday.mon = static_cast<Month>(rand() % 13);
    birthday.year = 1950 + rand() % 99;

    return Patient(gender, firstname, lastname, birthday, diagnosis);
}*/