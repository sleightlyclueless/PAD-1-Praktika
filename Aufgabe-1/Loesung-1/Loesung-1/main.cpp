// Import necessary libs for C++ functions
#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>

#include <array>

// Console break function - just cout two breaks
void console_break() {
	std::cout << std::endl << std::endl;
}

// Function to get only digits on cin inputs
int get_number() {
	// Problem: Before cin int input like 10f3r5 resulted in 10 - break after the letter. Could lead to unwanted results.
	// Therefore check and only accept digit entries.

	// Initialize necessary vars
	std::string str;
	int a;

	// Read whole input cin into string var first, because here it does not break after letters
	while (getline(std::cin, str))
	{
		// Search if there is an unwanted char in string.
		// size_t can store up to max size of an object - if we do not find an unaccepted char it becomes -1 or npos (18446744073709551615 == -1)
		auto const flag = str.find_first_not_of("-0123456789");

		// npos is type size_t and cant be negative therefore it takes on the value of the highest possible number. If that is the case we have an accepted integer input
		if (flag == std::string::npos)
		{
			// Success - valid int - transform to int
			a = stoi(str);
			std::cout << "Your int var is: " << a;
			console_break();
			// If we found an fitting int - exit the whole while loop - we are done here
			break;
		}

		std::cout << "Error, enter only valid int numbers. Please try again!" << std::endl;
	}

	// When we exited the while loop we found an int var. Go ahead and return that to the function call.
	return a;
}

// Recursive function to do factorial calc with for loop
int factorial(const int n)
{
	int fac = 1;
	if (n != 0)
	{
		for (int i = 1; i <= n; i++) {
			fac *= i;
		}
	}
	return fac;
}


// Aufgabe 1.1 - First hello world function
void aufgabe1_1()
{
	// First command output
	std::cout << "Hello Sebastian - this is your first C++ function";
	console_break();
}

// Aufgabe 1.2 - Get int input and transform to chars
void aufgabe_1_2()
{
	// User instructions
	std::cout << "First input handling function. Transform int to char." << std::endl << "Please enter an integer number for the function to handle." << std::endl;

	// Call get a number function from cin
	int a = get_number();
	// int a;
	// cin >> a;

	while (a < 0 || a > 255)
	{
		std::cout << "Please enter a number between 0 and 255 - this is how many ASCII Chars exist." << std::endl;
		a = get_number();
	}

	const char c = static_cast<char>(a);

	// That's because -16 is the same as hex 0xf0 which is the same as 240
	// Output var versions
	console_break();
	std::cout << "==================================" << std::endl;
	std::cout << "Your var as int typeof: " << typeid(a).name() << std::endl << "Value: " << a << std::endl;
	std::cout << "Your var as char typeof: " << typeid(c).name() << std::endl << "Value: " << c << std::endl;
}

// Aufgabe 1.3 - Function for basic calculations of n and m
void aufgabe1_3()
{
	// pre create necessary int and float vars for future calculation (float cause possible commas in division result)
	float result;

	// explanation for program to the user
	std::cout << "Calculate 2 integers n and m with one another.";
	console_break();

	// get var n for calculations
	std::cout << "Please enter an integer variable for n." << std::endl;
	int n = get_number();

	// get var m for calculations
	std::cout << "Please enter the second integer variable for m." << std::endl;
	int m = get_number();

	std::cout << "Calculations start" << std::endl;
	std::cout << "==================================" << std::endl;

	// calculate results and put it into console for the user
	result = n + m;
	std::cout << "Plus: " << n << " + " << m << " = " << result << std::endl;

	result = n - m;
	std::cout << "Minus: " << n << " - " << m << " = " << result << std::endl;

	result = n * m;
	std::cout << "Multiplication: " << n << " * " << m << " = " << result << std::endl;

	// handle exception if we want to divide by 0
	if (m == 0)
	{
		std::cout << "Cant divide or modulo by zero!" << std::endl;
	}
	else
	{
		result = (float)n / (float)m;
		std::cout << "Division: " << n << " / " << m << " = " << result << std::endl;

		result = n % m;
		std::cout << "Modulo: " << n << " / " << m << " = " << result << std::endl;
	}
}

