/*
 * Bevezetjük azokat a könyvtárakat, amelyekkel szeretnénk dolgozni
 * <iostream> kiírás, beolvasás (konzolról)
 * <string> szöveg
 * <fstream> fájl olvasás, írás
 * <vector> vektor lista
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define MERET 3 //Definiálunk egy konstans számot

using namespace std;

/*
 * Létrehozzuk a Szemely osztályt
 * két publikus adattaggal és két konstruktorral
*/
class Szemely{
public:
    string nev;
    int kor;

    Szemely(){}
    Szemely(string _nev, int _kor){
        nev=_nev;
        kor=_kor;
    }

};

/*
 * Létrehozunk egy publikus tömböt és egy vektor listát
 * melyekbe Szemelyeket tudunk rakni
*/
Szemely szemelyek[MERET];
vector<Szemely> beolvasottSzemelyek;

int main() {
    string nev;
    int kor;
    char elvalaszto='\t';

	/*
	 * Feltöltjük tömböt egy ciklussal a konzolról
	*/
    for (int i = 0; i < MERET; ++i) {
        cout<<"Kerem adja meg a "<<i<<". szemely nevet: "<<endl;
        cin>>nev;
        cout<<"Kerem adja meg a "<<i<<". szemely korat: "<<endl;
        cin>>kor;
        szemelyek[i]=Szemely(nev, kor);
    }

	/*
	 * Megnyitjuk a lista.txt fájlt
	 * Ellenőrizzük, hogy nyitva van-e a fájl
	 * Beletöltjük a tömb elemeit a fájlba egy ciklussal
	 * Bezárjuk a fájlt
	*/
    ofstream fajlom("lista.txt");

    if(fajlom.is_open()){
        cout<<"A fajl megnyitva irasra."<<endl;

        for (int i = 0; i < MERET; ++i) {
            fajlom<<szemelyek[i].nev;
            fajlom<<'\t';
            fajlom<<szemelyek[i].kor;
            fajlom<<'\n';
        }
        cout<<"A fajl feltoltve."<<endl;

    } else{cout<<"Nem sikerult megnyitni a fajlt!";}

    fajlom.close();
    cout<<"A fajl bezarva."<<endl;

	/*
	 * Megnyitjuk a lista.txt fájlt
	 * Ellenőrizzük, hogy nyitva van-e a fájl
	 * Soronként végigmegyünk a fájlon és beletöltjük az adatokat a vektor listába
	 * Bezárjuk a fájlt
	*/
    ifstream fajlomOlvasasra("lista.txt");

    if(fajlomOlvasasra.is_open()){
        cout<<"A fajl megnyitva olvasasra."<<endl;

        string beolvasottSor;

        string kiolvasottNev;
        string kiolvasottKor;

        while (getline(fajlomOlvasasra,beolvasottSor)){
            unsigned long elvalasztoHelye=beolvasottSor.find('\t'); // Megkeresi a \t karakter helyét a szövegben
            kiolvasottNev=beolvasottSor.substr(0,elvalasztoHelye); // Elvágja a szöveget a 0 és az első \t karakter indexénél
            kiolvasottKor=beolvasottSor.substr(elvalasztoHelye+1,beolvasottSor.size()); // Elvágja a szöveget az első \t karakter helyénél és a második \t karakter indexénél

            int kor=stoi(kiolvasottKor); // Átalakítja a kor szöveget számmá

            beolvasottSzemelyek.push_back(Szemely(kiolvasottNev,kor));
        }

    }else{cout<<"Nem sikerult megnyitni a fajlt!";}

    fajlomOlvasasra.close();
    cout<<"A fajl olvasasa befejezodott."<<endl;

	/*
	 * Végigmegyünk a vektor listán egy ciklussal és kiíratjuk a tartalmát a konzolra
	*/
    for (int j = 0; j < beolvasottSzemelyek.size(); ++j) {
        cout<<beolvasottSzemelyek[j].nev<<'\t'<<beolvasottSzemelyek[j].kor<<endl;
    }
    cout<<"Minden tarolt adat kiirva."<<endl;

    std::cout << "A kod a vegehez ert." << std::endl;
    return 0;
}