#pragma once

// Libraries used throughout project
#include <iostream> // Enable Console output
#include <sstream> // Sstream to dynamically build big string for the playing field print
#include <array> // Array for playing field
#include <vector> // Vectors for dynamic tile-lists
#include <ctime> // Generate random numbers
#include <chrono> // Display elapsed time


// Enum for possible tile states
enum class Tilestate
{
	unrevealed = 0,
	mine,
	revealed
};


// Struct for tiles
struct Tile
{
	// Possible values for struct tile with default values for initialisation
	Tilestate tilestate = Tilestate::unrevealed;
	bool neighboursrevealed = false;
	bool guessedmine = false;
	int adjacent_mines_counter = 0;
	int x_axis = 0;
	int y_axis = 0;
};


// Overload function to handle tilestates and return according string for print function instantly
inline std::ostream &operator << (std::ostream &os, const Tile &t)
{
	// Get tilestate from tile into switch case
	switch (t.tilestate) {

		// Get current string from tilestate into ostream var os to return and use in print function
		// Whitespaces for better display in cout console
		case Tilestate::unrevealed:
			os << "  *";
			break;
		
		case Tilestate::mine:
			os << "  X";
			break;

		case Tilestate::revealed:
			if (t.adjacent_mines_counter > 0)
				os << "  " << t.adjacent_mines_counter;
			else
				os << "  .";
			break;
	}
	
	// Return the string for tilestate with var os
	return os;
}