#include <iostream>
#include <string>
#include <sstream>
// Aufgabe 3.2 +
#include <array>
// Aufgabe 3.3 +
#include <vector>
#include <time.h>


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
			// If you accidently just hit enter the first time give error and start over
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


// Aufgabe 3.1
void encrypt_caesar_chiffre()
{
	
	// Get Caesar index
	std::cout << "Bitte geben Sie den Chiffren-Schlüssel ein" << std::endl;
    int verschiebung = get_number();
    while (verschiebung < 1 || verschiebung > 25) {
		std::cout << "Max 25 bitte (Alphabet)" << std::endl;
		verschiebung = get_number();
    }

	// Get amount of words
	std::cout << "Bitte geben Sie eine Anzahl an Worten ein, die verschlüsselt werden sollen" << std::endl;
	int menge = get_number();
	while (menge < 1) {
		std::cout << "Min. 1 Wort" << std::endl;
		menge = get_number();
	}

	std::string chiffretext;

	// Encrypt
	for (int words = 0; words < menge; words++)
	{
		// Get plain text
		std::cout << "Bitte geben sie ein Wort ein (max. 10 Buchstaben)" << std::endl;
		char input[10];
		std::cin >> input;

		int losung[10];

		std::cout << "Ihr Wort in Caesa Chiffre: ";
		for (int i = 0; i < 10; i++) {

			// Convert to lowercase
			input[i] = tolower(input[i]);

			// Duplicate Char Array with integers for conversion
			losung[i] = input[i] + verschiebung;
			
			// If number over 122 we passed the end of the alphabet for the char -> Start over
			if (losung[i] > 122) {
				input[i] = losung[i] - 26;
			}
			else {
				input[i] = losung[i];
			}

			// End encryption for this word if no following letter exists
			if (input[i] < 97 || input[i] > 122) {
				input[i] = ' ';
				chiffretext += input[i];
				break;
			}

			std::cout << input[i];
			chiffretext += input[i];

		}
		std::cout << std::endl << std::endl;

	}
	
	std::cout << "Alles zusammen in Caesa Chiffre: " << chiffretext << std::endl;
}


// Aufgabe 3.1
void decrypt_caesar_chiffre()
{

	// Decrypt
	for (int verschiebung = 1; verschiebung < 27; verschiebung++)
	{
		std::cout << "Verschiebung für: " << verschiebung << std::endl;
		
		for (int i = 0; i < 27; i++) {
			
			char input[27] = { 'd','q','m','t',' ','m','z','n','w','t','o',' ','j','m','q',' ','l','m','z',' ','s','t','i','c','a','c','z' };
			int losung[27];
			
			if (input[i] != ' ')
			{
				// Duplicate Char Array with integers for conversion
				losung[i] = input[i] - verschiebung;

				// If number under 97 we passed the end of the alphabet for the char -> Start over
				if (losung[i] < 97) {
					losung[i] = losung[i] + 26;
				}

			}
			else
			{
				losung[i] = input[i];
			}

			input[i] = losung[i];
			std::cout << input[i];

		}
		
		std::cout << std::endl << std::endl;
	}
	
	// Viel Erfolg bei der Klausur (8)
}


// Aufgabe 3.2
void sieb()
{
	
	// TODO: ANsatz mit Wurzeln
	// Get amount of numbers
	std::cout << "Bitte geben Sie eine Zahl ein um zu gucken, welche Primzahlen in dieser enthalten sind." << std::endl;
	const int n = get_number();
	
	// We have to write nums into array (instead of vector). This initialize, however is illegal:
	// std::array<int, mysize> zahlen;
	// Need to use a parameter to specify the size of an dynamic array
	int *zahlen = new int[n];

	// Write nums into array
	for (int z = 0; z < n; z++) {
		zahlen[z] = z+1;
	}
	zahlen[0] = -1;
	
	// Calculate all prime numbers
	for (int i = 0; i < n; i++) {
		for (int r = i; r > 0; r--) {
			if (zahlen[i] != zahlen[r] && zahlen[r] != -1) {
				if (zahlen[i] % zahlen[r] == 0) {
					zahlen[i] = -1;
					break;
				}
			}
		}
	}

	// Output all prime numbers
	std::cout << "Die Zahl " << n << " enthält die folgenden Primzahlen: ";
	for (int l = 0; l < n; l++) {
		if (zahlen[l] != -1) {
			std::cout << zahlen[l] << ", ";
		}
	}
	std::cout << std::endl;

	// Free array again
	delete[] zahlen;

}


