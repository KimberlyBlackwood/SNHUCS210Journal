// 07/23/2024 | Project one: Chada Tech
// This program outputs 2 clocks (12-hour and 24-hour) and allows the user to minipulate
// the clocks by adding increments of hours/minutes/seconds.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



// Declare a function for the clocks' borders
void printClockBorder() {
	for (int i = 0; i < 16; ++i) { // For loop that prints space padding
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) { // For loop that prints *'s for the 12 - hour clock border
		cout << "*";
	}
	for (int i = 0; i < 5; ++i) { // For loop that prints space padding between clocks
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) { // For loop that prints *'s for the 24 - hour clock border
		cout << "*";
	}
	cout << endl;
}



// Function that outputs both clocks and converts the 24-hour clock to 12-hour AM / PM clock
void printClocks(int hours, int minutes, int seconds) {
	// Necessary attributes used for the 12-hour conversion
	int hourConv; // Hour conversion
	int minConv; // Minute conversion
	int secConv; // Second conversion
	string amPm = "AM"; // AM or PM
	// Covert 24-Hour clock to 12-Hour AM/PM clock
	if (hours == 0) {
		hourConv = 12;
	}
	else if (hours == 12) {
		hourConv = hours;
		amPm = "PM";
	}
	else if (hours > 12) {
		hourConv = hours - 12;
		amPm = "PM";
	}
	else {
		hourConv = hours;
	}
	// Clock titles
	cout << "\t\t*\t" << "12-Hour Clock";

	cout << "\t *";
	cout << "\t*" << "\t24-Hour Clock";
	cout << "\t *" << endl;
	// 12-hour clock
	cout << "\t\t* \t ";
	cout << setw(2) << setfill('0') << hourConv << ":"; // formatted 12-hour clock
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << " " << amPm;
	cout << "\t *";
	// 24-hour clock
	cout << "\t*" << "\t ";
	cout << setw(2) << setfill('0') << hours << ":"; // formatted 24-hour clock
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << "\t *" << endl;
}



// Function that takes in the initial time from the user
void inputInitialTime(int& setHour, int& setMinute, int& setSecond) {
	string inputString; // Holds initial user input
	string tempString; // Used for user time input validation
	bool validTime = false; // Valid time toggle used for the while statement inputString
	int firstColonPosition;
	int secondColonPosition; // Used to find the 2nd colon in inputString


	while (!validTime) {
		cout << "Enter time as HH:MM:SS in 24-hour format: "; // Ask for user initial time input
		getline(cin, inputString); // Assign user input
		firstColonPosition = inputString.find(':');
		// Finds 1st colon
		secondColonPosition = inputString.find(':', firstColonPosition + 1);
		// Finds 2nd colon
		// Attempt to assign and convert each clock section only if they were integers, otherwise ignore
		try
		{
			setHour = stoi(inputString.substr(0, firstColonPosition));
			// Takes in the first section and converts it to an int
			setMinute = stoi(inputString.substr(firstColonPosition + 1,
				secondColonPosition)); // same as setHour

			setSecond = stoi(inputString.substr(secondColonPosition + 1,
				inputString.size() - 1)); // same as setHour
		}
		catch (const std::exception&)
		{
			// Not planning to do something with the exception in this program
		}
		if (inputString.size() != 8) { // Check if user entered the proper character length
			cout << "Time is invalid" << endl;
			!validTime;
		}
		else if (setHour < 0 || setHour > 23) { // Check if setHour is between 0 and 23
			cout << "Time is invalid" << endl;
			!validTime;
		}
		else if (setMinute < 0 || setMinute > 59) { // Check if setMinute is between 0 and 59
			cout << "Time is invalid" << endl;
			!validTime;
		}
		else if (setSecond < 0 || setSecond > 59) { // Check if setSecond is between 0 and 59
			cout << "Seconds are invalid" << endl;
			!validTime;
		}
		else {
			validTime = true; // Time is valid
		}
	}
}



// Main menu options function
void printMainMenu() {
	cout << endl;
	cout << "*********************************" << endl;
	cout << "* 1-Add One Hour\t\t*" << endl;
	cout << "* 2-Add One Minute\t\t*" << endl;
	cout << "* 3-Add One Second\t\t*" << endl;
	cout << "* 4-Exit\t\t\t*" << endl;
	cout << "*********************************" << endl;
	cout << endl;
}



// Function that takes in and validates user inputs
void processUserInput(int& userChoice, int& setHour, int& setMinute, int&
	setSecond) {
	cout << "Select option (1-4): "; // Ask user for option number
	// Verify user input is not other than an integer
	if (!(cin >> userChoice)) { // This statement ensures user only enters integers
		cin.clear();

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This ensures non-numerical values are ignored

		userChoice = 0;
	}
	// Utilize swich statement based on user's input
	switch (userChoice) {
	case 1:
		cout << "1 hour added" << endl;
		if (setHour < 23) { // Increments 1 hour until reaches 24
			++setHour;
		}
		else {
			setHour = 00; // Reset to 00 hour onces it reaches 24
		}
		break;
	case 2:
		cout << "1 minute added" << endl;
		if (setMinute < 59) { // Increments 1 minute until reaches 59
			++setMinute;
		}
		else {
			setMinute = 00; // Reset to 00 minute onces it reaches 59
		}
		break;
	case 3:
		if (setSecond < 59) { // Increments 1 second until reaches 59
			++setSecond;
		}
		else {
			setSecond = 00; // Reset to 00 second onces it reaches 59
		}
		break;
	case 4:
		cout << "Goodbye!" << endl;
		break;
	default:
		cout << "Invalid choice. Enter a number between 1-4..." << endl;
		cin.clear();
		break;
	}
}



int main() {
	// Declare global properties
	int userChoice = 0; // Initial user choice
	int setHour = 0; // The following attributes initialize the clocks to midnight
	int setMinute = 0;
	int setSecond = 0;
	// Ask user to enter the initial time
	inputInitialTime(setHour, setMinute, setSecond);

	// Enter program's while loop
	while (userChoice != 4)
	{
		printClockBorder(); // Clocks borders-top
		printClocks(setHour, setMinute, setSecond); // Prints both clocks
		printMainMenu(); // Prints main menu to minipulate clocks
		processUserInput(userChoice, setHour, setMinute, setSecond);
	
		
	}

	//printClockBorder(); // Clocks borders-top
	//printClocks(setHour, setMinute, setSecond); // Prints both clocks
	//printClockBorder(); // Clocks borders - bottom
	//printMainMenu(); // Prints main menu to minipulate clocks
	//processUserInput(userChoice, setHour, setMinute, setSecond); // Takes in an integer and modifies clock based on command


	return 0;
}






// Matt's Correction
/*
* firstColonPosition not defined in inputInitialTime()
* return 0 outside of main()
* "Program Loop" scope wrong
*
*
*
*/