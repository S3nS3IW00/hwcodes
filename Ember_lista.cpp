#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Ember {
private:
	string nev;
	int kor;

public:
	Ember(string _nev, int _kor) {
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

vector<Ember> emberek;

void printMenu() {
	cout << "====================" << endl;
	cout << "(0) Kilepes" << endl;
	cout << "(1) Hozzaadas" << endl;
	cout << "(2) Torles" << endl;
	cout << "(3) Lista" << endl;
	cout << "====================" << endl;
}

void readFile() {
	string line;
	ifstream fajl("emberek.txt");
	if (fajl.is_open()) {
		while (getline(fajl, line)) {
			string nev;
			int kor;

			string s = line;
			string delimiter = ";";

			size_t pos = 0;
			string token;
			while ((pos = s.find(delimiter)) != string::npos) {
				token = s.substr(0, pos);
				nev = token;
				s.erase(0, pos + delimiter.length());
			}
			kor = stoi(s);
			emberek.push_back(Ember(nev, kor));
		}
	}
}

bool isExistsEmber(string name) {
	for (int i = 0; i < emberek.size(); i++) {
		if (emberek[i].getNev() == name) {
			return true;
		}
	}
	return false;
}

int getEmberIndexFromName(string name) {
	for (int i = 0; i < emberek.size(); i++) {
		if (emberek[i].getNev() == name) {
			return i;
		}
	}
}

void printEmberek() {
	if (emberek.size() > 0) {
		cout << "====================" << endl;
		cout << "NEV\tKOR" << endl;
		for (int i = 0; i < emberek.size(); i++) {
			cout << emberek[i].getNev() << "\t" << emberek[i].getKor() << endl;
		}
		cout << "====================" << endl;
	} else {
		cout << "A lista ures!" << endl;
	}
}

void saveFile() {
	ofstream fajl("emberek.txt");
	if (fajl.is_open()) {
		for (int i = 0; i < emberek.size(); i++) {
			fajl << emberek[i].getNev() << ";" << emberek[i].getKor() << endl;
		}
	}
}

int main(){

	readFile();
	printMenu();

	int menu;
	do {
		cin >> menu;
		if (menu == 1) {
			string nev;
			int kor;
			cout << "Adjon meg egy nevet!" << endl;
			cin >> nev;
			if (!isExistsEmber(nev)) {
				cout << "Adjon meg egy kort!" << endl;
				cin >> kor;
				emberek.push_back(Ember(nev, kor));
				cout << "Ember hozzaadva!" << endl;
			} else {
				cout << "Ember mar letezik a megadott nevvel!" << endl;
			}
		} else if (menu == 2) {
			string nev;
			cout << "Adja meg a torolni kivant nevet!" << endl;
			cin >> nev;
			if (isExistsEmber(nev)) {
				emberek.erase(emberek.begin() + getEmberIndexFromName(nev));
				cout << "Ember torolve!" << endl;
			} else {
				cout << "A megadott ember nem letezik!" << endl;
			}
		} else if (menu == 3) {
			printEmberek();
		}
		printMenu();
	} while (menu != 0);

	saveFile();

	cout << "Lefutottam!" << endl;
}
