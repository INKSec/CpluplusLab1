#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
// using namespace niemals in der Headerdatei verwenden
using Person = struct {
	std::string Vorname;
	std::string Nachname;
	std::string Geburtstag;
	int alterInJahren = 0;
	int alterInTagen = 0;
	int alterInStunden = 0;
};

class weitereFunktionalitaeten {
public:
	static void printText();
	static void addTen(int &);
	static void readData(std::vector<Person> &, std::ifstream &);
	static std::ifstream openstream(std::string &s);
	static void renameFile(std::string &a, std::string &b);

	
};




