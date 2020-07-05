#pragma once
#include <stdlib.h>
#include <string>
#include "Clock.h"
#include <iostream>
using namespace std;

//Constructors __________________________________________________________________
	//default constructor
Clock::Clock() {
	hr = 0;
	min = 0;
	sec = 0;
}
	//24 hr constructor
Clock::Clock(int userHr, int userMin, int userSec) {
	if (checkInputs(userHr, userMin, userSec)) {
		hr = userHr;
		min = userMin;
		sec = userSec;
	}
	else
	{
		exit(EXIT_FAILURE);
	}

}
	//12 hr constructor
Clock::Clock(int userHr, int userMin, int userSec, string userDayNight) {

	if (checkInputs(userHr, userMin, userSec, userDayNight)) {
		hr = userHr;
		min = userMin;
		sec = userSec;
		if (userDayNight == "Am" || userDayNight == "aM" || userDayNight == "am" || userDayNight == "AM") {
			dayNight = "AM";
		}
		else if (userDayNight == "Pm" || userDayNight == "pM" || userDayNight == "pm" || userDayNight == "PM") {
			dayNight = "PM";
		}
		else {
			incrHour();
		}
	}
	else {
		exit(EXIT_FAILURE);
	}


}
//________________________________________________________________________________


//Time display methods____________________________________________________________
void Clock::timeDisplay() {

	if (dayNight.empty()) {
		// 24 hour time display
		for (int i = 0; i < 26; i++) {
			cout << "*";
		}
		cout << endl;
		for (int j = 0; j < 2; j++)
		{
			for (int l = 0; l < 1; l++) {
				cout << "*";
			}
			for (int x = 1; x < 25; x++) {
				if (x == 7 && j == 0) {
					cout << "24-Hour Clock";
					x += 12;
				}
				else if (x == 9 && j == 1) {
					printTime(false);
					x += 7;
				}
				else {
					cout << " ";
				}
			}
			cout << "*" << endl;
		}
		for (int i = 0; i < 26; i++) {
			cout << "*";
		}
	}
	else if (dayNight == "PM" || dayNight == "AM") {
		for (int i = 0; i < 26; i++) {
			cout << "*";
		}
		cout << endl;
		for (int j = 0; j < 2; j++)
		{
			for (int l = 0; l < 1; l++) {
				cout << "*";
			}
			for (int x = 1; x < 25; x++) {
				if (x == 7 && j == 0) {
					cout << "12-Hour Clock";
					x += 12;
				}
				else if (x == 8 && j == 1)
				{

					printTime(true);
					cout << " " << dayNight;
					x += 10;
				}
				else {
					cout << " ";
				}
			}
			cout << "*" << endl;
		}
		for (int i = 0; i < 26; i++) {
			cout << "*";
		}


	}

}
void Clock::printTime(bool is12hr) {
	if (is12hr) {
		set12(hr, min, sec, dayNight);
	}
	else {
		set24(hr, min, sec);
	}

};
string Clock::set12(int& hour, int& minute, int& second, string& dayNight) {
	// ignore this function for now will work on doing it with loops instead of switch
	if (hour > 12) {
		switch (hour) {
		case 13:
			return "01:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 14:
			return "02:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 15:
			return "03:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 16:
			return "04:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 17:
			return "05:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 18:
			return "06:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 19:
			return "07:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 20:
			return "08:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 21:
			return "09:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 22:
			return "10:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 23:
			return "11:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;
		case 0:
			return "12:" + to_string(minute) + ":" + to_string(second) + " PM";
			break;

		}

	}
	else if (hour > 0 && hour < 12) {
		return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second) + " " + dayNight;
	}

}
string Clock::set24(int& hour, int& minute, int& second) {
	for (int i = 0; i <= 24; i++) {
		if (i == hour) {
			if (i < 12) {
				return "0" + to_string(i) + ":" + to_string(minute) + ":" + to_string(second);
			}
			else if (i < 24 && i > 12) {
				return to_string(i) + ":" + to_string(minute) + ":" + to_string(second);
			}
		}
	}

}
//________________________________________________________________________________


//Increment time methods__________________________________________________________
void Clock::incrHour()
{
	hr++;
}
void Clock::incrMin()
{
	min++;
}
void Clock::incrSec()
{
	sec++;
}
//________________________________________________________________________________


//Getter and setter_______________________________________________________________
string Clock::getDayNight()
{
	return dayNight;
}
void Clock::setDayNight(string userDayNight) {
	dayNight = userDayNight;
}
//________________________________________________________________________________


//input validation and clear screen_______________________________________________
void Clock::clearScreen() {
	system("CLS");
}
//229 and 262 are both private members
bool Clock::checkInputs(int hour, int min, int sec, string nightDay) {
	bool check1;
	bool check2;
	bool check3;

	if (0 <= hour <= 12) {
		check1 = true;
	}
	else {
		check1 = false;
	}
	if (0 <= min <= 59 && 0 <= sec <= 59) {
		check2 = true;
	}
	else {
		check2 = false;
	}
	if (nightDay == "AM" || nightDay == "PM" || nightDay == "am" || nightDay == "pm" ||
		nightDay == "aM" || nightDay == "pM" || nightDay == "Am" || nightDay == "Pm") {
		check3 = true;
	}
	else {
		check3 = false;
	}

	if (check1 && check2 && check3) {
		return true;
	}
	else {
		return false;
	}

}
bool Clock::checkInputs(int hour, int min, int sec) {
	bool check1;
	bool check2;
	bool check3;

	if (0 <= hour <= 24) {
		check1 = true;
	}
	else {
		check1 = false;
	}
	if (0 <= min <= 59 && 0 <= sec <= 59) {
		check2 = true;
	}
	else {
		check2 = false;
	}
	if (check1 && check2) {
		return true;
	}
	else {
		return false;
	};
}
//________________________________________________________________________________


