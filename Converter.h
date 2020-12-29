#pragma once
#include <string>
#include <vector>
using namespace std;

class Converter {
	private:
		string originalRomanNumeral;
		string originalModernNumber;
		vector<int> individualNumbers; //stores the parsed roman numeral
		
	public:
		//parse the roman numeral and convert it to numbers
		void setRomanValues(string romanNumeral);

		//convert the roman numeral to a number
		int solveRomanNumeral(string romanNumeral);

		//store the original modern number
		void setModernNumbers(string modernNumbers);

		//convert the number to a roman numeral
		string solveModernNumber(string modernNumber);

		//check to make sure a roman numeral was entered
		bool confirmRoman(string roman);

		//check to make sure that a number was entered
		bool confirmNumber(string number);

};