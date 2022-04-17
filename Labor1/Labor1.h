#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <sstream>

// using namespace niemals in der Headerdatei verwenden

// Anforderung 8
using Person = struct {
	std::string Vorname;
	std::string Nachname;
	std::string Geburtstag;
	double alterInJahren = 0;
	double alterInTagen = 0;
	double alterInStunden = 0;
};

class weitereFunktionalitaeten {
public:
	static auto multiply(const int a,const int b) -> int;
	static void printText();
	static void addTen(int&);
	static void readData(std::vector<Person> &, std::ifstream &);
	static std::ifstream openstream(std::string &s);
	static void renameFile(std::string &a, std::string &b);
	static void berechnungAlter(std::vector<Person> & const);
	static void ausgabeAltertext(std::vector<Person>& const);
	
};




