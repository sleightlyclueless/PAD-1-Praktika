#pragma once
#include <ostream>
#include <vector>
#include <iostream>
#include <string>

enum Gender
{
	male = 0,
	female,
	diverse
};
inline std::ostream& operator << (std::ostream& os, const Gender& t)
{
	switch (t)
	{
	case 0:
		os << "male";
		break;

	case 1:
		os << "female";
		break;

	case 2:
		os << "divers";
		break;
	}

	return os;
}

enum Diagnosis
{
	simulant = 0,
	infection,
	fracture,
	cured
};
inline std::ostream& operator << (std::ostream& os, const Diagnosis& d)
{
	switch (d)
	{
	case 0:
		os << "simulant";
		break;

	case 1:
		os << "infection";
		break;

	case 2:
		os << "fracture";
		break;
	
	case 3:
		os << "cured";
		break;
	}
	
	return os;
}

enum Month
{
	January = 0,
	February,
	March,
	April,
	Mai,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};
inline std::ostream& operator << (std::ostream& os, const Month& d)
{
	switch (d)
	{
	case 0:
		os << "January";
		break;
	case 1:
		os << "February";
		break;
	case 2:
		os << "March";
		break;
	case 3:
		os << "April";
		break;
	case 4:
		os << "May";
		break;
	case 5:
		os << "June";
		break;
	case 6:
		os << "July";
		break;
	case 7:
		os << "August";
		break;
	case 8:
		os << "September";
		break;
	case 9:
		os << "Oktober";
		break;
	case 10:
		os << "November";
		break;
	default:
		os << "December";
		break;
	}

	return os;
}
const std::vector<std::string> enum_str = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

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
		int id_;
		Gender gender_;
		std::string firstname_;
		std::string lastname_;
		Date birthdate_;
		Diagnosis diagnosis_;
		int timetocure_;

	public:
		static int global_id_;
		// Constructor
		Patient(Gender gender, std::string firstname, std::string lastname, Date birthdate, Diagnosis diagnosis);

		~Patient()
		= default;

		
		// Get Methods
		static int get_global_id() { return global_id_; }
		int get_id() const { return id_; }
		Gender get_gender() const { return gender_; }
		std::string get_firstname() const { return firstname_; }
		std::string get_lastname() const { return lastname_; }
		Date get_birthdate() const { return birthdate_; }
		Diagnosis get_diagnosis() const { return diagnosis_; }
		int get_time_to_cure() const { return timetocure_; }

		// Set Methods
		void set_id(const int i) { id_ = i; }
		void set_diagnosis(Diagnosis d) { diagnosis_ = d; }
		void set_time_to_cure(const int t) { timetocure_ = t; }

		// Methods
		void print() const; // Print current patient data
		static std::string enum_to_str(int i);
		void reduce_time_to_cure(int t);
		void change_diagnosis(Diagnosis d);
		static bool compare_patients(Patient* p1, Patient* p2);
};