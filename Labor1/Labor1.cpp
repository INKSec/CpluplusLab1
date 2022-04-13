#include "Labor1.h"

void weitereFunktionalitaeten::printText() {
	std::cout << "Anforderung 3 hoffentlich erfuellt" << std::endl << std::endl;
}
void weitereFunktionalitaeten::addTen(int &a) {
	a += 10;
}


std::ifstream weitereFunktionalitaeten::openstream(std::string& const s) {
	std::ifstream Datei(s, std::ifstream::in);
	return Datei;
}




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
};