// Aufgabe 1.4 - Function to calculate int to its same square
void aufgabe1_4()
{
	// explanation for program to the user
	std::cout << "This function will give the square of two for each second number from 1 to n or from n to -1." << std::endl;
	std::cout << "Please enter an integer variable for n." << std::endl;

	// initialize vars
	int n = get_number();


	// zero not accepted
	while (n == 0)
	{
		std::cout << "There are no square calculations from 0 to 0. Please enter another number." << std::endl;
		n = get_number();
	}


	// if n is positive we count from 1 to n
	if (n > 0)
	{
		// Solution with for-loop
		std::cout << "Solution with for-loop" << std::endl;
		// TODO Simpler i + 2
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				std::cout << "Result for number " << i << ": " << i * i << std::endl;
			}
			else if ((i % 2) != 0)
			{
				std::cout << "Result for number " << i << ": " << i * i << std::endl;
			}
		}

		std::cout << "==================================";
		console_break();


		// solution with while-loop
		std::cout << "Solution with while-loop" << std::endl;
		int while_counter = 1;

		while (while_counter <= n)
		{

			if (while_counter == 1)
			{
				std::cout << "Result for number " << while_counter << ": " << while_counter * while_counter << std::endl;
			}
			else if ((while_counter % 2) != 0)
			{
				std::cout << "Result for number " << while_counter << ": " << while_counter * while_counter << std::endl;
			}

			while_counter++;
		}

		std::cout << "==================================";
		console_break();


		// Solution with do-while-loop
		std::cout << "Solution with do-while-loop" << std::endl;
		int do_while_counter = 1;

		do
		{
			if (do_while_counter == 1)
			{
				std::cout << "Result for number " << do_while_counter << ": " << do_while_counter * do_while_counter << std::endl;
			}
			else if ((do_while_counter % 2) != 0)
			{
				std::cout << "Result for number " << do_while_counter << ": " << do_while_counter * do_while_counter << std::endl;
			}

			do_while_counter++;
		} while (do_while_counter <= n);

		std::cout << "==================================";
		console_break();

	}
	else

		// Nagative ints? -> Bonus Solution: If n is negative we count the other way around from -n to -1
	{
		// Solution with for loop
		for (int i = n; i <= -1; i++)
		{
			if (i == -1)
			{
				std::cout << "Result for number " << i << ": " << i * i << std::endl;
			}
			else if ((i % 2) != 0)
			{
				std::cout << "Result for number " << i << ": " << i * i << std::endl;
			}
		}

		std::cout << "==================================";
		console_break();


		// solution with while-loop
		std::cout << "Solution with while-loop" << std::endl;
		int while_counter = n;

		while (while_counter <= -1)
		{

			if (while_counter == -1)
			{
				std::cout << "Result for number " << while_counter << ": " << while_counter * while_counter << std::endl;
			}
			else if ((while_counter % 2) != 0)
			{
				std::cout << "Result for number " << while_counter << ": " << while_counter * while_counter << std::endl;
			}

			while_counter++;
		}

		std::cout << "==================================";
		console_break();


		// Solution with do-while-loop
		std::cout << "Solution with do-while-loop" << std::endl;
		int do_while_counter = n;

		do
		{
			if (do_while_counter == -1)
			{
				std::cout << "Result for number " << do_while_counter << ": " << do_while_counter * do_while_counter << std::endl;
			}
			else if ((do_while_counter % 2) != 0)
			{
				std::cout << "Result for number " << do_while_counter << ": " << do_while_counter * do_while_counter << std::endl;
			}

			do_while_counter++;
		} while (do_while_counter <= -1);

		std::cout << "==================================";
		console_break();
	}

	std::cout << "End of for loop solutions and function.";
	console_break();
}

// Bonus-Aufgabe 1.5 Bonus function binomial coefficient
void aufgabe1_5() {

	// Initialize flag for getting our int vars n and k with both not bigger than 12 or smaller than 1
	bool pass = false;
	int n, k;

	// Get first variable n with n > 0 and n<=12
	std::cout << "Please enter your first int variable n for binomial coefficient calculation. Please pay in mind that it cant be bigger than 12 due to the limits of integers." << std::endl;
	while (pass == false)
	{
		n = get_number();

		if (n >= 1 && n <= 12)
		{
			pass = true;
		}
		else
		{
			std::cout << "Pay in mind: n has to be n > 0 and n<=12. Please try again!" << std::endl;
		}
	}

	// Reset flag for getting the second var and using it again
	pass = false;

	// Get second var k with k > 0 k<=12 and n>=k
	std::cout << "Please enter your second int variable k for binomial coefficient calculation. Please pay in mind the above stated conditions and that n has to be bigger than k." << std::endl;
	while (pass == false)
	{
		k = get_number();

		if (k >= 1 && k <= 12)
		{
			if (n >= k)
			{
				pass = true;
			}
		}

		if (pass == false)
		{
			std::cout << "Pay in mind: k has to be k > 0 and k<=12, as well as n>=k with n being " << n << std::endl << "Please try again!" << std::endl;
		}
	}

	int const fact_n = factorial(n);
	int const fact_k = factorial(k);
	int const fact_n_minus_k = factorial(n - k);

	std::cout << "==================================" << std::endl
	<< "Here are our variables:" << std::endl
	<< "n = " << n << std::endl
	<< "k = " << k << std::endl
	<< "fact_n = " << fact_n << std::endl
	<< "fact_k = " << fact_k << std::endl
	<< "fact_n_minus_k = " << fact_n_minus_k << std::endl
	<< "==================================" << std::endl
	<< "Binomial coefficient: " << fact_n / (fact_k * fact_n_minus_k);

	console_break();
}


int main() {

	// First hello world function
	// aufgabe1_1();

	// Get int input and transform to chars
	// aufgabe_1_2();

	// Function for basic calculations of n and m
	// aufgabe1_3();

	// Function to calculate int to its same square
	// aufgabe1_4();

	// Bonus function binomial coefficient
	// aufgabe1_5();

	return 0;
}
