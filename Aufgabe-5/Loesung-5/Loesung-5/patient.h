#pragma once
#include <string>

enum Gender
{
	male = 0,
	female,
	diverse
};

enum Diagnosis
{
	simulant = 0,
	infection,
	fracture,
	cured
};

enum Month
{
	january = 0,
	febuary,
	march,
	april,
	mai,
	june,
	july,
	august,
	september,
	october,
	november,
	december
};

struct Date
{
	int day;
	Month mon;
	int year;
};


class Patient
{
	private:
		// Attributes
		Gender gender;
		std::string firstname;
		std::string lastname;
		Date birthdate;
		Diagnosis diagnosis;
		int timetocure;

	public:
		// Constructor
		Patient(Gender gender, std::string firstname, std::string lastname, Date birthday, Diagnosis diagnosis);


		~Patient()
		= default;
};