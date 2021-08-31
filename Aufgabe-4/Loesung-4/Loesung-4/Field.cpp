#include "Field.h"

// Implement initialized methods from Field.h
// Get integer from cin and prevent strange entries
// Problem: Before cin int input like 10f3r5 resulted in 10 - break after the letter. Could lead to unwanted results - only accept digit entries.
int Field::getnumber() const
{
	// Initialize necessary vars
	std::string str;

	// Read whole input cin into string var first, because here it does not break after letters
	while (getline(std::cin, str))
	{
		// Exception if empty - request valid entry
		if (str.empty())
		{
			std::cout << "Error, you have to enter something. Please do so!" << std::endl;
			continue;
		}

		// Search if there is an unwanted char in string: If we do not find an unaccepted char size_t becomes npos (18446744073709551615 == -1)
		size_t const flag = str.find_first_not_of("-0123456789");

		// If no unaccepted characters return accepted number
		if (flag == std::string::npos)
		{
			const int a = stoi(str);
			return a;
		}

		std::cout << "Error, enter only valid int numbers. Please try again!" << std::endl;
	}

	return 0;
}


// Initialize field by giving every field coordinates and placing amount of set mines
void Field::initialize(int placemines)
{
	mines = placemines;
	
	// Give every tile their according x and y axis specifier
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			field_[x][y].x_axis = x;
			field_[x][y].y_axis = y;
		}
	}

	// Create mines on random tiles until we have got all of them
	while (placemines > 0) {
		const int rand_x = rand() % width;
		const int rand_y = rand() % height;

		// change from unrevealed to mine (tiles are initialized with that value)
		if (field_[rand_x][rand_y].tilestate == Tilestate::unrevealed) {
			field_[rand_x][rand_y].tilestate = Tilestate::mine;
			placemines--;
		}
	}

	// After mines are created use calculateNeighbours to get amount of adjacent mines
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			// Get amount of adjacent mines for each Tile into variable and set Tile data accordingly
			const int neighbours = calculate_neighbors(x, y);
			field_[x][y].adjacent_mines_counter = neighbours;
		}
	}
}


// Calculate amount of unrevealed tiles without mines
int Field::calcremainingtiles() const
{
	int openfields = 0;

	// Check all fields per their x and y axis
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			// If tiles is unrevealed it is one of the fields we still need to find - increase counter
			if (field_[x][y].tilestate == Tilestate::unrevealed)
				openfields++;
		}
	}

	return openfields;
}


// Calculate amount of mines adjacent to given tile coordinates
int Field::calculate_neighbors(const int x, const int y) const
{
	// Initialize with 0 adjacent mines
	int result = 0;

	// Calculate the coordinates each with +1 +0 -1 to go in a circle around it and scan for mines
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			const int neighbour_x = x + i;
			const int neighbour_y = y + j;
			
			// Handle out of bound calculations
			if (0 <= neighbour_x && neighbour_x < width && 0 <= neighbour_y && neighbour_y < height)
			{
				// If there is a mine adjacent increase mine counter
				if (field_[neighbour_x][neighbour_y].tilestate == Tilestate::mine)
					result++;
			}
		}
	}

	// Return mine counter
	return result;
}


