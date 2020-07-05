#pragma once
#include <string>
using namespace std;

class Clock{
public:
	Clock();
	Clock(int, int, int);
	Clock(int, int, int, string);

	void timeDisplay();
	string set12(int& hour, int& minute, int& second, string& dayNight);
	string set24(int& hour, int& minute, int& second);
	void incrHour();
	void incrMin();
	void incrSec();
	string getDayNight();
	void setDayNight(string userDayNight);
	void clearScreen();
	bool checkInputs(int hour, int min, int sec, string nightDay);
	bool checkInputs(int hour, int min, int sec);



private:
	void printTime(bool);
	int hr;
	int min;
	int sec;
	string dayNight;

};

