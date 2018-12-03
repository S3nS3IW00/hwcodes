#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

class Alkatresz {
private:
	int gyartasiSzam;
	int suly;
public:
	Alkatresz() {}
	Alkatresz(int _gyartasiSzam, int _suly) {
		gyartasiSzam = _gyartasiSzam;
		suly = _suly;
	}

	int getGyartasiSzam() {
		return gyartasiSzam;
	}

	int getSuly() {
		return suly;
	}
};

int main(){

	vector<Alkatresz> szerszamosLada;
	for (int i = 0; i <= 10; i++) {
		szerszamosLada.push_back(Alkatresz(i, i));
	}

	for (int i = 0; i < szerszamosLada.size(); i++) {
		cout << szerszamosLada[i].getGyartasiSzam() << " " << szerszamosLada[i].getSuly() << endl;
	}

	map<int, string> par;
	par.insert(pair<int, string>(10, "Tiz"));

	map<int, string>::iterator iter;
	for (iter = par.begin(); iter != par.end(); iter++) {
		cout << iter->first << "\t";
		cout << iter->second << endl;
	}

    cout << "Lefutottam!" << endl;
	
	return 0;
}

