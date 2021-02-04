#pragma once
#ifndef PAD1_ZWISCHENTEST_H
#define PAD1_ZWISCHENTEST_H

// Includes
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cmath>


// Enum für feste Werte von Geschlecht
enum Geschlecht
{
	m, w, d
};
std::array<std::string, 3> geschlecht_string{ "männlich", "weiblich", "divers" };

// Kunden struct zum erstellen von Kunden - Objekten
struct Kunde {
	std::string nname;
	std::string vname;
	Geschlecht geschlecht;
	int knr;
	double guthaben;
};

// Functions
void search_customer();
Kunde getCustomer(int curr_knr);
auto sortDatabase(std::vector<Kunde> kunden_db);
double compoundInterest(int n);

#endif