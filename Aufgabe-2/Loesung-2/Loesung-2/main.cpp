// Import necessary libs
#include <iostream> /*basic */
#include <string> /* getline and stoi */
#include <ctime> /* time */
#include <array> /* arrays */



// Function to get only digits on cin inputs
int get_number() {
	// Problem: Before cin int input like 10f3r5 resulted in 10 - break after the letter. Could lead to unwanted results.
	// Therefore check and only accept digit entries.

	// Initialize necessary vars
	std::string str;
	int a;
	int firsttime = 0;

	// Read whole input cin into string var first, because here it does not break after letters
	while (getline(std::cin, str))
	{
		// Exception if empty - request valid entry
		if (str.empty())
		{
			if (firsttime != 0)
			{
				std::cout << "Error, you have to enter something. Please do so!" << std::endl;
			}
			continue;
		} 
		
		// Search if there is an unwanted char in string.
		// size_t can store up to max size of an object - if we do not find an unaccepted char it becomes -1 or npos (18446744073709551615 == -1)
		auto const flag = str.find_first_not_of("-0123456789");

		// npos is type size_t and cant be negative therefore it takes on the value of the highest possible number. If that is the case we have an accepted integer input
		if (flag == std::string::npos)
		{
			// Success - valid int - transform to int
			a = stoi(str);
			// If we found an fitting int - exit the whole while loop - we are done here
			break;
		}

		std::cout << "Error, enter only valid int numbers. Please try again!" << std::endl;
		firsttime++;
	}

	// When we exited the while loop we found an int var. Go ahead and return that to the function call.
	return a;
}

// Function to ask the player to continue or quit playing
bool want_to_play(const int timesplayed)
{
	std::string ans;
	bool optin = false;

	// Different user questions depending if you call this first or another time
	if (timesplayed == 0)
	{
		std::cout << "Welcome - Would you like to play a game of roulette and are you over the age of 18?" << std::endl;
	}
	else
	{
		std::cout << "Would you like to play again?" << std::endl;
	}

	// Get user input ('y' if he wants to play)
	std::cout << "Type 'y' if so. Type something else to leave." << std::endl;
	std::cin >> ans;
	while (ans.empty())
	{
		std::cout << "Error, you have to enter something. Please do so!" << std::endl;
		std::cin >> ans;
	}
	std::cout << std::endl;
	
	// If he wants to play ('y') return true if not return false
	switch (ans[0])
	{
		case 'y':
			std::cout << "Alright, here we go!" << std::endl;
			optin = true;
			break;
		default:
			std::cout << "See you next time!" << std::endl;
			optin = false;
			break;
	}

	return optin;
}


void aufgabe2_1()
{
	// Initialize neseccary globals
	bool play = true;
	int money = 10000;

	
	// While still wants to play and still has money
	while (money > 0 && play == true) {

		// Enter bet
		std::cout << "Please enter your bet: " << std::endl;
		int bet = get_number();
		while (bet > money)
		{
			std::cout << "You don`t have that much anymore, enter another bet! " << std::endl;
			bet = get_number();
		}

		// Enter number for bet
		std::cout << "On which number do you want to bet(0-36): " << std::endl;
		int number = get_number();
		while (number < 0 || number > 36)
		{
			std::cout << "Only numbers between 0-36! " << std::endl;
			number = get_number();
		}

		// Enter winning number
		std::cout << "Which number is gonna be the winning one: " << std::endl;
		int winnumber = get_number();
		while (winnumber < 0 || winnumber > 36)
		{
			std::cout << "Only numbers between 0-36! " << std::endl;
			winnumber = get_number();
		}

		// Do if won
		if (number == winnumber) {
			bet = bet + (bet * 35);
			money = bet + money;
			std::cout << "You won: " << bet << std::endl;
			std::cout << "Now you have " << money << " left" << std::endl;

		}
		// Do if lost
		else {
			money = money - bet;
			std::cout << "You lost and have " << money << " left!" << std::endl;
		}

		// Break loop if no money left
		if (money <= 0)
		{
			std::cout << "Sorry, you have no money left!" << std::endl;
			break;
		}

		// Optin want to play again?
		play = want_to_play(1);

	}
}

