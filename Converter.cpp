#include "Converter.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Converter::setRomanValues(string romanNumeral){
	originalRomanNumeral = romanNumeral; //store original value
	for (int i=0; i < romanNumeral.size(); i++){ //convert the roman numeral to a number and store it in a vector
		switch (romanNumeral.at(i)){
			case 'I' :
			individualNumbers.push_back(1);
			break;
			//
			case 'V' :
			individualNumbers.push_back(5);
			break;
			//
			case 'X' :
			individualNumbers.push_back(10);
			break;
			//
			case 'L' :
			individualNumbers.push_back(50);
			break;
			//
			case 'C' :
			individualNumbers.push_back(100);
			break;
			//
			case 'D' :
			individualNumbers.push_back(500);
			break;
			//
			case 'M' :
			individualNumbers.push_back(1000);
			break;	
		}	
	}
}

int Converter::solveRomanNumeral(string romanNumeral){
	int finalAnswer = 0;
	//compare the left and right numbers to see if they need to be added or subtracted.
	for (int i=individualNumbers.size()-1; i >= 0; i--){
		//need to subtract if B-A is positive
		if ((i != 0) && (individualNumbers.at(i)-individualNumbers.at(i-1) > 0) ){
			finalAnswer = finalAnswer + (individualNumbers.at(i) - individualNumbers.at(i-1));
			i--;//skip the subtracted value
		}
		else { //add
			finalAnswer = finalAnswer + individualNumbers.at(i);
		}
	}

	individualNumbers.clear();
	return finalAnswer;
}

void Converter::setModernNumbers(string modernNumber){
	originalModernNumber = modernNumber;		
}

string Converter::solveModernNumber(string modernNumber){
	int myNumber = stoi(modernNumber);
	string finalAnswer; 
	//check to see the greatest number that fits until myNumber is 0
	while (myNumber != 0){
		if (myNumber < 5){
			if (myNumber > 3){
				finalAnswer.append("IV");
				myNumber = myNumber - 4;
			}
			else {
				finalAnswer.append("I");
				myNumber = myNumber - 1;
			}
		}
		else if (myNumber < 10){
			if (myNumber > 8){
				finalAnswer.append("IX");
				myNumber = myNumber - 9;
			}
			else{
				finalAnswer.append("V");
				myNumber = myNumber - 5;
			}
		}
		else if (myNumber < 50){
			if (myNumber < 40){
				finalAnswer.append("X");
				myNumber = myNumber - 10;
			}
			else {
				finalAnswer.append("XL");
				myNumber = myNumber - 40;
			}
		}
		else if (myNumber < 100){
			if (myNumber < 90){
				finalAnswer.append("L");
				myNumber = myNumber - 50;
			}
			else {
				finalAnswer.append("XC");
				myNumber= myNumber - 90;
			}
		}
		else if (myNumber < 500){
			if (myNumber < 400){
				finalAnswer.append("C");
				myNumber = myNumber - 100;
			}
			else {
				finalAnswer.append("CD");
				myNumber = myNumber - 400;
			}
		}
		else if (myNumber < 1000){
			if (myNumber < 900){
				finalAnswer.append("D");
				myNumber = myNumber - 500;
			}
			else {
				finalAnswer.append("CM");
				myNumber = myNumber - 900;
			}
		}
		else{
			finalAnswer.append("M");
			myNumber = myNumber - 1000;
		}
	}
	return finalAnswer;
}

bool Converter::confirmRoman(string roman){
	bool response;
	for (int i=0; i < roman.size(); i++){
		if ((roman.at(i) != 'I') && (roman.at(i) != 'V') && (roman.at(i) != 'X') && (roman.at(i) != 'L') && (roman.at(i) != 'C') && (roman.at(i) != 'D') && (roman.at(i) != 'M')){
			response = false;
		}
		else {
			response = true;
		}
	}
	return response;
}

bool Converter::confirmNumber(string number){
	bool response;
	for (int i=0; i < number.size(); i++){
		if ((number.at(i) != '0') && (number.at(i) != '1') && (number.at(i) != '2') && (number.at(i) != '3') && (number.at(i) != '4') && (number.at(i) != '5') && (number.at(i) != '6') && (number.at(i) != '7') && (number.at(i) != '8') && (number.at(i) != '9')){
			response = false;
		}
		else {
			response = true;
		}
	}
	return response;
}