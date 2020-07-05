#include "functions.h"
#include <iostream>
#include <string>

int main() {

	Clock myClock12hr = Clock(15, 23, 20, "pm");
	Clock myClock24hr = Clock(15, 23, 20);


	myClock12hr.timeDisplay();
	myClock24hr.timeDisplay();

	return 0;
}