// Externe Funktionen aus header-file
#include "Zwischentest.h"

// Vector für Kunden DB initialisieren - Vektor da dynamische Größe für DB Einträge
std::vector<Kunde> kunden_db;
std::vector<Kunde> kunden_db_sorted;


// Aufgabe 1.1: Interface zur Suche von Kunden Infos per Kundennummer
void search_customer()
{
	int id = 0;

	// Abbruchbedingung bei negativen Eingaben von IDs
	while (id >= 0)
	{
		std::cout << "Nach Kunden per Kundennummer suchen. Wenn sie keine weiteren Suchen durchführen wollen geben Sie als knr bitte einfach eine negative Zahl ein." << std::endl;
		std::cin >> id;

		if (id < 0)
			break;

		if (id >= kunden_db.size())
		{
			std::cout << "Wir haben keinen Kunden mit dieser Kundennummer gefunden! Bitte versuchen Sie es erneut!" << std::endl << std::endl;
			continue;
		}

		std::cout << "Vorname: " << kunden_db[id].vname << std::endl
					<< "Nachname:" << kunden_db[id].nname << std::endl
					<< "Geschlecht: " << geschlecht_string[kunden_db[id].geschlecht] << std::endl
					<< "Kontostand: " << kunden_db[id].guthaben << std::endl << std::endl;

	}

}

// Aufgabe 1.2: Finde Kunde anhand seiner Kontonummer
Kunde getCustomer(int curr_knr)
{
	// Nach gültiger Nummer suchen
	if (curr_knr < 1111111 || curr_knr > 9999999)
	{
		std::cout << "Entschuldigung, das war keine gültige Kontonummer!" << std::endl;
		return Kunde();
	}

	// DB durchsuchen nach Kontonummer und zurückgeben falls vorhanden
	for (const Kunde& i : kunden_db)
	{
		if (i.knr == curr_knr)
		{
			return i;
		}

	}

	// Wenn wir diese stelle erreichen: Nichts gefunden!
	std::cout << "Entschuldigung, wir haben keinen Kunden mit dieser Kundennummer gefunden!" << std::endl << std::endl;
	return Kunde();

}

// Aufgabe 1.3 Insertion sort
auto sortDatabase(std::vector<Kunde> kunden_db)
{
	
	// DB Vektor alphabetisch für Nachnamen sortieren per Insertion Sort
	for (int i = 1; i < kunden_db.size(); i++)
	{
		const Kunde tmp = kunden_db[i];
		int j = i - 1;

		while (j>=0 && tmp.nname < kunden_db[j].nname)
		{
			kunden_db[j + 1] = kunden_db[j];
			j--;
		}

		kunden_db[j + 1] = tmp;
	}

	return kunden_db;
}

// Guthaben nach n Jahren = Guthaben · (1+ Zinssatz/100)^n
// Zins positive Guthaben dabei 2 Prozent
// Zins negative Guthaben Aufschlag von 5 Prozent
// Geben Sie das geschätzte Gesamtguthaben aller Kunden nach n Jahren zurück
double compoundInterest(int n)
{
	double auslagen = 0;
	
	for (const Kunde& i : kunden_db)
	{

		// pow: Hoch rechnung aus cmath
		if (i.guthaben >= 0)
		{
			std::cout << i.nname << " :" << i.guthaben << std::endl;
			auslagen += i.guthaben * pow(1.02, n);
		}
		else
		{
			std::cout << i.nname << " :" << i.guthaben << std::endl;
			auslagen += i.guthaben * pow(1.05, n);
		}

		std::cout << "Auslagen - Stand: " << auslagen << std::endl;
	}
	
	return auslagen;
}

int main()
{
	// Umlaute erlauben (Deutsch...)
	setlocale(LC_ALL, "");

	
	// Datenbank (Vektor) mit 5 Personen füllen, Vektor weil Datenbank kann Größe ändern!
	kunden_db.push_back(Kunde{ "Pietersen", "Pietra", w, 2431109, -17928.90 });
	kunden_db.push_back(Kunde{ "Modaal", "Maria", d, 3102938, 12000.00 });
	kunden_db.push_back(Kunde{ "Klakson", "Klara", w, 2439101, 4938.02 });
	kunden_db.push_back(Kunde{ "Joskens", "Jos", m, 2555101, -4500.00 });
	kunden_db.push_back(Kunde{ "Janssen", "Jan", m, 2244887, 13465.30 });
	

	// Aufgabe 1.1: Interface zur Suche von Kunden und deren Infos per Kundennummer
	// search_customer();


	// Aufgabe 1.2: Finde Kunde anhand seiner Kontonummer
	/*const int curr_knr = 2555101;
	Kunde c = getCustomer(curr_knr);
	if (!empty(c.vname))
	{
		std::cout << "Vorname: " << c.vname << std::endl;
		std::cout << "Nachname:" << c.nname << std::endl;
		std::cout << "Geschlecht: " << geschlecht_string[c.geschlecht] << std::endl;
		std::cout << "Kontostand: " << c.guthaben << std::endl;
	}*/

	
	// Aufgabe 1.3 Insertion Sort für Vektor - KundenDB
	// Pre sort
	/*std::cout << "Vor Insertion-sort: " << std::endl;
	for (const Kunde& i : kunden_db)
	{
		std::cout << "Vorname: " << i.vname << std::endl;
		std::cout << "Nachname:" << i.nname << std::endl;
		std::cout << "Geschlecht: " << i.geschlecht << std::endl;
		std::cout << "Kontostand: " << i.guthaben << std::endl;
		std::cout << std::endl;
	}
	
	// Sort-Function
	std::vector<Kunde> kunden_db_sorted = sortDatabase(kunden_db);
	std::cout << "=========================" << std::endl;
	
	// Post sort
	std::cout << "Nach Insertion-sort: " << std::endl;
	for (const Kunde& i : kunden_db_sorted)
	{
		std::cout << "Vorname: " << i.vname << std::endl;
		std::cout << "Nachname:" << i.nname << std::endl;
		std::cout << "Geschlecht: " << i.geschlecht << std::endl;
		std::cout << "Kontostand: " << i.guthaben << std::endl;
		std::cout << std::endl;
	}
	// Laufzeit AC: 1/4 * (n^2 - n)
	// Vergleiche: 10 Stück*/

	
	// Aufgabe 1.4: Für n Jahre Guthaben berechnen:
	/*int jahre = 5;
	double auslagen = compoundInterest(jahre);
	std::cout << "Auslagen nach " << jahre << " Jahren: " << auslagen << std::endl;*/
	
	return 0;
}