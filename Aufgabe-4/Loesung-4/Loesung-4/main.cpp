#include "Field.h"


int main()
{
	// Get start time before playing to calculate elapsed time for display
	const auto start = std::chrono::high_resolution_clock::now();
	
	// Get random seed for initialize etc.
	srand(time(nullptr));
	
	// Allow output of utf-8 chars
	setlocale(LC_ALL, "");

	// Game runs as long as this field is false
	bool gameover = false;

	// Char to toggle between guess and mark mine mode
	char togglemode;
	

	// Create object from class field so we can use the field and its functions
	Field field;

	// Initialise playing field
	field.setMines(10);
	field.initialize();

	
	// Run game as long as no mine was hit or win condition not reached
	while(!gameover)
	{
		// Calculate and print remaining open fields as win condition
		const int openfields = field.calcremainingtiles();
		std::cout << "Remaining open fields: " << openfields << std::endl << std::endl;
		
		// Print field itself
		field.print(false);
		
		// Calc elapsed time and show it
		const auto end = std::chrono::high_resolution_clock::now();
		auto elapsed_secs = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
		std::cout << "Elapsed time: ";
		if (elapsed_secs / 3600 > 0)
		{
			std::cout << elapsed_secs / 3600 << " hours, ";
			elapsed_secs = elapsed_secs - (elapsed_secs / 3600) * 3600;
		}
		if (elapsed_secs / 60 > 0)
		{
			std::cout << elapsed_secs / 60 << " minutes, ";
			elapsed_secs = elapsed_secs - (elapsed_secs / 60) * 60;
		}
		std::cout << elapsed_secs << " seconds" << std::endl << std::endl;

		
		// Check win condition and end loop / game if reached
		if (openfields == 0)
		{
			std::cout << "You win!" << std::endl << std::endl;
	
			break;
		}

		
		// User instructions to toggle between guess or mark mine mode
		std::cout << "Do you want to toggle a mine guess, type 'y' if yes, anything else if no" << std::endl;
		std::cin >> togglemode;
		togglemode = std::tolower(togglemode);
		if (togglemode == 'y')
		{
			std::cout << "Mine - mark - mode: State coordinates from the field where you want to toggle a mark of a mine" << std::endl;
		} else
		{
			std::cout << "State coordinates from the field to guess" << std::endl;
		}

		
		// User instructions to get coordinates from field to check / mark
		std::cout << "Vertical column: ";
		int x = field.getnumber();
		while (x < 0 || Field::getWidth() - 1 < x)
		{
			std::cout << "Error - only columns from 0 - " << Field::getWidth() - 1 << " available!" << std::endl;
			x = field.getnumber();
		}
		
		std::cout << "Horizontal column: ";
		int y = field.getnumber();
		while (y < 0 || Field::getHeight() - 1 < y)
		{
			std::cout << "Error - only columns from 0 - " << Field::getHeight() - 1 << " available!" << std::endl;
			y = field.getnumber();
		}
		std::cout << "Your field: " << x << " " << y << std::endl;


		// Handle field to check depending on mode (guess or mark) we are in
		if (togglemode == 'y')
		{
			// Mark given field as mine
			gameover = field.toggle_minemark(x, y);
		}
		else
		{
			// Evaluate given field and update game state and field
			gameover = field.guess(x, y);
		}

		std::cout << std::endl;
		
	}
	
	// Print field to show mines in the end
	field.print(true);
	
	return 0;
}