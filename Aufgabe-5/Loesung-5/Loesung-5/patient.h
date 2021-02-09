#pragma once
#include <ostream>
#include <string>

enum Gender
{
	male = 0,
	female,
	diverse
};
inline std::ostream& operator << (std::ostream& os, const Gender& g)
{
	switch (g)
	{
		case 0:
			os << "Male";
			break;
		case 1:
			os << "Female";
			break;
		case 2:
			os << "Divers";
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
			os << "Simulant";
			break;
		case 1:
			os << "Infection";
			break;
		case 2:
			os << "Fracture";
			break;
		case 3:
			os << "Cured";
			break;
	}
	return os;
}

enum Month
{
	january = 0,
	february,
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
		case 11:
			os << "December";
			break;
	}
	return os;
}

struct Date
{
	int day;
	Month mon;
	int year;
};



class Patient
{
	
	private:
		// Attributes -- TODO usually start with m
		int id_;
		Gender gender_;
		std::string firstname_;
		std::string lastname_;
		Date birthdate_;
		Diagnosis diagnosis_;
		int timetocure_;

	public:
		// Public static var to count patient id
		static int global_id;
	
		// Constructor
		// TODO DEFAULT VALUE ONE CONSTRUCT Patient(Gender gender, std::string firstname, std::string lastname, Date birthdate, Diagnosis diagnosis = simulant);
		Patient(Gender gender, std::string firstname, std::string lastname, Date birthdate, Diagnosis diagnosis);
		Patient(Gender gender, std::string firstname, std::string lastname, Date birthdate);

		// Destructor
		~Patient()
		= default;

		
		// Get Methods
		static int get_global_id() { return global_id; }
		int get_id() const { return id_; }
		int get_time_to_cure() const { return timetocure_; }

		// Set Methods
		void set_id(const int i) { id_ = i; }
		void set_diagnosis(Diagnosis d) { diagnosis_ = d; }
		void set_time_to_cure(const int t) { timetocure_ = t; }

		// Methods
		void print_patient_data() const; // Print current patient data
		int calc_time_to_cure() const; // Calc and return remaining time to cure fom diagnosis
		int reduce_time_to_cure(int t); // Function to reduce the cure time. Used from hospital when a day passes
		void change_diagnosis(Diagnosis d); // Change diagnosis and reset timetocure accordingly again
		static bool compare_patients(Patient* p1, Patient* p2); // Compare two patients per pointer and return bool if they are the same

};