// Aufgabe 3.3
void sumsortVecs()
{
	
	// Vecs for rnums
	std::vector<int> first;
	std::vector<int> second;
	// TODO: Magic numbers vermeiden (vectorsize verwenden) -> 4. Praktikum wichtig
	
	srand(time(NULL)); // Seed for random nums
	
	int sorted[200]; // Array for sortednums
	

	// Fill vectors with rand nums
	for (int i = 0; i <= 99; i++) {
		int random;
		random = rand() % 1000;
		first.push_back(random);
		random = rand() % 1000;
		second.push_back(random);
	}
	
	// Fill array with vectors
	for (int a = 0; a <= 199; a++)
	{
		// Initialize vars for first vector element for comparison
		int pointer_first = 0;
		int pointer_second = 0;
		int counter = 0;
		bool empty_first = false;
		bool empty_second = false;

		// Need empty flags, because when one vector is empty we cant compare with those vector elements anymore
		if (first.empty())
		{
			empty_first = true;
		}
		if (second.empty())
		{
			empty_second = true;
		}
	
		// Get smallest element and its position from first vector
		if (empty_first == false)
		{
			for (const int& b : first)
			{
				// TODO .at() statt first[] verwenden -> exception handling
				if (b < first[pointer_first])
				{
					pointer_first = counter;
				}
				counter++;
			}
		}

		// Get smallest element and its position from second vector
		if (empty_second == false)
		{
			counter = 0;
			for (const int& c : second)
			{
				if (c < second[pointer_second])
				{
					pointer_second = counter;
				}
				counter++;
			}
		}

		// Exceptions if one vector is empty, we cant compare the elements anymore - unexpected behaviour!
		// For the last elements in only one vector dont compare with the empty vector anymore - just enter the smallest determined element from remainings
		if (empty_first == true)
		{
			sorted[a] = second[pointer_second];
			second.erase(second.begin() + pointer_second);
			continue;
		}
		if (empty_second == true)
		{
			sorted[a] = first[pointer_first];
			first.erase(first.begin() + pointer_first);
			continue;
		}
		
		// Compare elements and write into array at cur position a, then remove them from vector
		if (first[pointer_first] < second[pointer_second])
		{
			sorted[a] = first[pointer_first];
			first.erase(first.begin() + pointer_first);
		}
		else if (second[pointer_second] < first[pointer_first])
		{
			sorted[a] = second[pointer_second];
			second.erase(second.begin() + pointer_second);
		}
		// If both elements are the same write both into array at array[a] and array[a+1], then remove both
		else
		{
			sorted[a] = first[pointer_first];
			sorted[a + 1] = second[pointer_second];
			first.erase(first.begin() + pointer_first);
			second.erase(second.begin() + pointer_second);
			a++;
		}
		
	}

	// Cout sorted and summed array
	for (const int& el : sorted) {
		std::cout << el << std::endl;
	}
	
}


// Aufgabe 3.4
std::vector<int> bubbleSort(std::vector<int> vector)
{
	const int n = vector.size();
	
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j>=i; j--)
		{
			if (vector[j-1] > vector[j])
			{
				int tmp = vector[j - 1];
				vector[j - 1] = vector[j];
				vector[j] = tmp;
			}
		}
	}

	return vector;
}


// Aufgabe 3.4
void sumsortpresortedVecs()
{
	
	// Vecs for rnums
	std::vector<int> first;
	std::vector<int> second;

	srand(time(NULL)); // Seed for random nums

	int sorted[200]; // Array for sortednums
	

	// Fill vectors with rand nums
	for (int i = 0; i <= 99; i++) {
		int random;
		random = rand() % 1000;
		first.push_back(random);
		random = rand() % 1000;
		second.push_back(random);
	}
	
	// Sort arrays
	std::vector<int> firstsorted = bubbleSort(first);
	std::vector<int> secondsorted = bubbleSort(second);

	
	// Fill array with sorted vectors
	for (int a = 0; a <= 199; a++)
	{
	
		if (firstsorted.empty())
		{
			sorted[a] = secondsorted[0];
			secondsorted.erase(secondsorted.begin());
			continue;
		}
		if (secondsorted.empty())
		{
			sorted[a] = firstsorted[0];
			firstsorted.erase(firstsorted.begin());
			continue;
		}
		
		// Compare elements and write into array at cur position a, then remove them from vector
		if (firstsorted[0] < secondsorted[0])
		{
			sorted[a] = firstsorted[0];
			firstsorted.erase(firstsorted.begin());
		}
		else if (secondsorted[0] < firstsorted[0])
		{
			sorted[a] = secondsorted[0];
			secondsorted.erase(secondsorted.begin());
		}
		// If both elements are the same write both into array at array[a] and array[a+1], then remove both
		else
		{
			sorted[a] = firstsorted[0];
			sorted[a + 1] = secondsorted[0];
			firstsorted.erase(firstsorted.begin());
			secondsorted.erase(secondsorted.begin());
			a++;
		}
		
	}

	// Cout sorted and summed array
	std::cout << "===========================" << std::endl;
	for (const int& el : sorted) {
		std::cout << el << std::endl;
	}
	
}



int main()
{
	setlocale(LC_ALL,"");

	// Aufgabe 3.1
	// encrypt_caesar_chiffre();
	// decrypt_caesar_chiffre();

	// Aufgabe 3.2
	// sieb();

	// Aufgabe 3.3
	// sumsortVecs();

	// Aufgabe 3.4
	// sumsortpresortedVecs();
	
    return 0;
}