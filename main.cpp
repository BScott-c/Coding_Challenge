#include <iostream>
#include <string>
#include "Converter.h"
using namespace std;

int main() {
	string conversionType;
	string input;
	Converter toBeConverted;
	bool romanToModern;
	cout << "Welcome to the Roman Numeral Conversion Tool." << endl << endl;
	
	cout << "Enter \"R\" to convert a roman numeral to a modern number. Enter \"M\" to convert a modern number to a roman numeral. Enter \"Q\" to quit" << endl;

	getline(cin, conversionType);

	while (conversionType != "Q"){
		if (conversionType == "R" || conversionType == "r"){
			cout << "Please enter your roman numeral to be converted to a modern number:" << endl;
			getline (cin, input);

			//check input
			if (toBeConverted.confirmRoman(input) == false){
				cout << "I'm sorry, that isn't a valid roman numeral. Please try again." << endl;
			}
			else { //solve 
				toBeConverted.setRomanValues(input);
				cout << toBeConverted.solveRomanNumeral(input) << endl;
			}
		}
		else if (conversionType == "M" || conversionType == "m"){
			cout << "Please enter your modern number to be converted to a roman numeral:" << endl;
			getline (cin, input);
			//check input
			if (toBeConverted.confirmNumber(input) == false){
				cout << "I'm sorry, that isn't a valid  number. Please try again." << endl;
			}
			else { //solve
				toBeConverted.setModernNumbers(input);
				cout << toBeConverted.solveModernNumber(input) << endl;
			}
		}
		else {
			cout << "I'm sorry, I don't recognize that command." << endl; 
		}

		cout << "Enter \"R\" to convert a roman numeral to a modern number. Enter \"M\" to convert a modern number to a roman numeral. Enter \"Q\" to quit" << endl;

		getline(cin, conversionType);

	}
	

	return 0;
}