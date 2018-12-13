#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Termek {
private:
	int ar;
	int nettoAr;
	string nev;
	int cikkszam;
public:
	Termek() {}
	Termek(int _ar, int _nettoAr, string _nev, int _cikkszam) {
		ar = _ar;
		nettoAr = _nettoAr;
		nev = _nev;
		cikkszam = _cikkszam;
	}

	int getAr() {
		return ar;
	}

	int getNettoAr() {
		return nettoAr;
	}

	string &getNev() {
		return nev;
	}

	int getCikkszam() {
		return cikkszam;
	}

	int getBruttoAr() {
		return getNettoAr()*1.27;
	}
};

class Kisbolt {
private:
	string nev;
	string varos;
	vector<Termek> termekek;

public:
	Kisbolt() {}
	Kisbolt(string _nev, string _varos) {
		nev = _nev;
		varos = _varos;
	}

	string &getNev() {
		return nev;
	}

	string &getVaros() {
		return varos;
	}

	bool addTermek(Termek termek) {
		if (!isExistsTermek(termek)) {
			termekek.push_back(termek);
			return true;
		}
		return false;
	}

	bool isExistsTermek(Termek termek) {
		for (int i = 0; i < termekek.size(); i ++) {
			if (termek.getCikkszam() == termekek[i].getCikkszam()) {
				return true;
			}
		}
		return false;
	}

	Termek legnagyobbBeveteltHozoTermek() {
		Termek temp;
		for (int i = 0; i < termekek.size(); i++) {
			if ((!isExistsTermek(temp)) || ((termekek[i].getNettoAr() - termekek[i].getAr()) > (temp.getNettoAr() - temp.getAr()))) {
				temp = termekek[i];
			}
		}
		return temp;
	}

	void termekTulajdonsagok(Termek termek) {
		cout << "\t AR \t NETTO \t NEV \t\t CIKKSZAM" << endl;
		cout << "1. \t " << termek.getBruttoAr() << " \t " << termek.getNettoAr() << " \t " << termek.getNev() << " \t " << termek.getCikkszam() << endl;
	}

	void termekLista() {
		cout << "\t AR \t NETTO \t NEV \t\t CIKKSZAM" << endl;
		for (int i = 0; i < termekek.size(); i++) {
			cout << (i+1) << ". \t " << termekek[i].getBruttoAr() << " \t " << termekek[i].getNettoAr() << " \t " << termekek[i].getNev() << " \t " << termekek[i].getCikkszam() << endl;
		}
	}
};

void elvalaszto() {
	cout << "-----[]-----" << endl;
}

int main() {
	Kisbolt tesco("Tesco", "Budapest");

	Termek t(200, 300, "Szaraz zsemle", 1);
	Termek t2(450, 500, "Aludt tej", 2);
	Termek t3(80, 200, "Nyaloka", 3);

	tesco.addTermek(t);
	tesco.addTermek(t2);
	tesco.addTermek(t3);

	tesco.termekLista();

	elvalaszto();

	tesco.termekTulajdonsagok(tesco.legnagyobbBeveteltHozoTermek());

	cout << "Lefutottam!" << endl;
}
