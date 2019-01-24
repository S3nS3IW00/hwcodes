#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream megnyitandoFile("fajl.txt");
	if (megnyitandoFile.is_open()) {
		/*megnyitandoFile << "Elso sor.\n";
		megnyitandoFile << "Masodik sor.\n";*/
		int szam = 0;
		do {
			cin >> szam;
			megnyitandoFile << szam << endl;
		} while (szam != 0);
		megnyitandoFile.close();
	}
	else cout << "Nem tudom megnyitni a fajlt";
	return 0;
}
