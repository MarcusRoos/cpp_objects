//##############################################################################
// Filnamn: TestTimer.cpp
// Skrivit av : Mikael Nilsson
// Justerad av: Per Ekeroot 2012-02-07
//              Erik Strom 2019-12-22 (adjustements)
// Skapat datum: 2011-08-03
//##############################################################################

//===< include >================================================================
#include "Timer.h"
#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;
/*
int main(int argc, const char* argv[]) {
	Timer timer{};                          // Skapa ett Timer-objekt

	timer.start();                          // Starta tidtagningen
	cout << "Tryck ENTER!!" << endl;
	string s;
	while(!getline(cin, s));        // Vänta på att användaren trycker på ENTER
	cout << fixed << setprecision(6);

	cout << "Tid = "    // Läs av stopptiden och beräkna skillnaden till starttiden
	    << timer.stop() / 1000000
	    << " [s]" <<  endl;
	return 0;
}*/
