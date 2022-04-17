/*************************************************
* 
*
* 
*Michael Burkhardt 937645
* 
* Der erste uebergabeparameter muss eine Zahl sein, danach eine Zeichenfolge
* Ich habe fuer Anforderung 13 Ctime benutzt, daher sind Daten vor 1970 nicht moeglich
* 
* 
* 
* ************************************************
*/


#include "main.h"
#include "Labor1.h"
#include <vector>
#include <String>
#include <iostream>
#include <cmath>
#include <fstream>
#include <exception>
#include <cstdio>
#include <cassert>






int main(int argc, char** argv)
{

	// Anforderung 1
	
	std::vector<std::string> argument;
	for (int i{ 0 }; i < argc; i++) {
		
		argument.push_back(argv[i]);
		// std::cout << argv[i] << std::endl;
	}

	for (auto& a : argument){
		std::cout << a << std::endl;
		}


	// Anforderung 2
	double anforderung2;
	anforderung2 = std::stod(argv[1]); 
	


	// Anforderung3
	weitereFunktionalitaeten::printText();

	// Anforderung 4
	double ergebnisAnforderung4;
	ergebnisAnforderung4 = sin(anforderung2);
	std::cout << "Das Ergebnis zu Anforderung 4 ist: " << ergebnisAnforderung4 << std::endl << std::endl;


	// Anforderung 5
	// C-Like
	int x{ (int)ergebnisAnforderung4 };
	//functional
	int y{ int(ergebnisAnforderung4) };

	// Anforderung 6/18

	x = weitereFunktionalitaeten::multiply(10,10);
	weitereFunktionalitaeten::addTen(x);
	std::cout << "Das Ergebnis von Anforderung 6 ist: " << x << std::endl << std::endl;



	// Anforderung 7
	std::cout << "Variable x = " << x <<  " in hex ist: " << std::hex << x << std::endl << std::endl;

	// Anforderung 8 ist in Labor1.h

	// Anforderung 9
	std::vector<Person> Personen;

	// Anforderung 10 & 11
	
	std::ifstream Datei;
	try {
		
		Datei.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		Datei.open("Text.txt");
		weitereFunktionalitaeten::readData(Personen, Datei);
		Datei.close();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
		//assert(!Datei);
		
	
		

	
	// Anforderung 12 -- Nach erneutem Programmaufruf funktioniert Anforderung 10 nicht mehr, da der Dateiname geaendert wurde
	std::string textdatei = "Text.txt";
	std::string neuerNameTeil1{ "C:\\Users\\Micha\\Desktop\\4. Semester\\C++\\Labor\\Labor1\\Labor1\\" };
	std::string neuerNameTeil2(argv[2]);
	std::string neuerNameTeil3{".txt"};

	std::string neuerName{ neuerNameTeil1 + neuerNameTeil2 + neuerNameTeil3};
	std::string alterName = "C:\\Users\\Micha\\Desktop\\4. Semester\\C++\\Labor\\Labor1\\Labor1\\" + textdatei;
	//weitereFunktionalitaeten::renameFile(alterName, neuerName);
	//Auskommentiert, da ich sonst bei jedem Testen die Datei wieder umbenennen muss


	
	// Anforderung 13
	weitereFunktionalitaeten::berechnungAlter(Personen);

	// Anforderung 14
	weitereFunktionalitaeten::ausgabeAltertext(Personen);



	
	
	
		
	
	






	






	


	
	std::cout << "Ende" << std::endl;
	return 0;
}