// Print current state from playing field into console
void Field::print(const bool debug) const
{
	// Use stringstream to build one big stream for state of playingfield and cout at the end
	std::stringstream result;

	// stylistic top line labels with indent for alignment -- START
	// ============================================================
	result << "    ";
	for (int x = 0; x < width; x++)
	{
		if (x < 10)
			result << "0" << x << " ";
		else
			result << x << " ";
	}
	result << std::endl;
	
	result << "   ";
	for (int x = 0; x < width; x++)
		result << "===";
	result << std::endl;
	// ============================================================
	// stylistic top line labels with indent for alignment -- END

	
	// Start with top down so we can label the left side in the beginning
	for (int x = 0; x < height; x++)
	{
		// Numeric description of lines (add 0 so single didgets so we align eg 01 with 10)
		if (x < 10)
			result << "0";
		result << x << "|";

		// Check x and y axis and output according tilestate
		for (int y = 0; y < width; y++)
		{
			// If we enabled debug just print tilestate, mines included
			// tilestates are already calculated into string by overload function in Tile.h!
			if (debug)
				result << field_[x][y];
			else
			{
				// If tile is revealed simply print its state string
				if (field_[x][y].tilestate == Tilestate::revealed)
					result << field_[x][y];
				// All unrevealed tiles get *, also mines, except when marked
				else
				{
					if (field_[x][y].guessedmine)
						result << "  M";
					else
						result << "  *";
				}	
			}
		}

		// Break lines for each completed line
		result << std::endl;
	}
	
	// At the end return the big built stringstream as sting
	std::cout << result.str();
}


// Evaluate and handle a guess of a tile coordinates and return bool value gameover if game continues
bool Field::guess(const int x, const int y)
{

	// If its a mine return gameover - true
	if (field_[x][y].tilestate == Tilestate::mine) {
		std::cout << "BOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!" << std::endl;
		return true;
	}

	// If tile already revealed return false (...)
	if (field_[x][y].tilestate == Tilestate::revealed) {
		std::cout << "Tile already revealed..." << std::endl;
		return false;
	}

	// If we got past the two ifs we did not find a mine - reveal this field
	field_[x][y].tilestate = Tilestate::revealed;
	
	// If we found a field with 0 neighbours we enter the algorithm to reveal its neighbours
	// and if they have 0 neighbours too repeat it for those, too
	if (field_[x][y].adjacent_mines_counter == 0)
		reveal_neighbours(x, y);

	// Game continues
	return false;
	
}


// On successfull guesses on fields with 0 neighbours call recursive algorithm to also reveal all neighbours who also have 0 neighbours
void Field::reveal_neighbours(const int x, const int y)
{
	// Set handler to avoid duplicate reveal of neighbours
	field_[x][y].neighboursrevealed = true;

	// Search all neighbours of 0 neighbour tile and reveal them
	for (Tile* t : get_neighbours(x, y))
	{
		if (t->tilestate == Tilestate::unrevealed)
			t->tilestate = Tilestate::revealed;
	}

	// Also search all neighbours if their adjecent tiles also have 0 neighbours and if the handler of if already revealed is not true
	// If both of those are right for the neighbours we call this function to reveal and scan its neighbours again in a recursive call
	for (Tile* t : get_neighbours(x, y))
	{
		if (t->adjacent_mines_counter == 0 && !t->neighboursrevealed)
			reveal_neighbours(t->x_axis, t->y_axis);
	}
}


// Return Vector with all tiles that are adjacent to given tile coordinates
std::vector<Tile*> Field::get_neighbours(const int x, const int y)
{
	// Initialize vector to save adjacent ties in
	std::vector<Tile*> neighbours;
	
	// Calculate the coordinates each with +1 +0 -1 to go in a circle around it and scan for mines
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{

			const int neighbour_x = x + i;
			const int neighbour_y = y + j;

			// If out of bound or same field dont do anything and continue from the top
			if(i == 0 && j == 0 || neighbour_x < 0 || width - 1 < neighbour_x || neighbour_y < 0 || height - 1 < neighbour_y)
				continue;

			// Add neighbour to vector
			neighbours.push_back(&field_[neighbour_x][neighbour_y]);
		}
	}

	// Return vector with all neighbour tiles back to the recursive function
	return neighbours;
}


// Function to toggle state of tile if it was marked to be a mine or not
bool Field::toggle_minemark(const int x, const int y)
{
	// Toggle the guessed state
	if (field_[x][y].guessedmine)
		field_[x][y].guessedmine = false;
	else
		field_[x][y].guessedmine = true;

	// Return false to gameover - game cant be over after guessing anyway
	return false;
}