void aufgabe2_2()
{
	// Initialize neseccary globals
	bool play = true;
	int money = 10000;

	// While still wants to play and still has money
	while (money > 0 && play == true) {

		// Enter bet
		std::cout << "Please enter your bet: " << std::endl;
		int bet = get_number();
		while (bet > money)
		{
			std::cout << "You don`t have that much anymore, enter another bet! " << std::endl;
			bet = get_number();
		}

		// Enter number for bet
		std::cout << "On which number do you want to bet(0-36): " << std::endl;
		int number = get_number();
		while (number < 0 || number > 36)
		{
			std::cout << "Only numbers between 0-36! " << std::endl;
			number = get_number();
		}

		// Determine random winnumber from 0 - 36
		// Pseudozufallszahlengenerator -  Jeder andere Wert für Seed legt den Generator auf einen anderen Startpunkt in der Pseudo Zufalls-Sequenz fest.
		// Als Seed nehmen wir die Systemzeit (die sich entsprechend andauernd verändert und deshalb immer an einen anderen Punkt der Zufalls-Sequenz springt.
		srand(time(NULL));
		const int winnumber = rand() % 37;
		std::cout << "Winning number is: " << winnumber << std::endl;

		// Do if won
		if (number == winnumber) {
			bet = bet + (bet * 35);
			money = bet + money;
			std::cout << "You won: " << bet << std::endl;
			std::cout << "Now you have " << money << " left" << std::endl;

		}
		// Do if lost
		else {
			money = money - bet;
			std::cout << "You lost and have " << money << " left!" << std::endl;
		}

		// Break loop if no money left
		if (money <= 0)
		{
			std::cout << "Sorry, you have no money left!" << std::endl;
			break;
		}

		// Optin want to play again?
		play = want_to_play(1);

	}
}


