#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Tranzakcio {
private:
	string nev;
	int osszeg;

public:
	Tranzakcio() {}
	Tranzakcio(string _nev, int _osszeg) {
		nev = _nev;
		osszeg = _osszeg;
	}

	string &getNev() {
		return nev;
	}

	int getOsszeg() {
		return osszeg;
	}
};

vector<Tranzakcio> tranzakciok;

void readFile() {
	ifstream fajl("vasarlasok.txt");
	if (fajl.is_open()) {
		string line;
		while (getline(fajl, line)) {
			int splitIndex = line.find(':');
			string nev = line.substr(0, splitIndex);
			int osszeg = stoi(line.substr(splitIndex + 1, line.size()));
			tranzakciok.push_back(Tranzakcio(nev, osszeg));
		}
		fajl.close();
	}
}

void saveFile() {
	ofstream fajl("vasarlasok.txt");
	if (fajl.is_open()) {
		for (int i = 0; i < tranzakciok.size(); i++) {
			fajl << tranzakciok[i].getNev() << ":" << tranzakciok[i].getOsszeg() << endl;
		}
		fajl.close();
	}
}

void printTranzakciok() {
	if (tranzakciok.size() > 0) {
		cout << "\tNEV\t\tOSSZEG" << endl;
		for (int i = 0; i < tranzakciok.size(); i++) {
			cout << (i + 1) << "\t" << tranzakciok[i].getNev() << "\t\t" << tranzakciok[i].getOsszeg() << endl;
		}
	} else {
		cout << "A fajl nem tartalmaz tranzakciot!" << endl;
	}
}

string getLegdragabbTermek() {
	string nev = tranzakciok[0].getNev();
	int osszeg = tranzakciok[0].getOsszeg();
	for (int i = 0; i < tranzakciok.size(); i++) {
		if (tranzakciok[i].getOsszeg() > osszeg) {
			osszeg = tranzakciok[i].getOsszeg();
			nev = tranzakciok[i].getNev();
		}
	}
	return nev;
}

string getLegolcsobbTermek() {
	string nev = tranzakciok[0].getNev();
	int osszeg = tranzakciok[0].getOsszeg();
	for (int i = 0; i < tranzakciok.size(); i++) {
		if (tranzakciok[i].getOsszeg() < osszeg) {
			osszeg = tranzakciok[i].getOsszeg();
			nev = tranzakciok[i].getNev();
		}
	}
	return nev;
}

int getOsszBevetel() {
	int bevetel = 0;
	for (int i = 0; i < tranzakciok.size(); i++) {
		bevetel += tranzakciok[i].getOsszeg();
	}
	return bevetel;
}

void addTranzakcio() {
	string nev;
	int osszeg;
	do {
		cout << "Adjon meg egy nevet! Kilepeshez irja be, hogy 'kilep'!" << endl;
		cin >> nev;
		if (nev == "kilep") return;
		cout << "Adja meg a tranzakcio osszeget!" << endl;
		cin >> osszeg;
		tranzakciok.push_back(Tranzakcio(nev, osszeg));
		cout << "Tranzakcio hozzaadva" << endl;
	} while (nev != "kilep");
}

void elvalaszto() {
	cout << "=====[]=====" << endl;
}

int main() {
	readFile();
	printTranzakciok();
	elvalaszto();
	addTranzakcio();
	printTranzakciok();
	elvalaszto();
	cout << "Legdragabb termek: " << getLegdragabbTermek() << endl;
	cout << "Legolcsobb termek: " << getLegolcsobbTermek() << endl;
	cout << "Osszes bevetel: " << getOsszBevetel() << endl;
	saveFile();

	cout << "Lefutottam" << endl;
}
