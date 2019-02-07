#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Szemely {
private:
	string nev;
	int kor;

public:
	Szemely() {}
	Szemely(string _nev, int _kor) {
		nev = _nev;
		kor = _kor;
	}

	string &getNev() {
		return nev;
	}

	int getKor() {
		return kor;
	}
};

vector<Szemely> szemelyek;

bool insertDatas() {
	ofstream fajl("lista.txt");
	if (fajl.is_open()) {
		string nev;
		int kor;
		do {
			cout << "Adjon meg egy nevet! Kilepeshez irja be a 'kilep' szot!" << endl;
			cin >> nev;
			if (nev == "kilep") {
				fajl.close();
				return true;
			}
			cout << "Adjon meg egy kort!" << endl;
			cin >> kor;
			if(nev != "kilep" && kor != 0) fajl << nev << "\t" << kor << "\n";
		} while (nev != "kilep" || kor != 0);
	} else {
		return false;
	}
	fajl.close();
	return true;
}

bool getDatas() {
	ifstream fajl("lista.txt");
	if (fajl.is_open()) {
		string line;
		while (getline(fajl, line)) {
			unsigned long splitIndex = line.find('\t');
			string nev = line.substr(0, splitIndex);
			int kor = stoi(line.substr(splitIndex + 1, line.size()));
			
			szemelyek.push_back(Szemely(nev, kor));
		}
	}
	fajl.close();
	if (szemelyek.size() < 1) {
		return false;
	}
	return true;
}

string getMinKorNev() {
	int kor = szemelyek[0].getKor();
	string nev = szemelyek[0].getNev();
	for (int i = 0; i < szemelyek.size(); i++) {
		if (kor > szemelyek[i].getKor()) {
			kor = szemelyek[i].getKor();
			nev = szemelyek[i].getNev();
		}
	}
	return nev;
}

string getMaxKorNev() {
	int kor = szemelyek[0].getKor();
	string nev = szemelyek[0].getNev();
	for (int i = 0; i < szemelyek.size(); i++) {
		if (kor < szemelyek[i].getKor()) {
			kor = szemelyek[i].getKor();
			nev = szemelyek[i].getNev();
		}

	}
	return nev;
}

int getAvgKor() {
	int sum = 0;
	if (szemelyek.size() > 0) {
		for (int i = 0; i < szemelyek.size(); i++) {
			sum += szemelyek[i].getKor();
		}
		return sum / szemelyek.size();
	}
	return 0;
}

int main() {
	if (insertDatas()) {
		if (getDatas()) {
			cout << "Legkisebb korral rendelkezo szemely neve: " << getMinKorNev() << endl;
			cout << "Legnagyobb korral rendelkezo szemely neve: " << getMaxKorNev() << endl;
			cout << "Atlag kor: " << getAvgKor() << endl;
		} else {
			cout << "A fajl nem tartalmaz adatot!" << endl;
		}
	} else {
		cout << "Nem sikerult az adatok feltoltese!" << endl;
	}

    cout << "Lefutottam" << endl; 
}