void aufgabe2_3()
{
	// Initialize neseccary globals
	bool play = true;
	std::string gamemode;
	int money = 10000;
	int timesplayed = 1;

	// Globals needed for bet on color
	int color;
	int wincolor = 0;

	// Globals needed for bet on columns
	int column;
	int wincolumn = 0;

	// Globals needed for bet on number
	int number;

		
	// While still wants to play and still has money
	while (money > 0 && play == true) {

		// Choose gamemode
		std::cout << "Please choose a gamemode: " << std::endl;
		std::cout << "Enter 'f' to guess a 'Farbe' / color " << std::endl;
		std::cout << "Enter 's' to guess a 'Spalte' / column " << std::endl;
		std::cout << "Enter 'z' to guess a 'Zahl' / number " << std::endl;
		std::cin >> gamemode;
		while (gamemode != "f" && gamemode != "s" && gamemode != "z")
		{
			std::cout << "That is not an available gamemode. Try again!" << std::endl;
			std::cin >> gamemode;
		}

		// Enter bet globally (no duplicate code for each mode)
		std::cout << "You currently have " << money << std::endl;
		std::cout << "Please enter your bet: " << std::endl;
		int bet = get_number();
		std::cout << "You bet: " << bet << std::endl;
		while (bet > money || bet < 1)
		{
			std::cout << "You don`t have that much money (anymore) or entered an invalid amount, enter another bet! " << std::endl;
			bet = get_number();
		}

		// Determine random winnumber from 0 - 36 everytime
		srand(time(NULL));
		const int winnumber = rand() % 37;
		
		
		// Enter gamemode logic depending on entry
		switch (gamemode[0])
		{
			
			case 'f':

				std::cout << "You chose to bet on a color! " << std::endl;
				std::cout << "Enter '1' to guess the color 'Rot' / red, meaning all uneven numbers" << std::endl;
				std::cout << "Enter '2' to guess the color 'Schwarz' / black, meaning all even numbers" << std::endl;

				// Enter color for bet with only 1 and 2 allowed
				color = get_number();
				while (color < 1 || color > 2)
				{
					std::cout << "Wrong entry! " << std::endl;
					std::cout << "Enter '1' to guess the color 'Rot' / red, meaning all uneven numbers" << std::endl;
					std::cout << "Enter '2' to guess the color 'Schwarz' / black, meaning all even numbers" << std::endl;
					color = get_number();
				}

				// Determine wincolor from given random number
				if (winnumber != 0)
				{
					if (winnumber % 2 != 0) {
						wincolor = 1;
					} else {
						wincolor = 2;
					}
				}
				std::cout << "Winning number is: " << winnumber << std::endl;
				std::cout << "Winning color is: " << wincolor << std::endl;

				// Do if won
				if (color == wincolor) {
					bet = bet + bet;
					money = bet + money;
					std::cout << "You won: " << bet << std::endl;
					std::cout << "Now you have " << money << " left" << std::endl;

				}
				// Do if lost
				else {
					money = money - bet;
					std::cout << "You lost and have " << money << " left!" << std::endl;
				}
				
				break;

			
			case 's':

				std::cout << "You chose to bet on a column! " << std::endl;

				// Enter column for bet with only 1-3 allowed
				std::cout << "On which column do you want to bet(1-3)" << std::endl;
				column = get_number();
				while (column < 1 || column > 3)
				{
					std::cout << "Enter only numbers between 1-3!" << std::endl;
					column = get_number();
				}

				// Is num 0
				if (winnumber != 0)
				{
					// Is num in col 1
					if (winnumber % 3 == 1) {
						wincolumn = 1;
					}
					// Is num in col 2
					if (winnumber % 3 == 2) {
						wincolumn = 2;
					}
					// Is num in col 3
					if (winnumber % 3 == 0) {
						wincolumn = 3;
					}
				}

				std::cout << "Winning number is: " << winnumber << std::endl;
				std::cout << "Winning column is: " << wincolumn << std::endl;

				// Do if won
				if (column == wincolumn) {
					bet = bet + (bet * 2);
					money = bet + money;
					std::cout << "You won: " << bet << std::endl;
					std::cout << "Now you have " << money << " left" << std::endl;

				}
				// Do if lost
				else {
					money = money - bet;
					std::cout << "You lost and have " << money << " left!" << std::endl;
				}
				
				break;

				
			case 'z':

				std::cout << "You chose to bet on a number! " << std::endl;

				// Enter number for bet with only 0-36 allowed
				std::cout << "On which number do you want to bet(0-36): " << std::endl;
				number = get_number();
				while (number < 0 || number > 36)
				{
					std::cout << "Only numbers between 0-36! " << std::endl;
					number = get_number();
				}

				std::cout << "Winning number is: " << winnumber << std::endl;

				// Do if won
				if (number == winnumber) {
					bet = bet + (bet * 35);
					money = bet + money;
					std::cout << "You won: " << bet << std::endl;
					std::cout << "Now you have " << money << " left" << std::endl;

				}
				// Do if lost
				else {
					money = money - bet;
					std::cout << "You lost and have " << money << " left!" << std::endl;
				}

				break;
				
			default:
				std::cout << "Sorry, that was not an available gamemode. You win or loose nothing! Try again!" << std::endl;
				break;
		}

		// Break loop if no money left
		if (money <= 0)
		{
			std::cout << "Sorry, you have no money left!" << std::endl;
			break;
		}

		// Optin want to play again?
		play = want_to_play(timesplayed);
		timesplayed++;
	}
}

void aufgabe2_4()
{
	// The more tests the closer to rand average...

	// Get amount of tests
	std::cout << "How many tests do you want to run?" << std::endl;
	int testamount = get_number();
	while (testamount < 1)
	{
		std::cout << "Cant run less than 1 tests..." << std::endl;
		testamount = get_number();
	}

	// Generate rand numbers for amount of tests and sum them to a total
	srand(time(NULL));
	int sum = 0;
	for (int i = 0; i < testamount; i++)
	{
		const int randnum = rand() % 10;
		std::cout << "Curr Num: " << randnum << std::endl;
		sum = sum + randnum;
	}

	// Calculate average: Sum / testamount
	const float average = (float)sum / (float)testamount;

	std::cout << "You made " << testamount << " tests in total" << std::endl;
	std::cout << "Your sum of all numbers was: " << sum << std::endl;
	std::cout << "Your average random number was: " << sum << " / " << testamount << " = " << average << std::endl;

}



int main() {

	// First hello world function
	/* const bool optin = want_to_play(0);

	if (optin != false)
	{
		// Roulette game with own entry for winning number
		// aufgabe2_1();
		// Roulette game with random winning number
		// aufgabe2_2();
		// Roulette game with different modes
		// aufgabe2_3();
	}*/

	aufgabe2_4();

	return 0;
}