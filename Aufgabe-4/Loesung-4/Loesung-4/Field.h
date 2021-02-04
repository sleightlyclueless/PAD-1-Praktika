#pragma once
#include "Tile.h"

// Create class for minesweeper field with according methods
class Field
{

	// Atributes: Create minesweeper field with const height and width dimensions = 12
	private:

		// Note: Array field_ has to be a square
		static const int width = 15;
		static const int height = 15;
		int mines_ = 0;
		// Initialize field array with Tiles struct in each field
		Tile field_[width][height];
	
	
	public:
	
		// Constructor
		Field()
		{
			
		}

		// Destructor
		~Field()
		{

		}
	
		// Methods
		//
		// Set amount of mines the field is initialized
		static int getWidth() { return width; }
		static int getHeight() { return height; }
		void setMines(int m) { mines_ = m; }
	
		// Methods initialized here and implemented in according Field.cpp
		int getnumber() const; // Get integer from cin and prevent strange entries
		void initialize(); // Initialize field by giving every field coordinates and placing amount of set mines
		int calcremainingtiles() const; // Calculate amount of unrevealed tiles without mines
		int calculate_neighbors(int x, int y) const; // Calculate amount of mines adjacent to given tile coordinates
		void print(bool debug) const; // Print current state from playing field into console
		bool guess(const int x, const int y); // Evaluate and handle a guess of a tile coordinates and return bool value gameover if game continues
		void reveal_neighbours(const int x, const int y); // On successfull guesses on fields with 0 neighbours call recursive algorithm to also reveal all neighbours who also have 0 neighbours
		std::vector<Tile*> get_neighbours(const int x, const int y); // Return Vector with all tiles that are adjacent to given tile coordinates
		bool toggle_minemark(const int x, const int y); // Function to toggle state of tile if it was marked to be a mine or not
	
};