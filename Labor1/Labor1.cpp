#include "Labor1.h"

void weitereFunktionalitaeten::printText() {
	std::cout << "Anforderung 3 hoffentlich erfuellt" << std::endl << std::endl;
}
void weitereFunktionalitaeten::addTen(int &a) {
	a += 10;
	
}

auto weitereFunktionalitaeten::multiply(const int a, const int b ) -> int {
	int c = a * b;
	return c;
 };







void weitereFunktionalitaeten::readData(std::vector<Person> &Personen, std::ifstream &D) {
	
	
	while (!D.eof()) {
		Person p;
		for (size_t i = 0; i < 3; i++) {
			std::string s;
			D >> s;
			p.Vorname = s;
			D >> s;
			p.Nachname = s;
			D >> s;
			p.Geburtstag = s;
			Personen.push_back(p);
		}
	}

};

void weitereFunktionalitaeten::renameFile( std::string &a, std::string &b) {
	
	if (rename(a.c_str(), b.c_str()) != 0) {
		std::cout << "Konnte Datei nicht umbenennen" << std::endl;
	}
	else {
		std::cout << "Die Datei wurde umbenannt" << std::endl;
	}
}
void weitereFunktionalitaeten::berechnungAlter(std::vector<Person> &Persons)
{
	// heute
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	
	for (size_t i = 0; i < Persons.size(); i++ ) {
		// Geburtstag aus Struct
		std::tm y = {};
		std::istringstream date(Persons[i].Geburtstag);

		date >> std::get_time(&y, "%d.%m.%Y");
		
		//Wandle beide Formate in time_t um
		std::time_t time1 = std::mktime(now); // 31556952 Sekunden pro Jahr
		std::time_t time2 = std::mktime(&y);
		//Berechnung der Werte
		Persons[i].alterInTagen = difftime(time1, time2) / 86400;
		Persons[i].alterInStunden = difftime(time1, time2) / (60 * 60);
		Persons[i].alterInJahren = difftime(time1, time2) / (60 * 60 * 24 * 365);
		//Ausgabe
		std::cout << Persons[i].Vorname << " ist " << std::fixed << std::setprecision(1) << Persons[i].alterInTagen << " Tage, " << Persons[i].alterInStunden << " Stunden und "
		<< Persons[i].alterInJahren << " Jahre alt." << std::endl << std::endl;
		// Anmerkung
		
	}
}
void weitereFunktionalitaeten::ausgabeAltertext(std::vector<Person>& Persons )
{	//Aller...
	std::vector<std::string> textAlterEinser{ "null","ein", "zwei", "drei","vier","fuenf","sechs","sieben","acht","neun","zehn", "elf", "zwoelf" };
	std::vector<std::string> textAlterZehner{ "nullig", "zehn", "zwanzig", "dreissig", "vierzig", "fuenfzig", "sechzig", "siebzig", "achzig", "neunzig", "hundert" };
	std::string fueller = "und";

	for (size_t i = 0; i < Persons.size(); i++) {
		// um die einzelnen Stelle zu bekommen
		int zehner = Persons[i].alterInJahren / 10;
		int einser = Persons[i].alterInJahren;
		einser = einser % 10;
		
		std::string first;
		std::string last;
		
		first = textAlterZehner[zehner];
		last = textAlterEinser[einser];
		

		if (einser == 1 && zehner == 1) {
			std::cout << Persons[i].Vorname << " ist " << textAlterEinser[11] << " Jahre alt." <<  std::endl;
		}
		else if (einser == 2 && zehner == 1) {
			std::cout << Persons[i].Vorname << " ist " << textAlterEinser[12] << " Jahre alt." << std::endl;
		}
		else if (einser == 0) {
			std::cout << Persons[i].Vorname << " ist " << first << " jahre alt." << std::endl;

		}
		else if (einser == 1 && zehner == 0) {
			std::cout << Persons[i].Vorname << " ist " << last << " jahr alt." << std::endl;
		}
		else {
			std::cout << Persons[i].Vorname << " ist " << last << fueller << first << " Jahre alt." << std::endl;
		}


		
		
	}

}
;



/*
	int tag1 = (int)Person[0].Geburtstag.at(0) - 48;
	int tag2 = (int)Person[0].Geburtstag.at(1) - 48;

	std::cout << tag1 << std::endl;
	std::cout << tag2 << std::endl;
	*/





