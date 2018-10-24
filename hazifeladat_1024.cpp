#include <iostream>

using namespace std;

void szamKonzolrolNegyzetKiir(){
    int szam;
    cin >> szam;
    cout << szam*szam << endl;
}

void szamKonzolrolFaktorialisKiir(){
    int szam;
    cin >> szam;
    for(int i = szam-1; i > 0; i--){
        szam*=i;
    }
    cout << szam << endl;
}

void szamokKonzolrolOsszegKiir(){
    int szam;
    int szam2;
    cin >> szam;
    cin >> szam2;
    cout << szam+szam2 << endl;
}

void pozitivParatlanKiir(int x){
    for(int i = 0; i < x; i++){
        cout << i*2+1 << " ";
    }
    cout << endl;
}

void parosVagyParatlan(){
    int szam;
    cin >> szam;
    cout << (szam % 2 == 0 ? "paros" : "paratlan") << endl;
}

void amigNemNulla(){
    int szam;
    cin >> szam;
    while(szam != 0){
        cin >> szam;
    }
}

void legnagyobbSzamAmigNemNulla(){
    int szam = 0;
    int legnagyobb = 0;
    do {
        cin >> szam;
        if(szam > legnagyobb){
            legnagyobb = szam;
            cout << "Legnagyobb: " << legnagyobb << endl;
        }
    }while(szam > 0);
}

int main()
{
    szamKonzolrolNegyzetKiir();
    szamKonzolrolFaktorialisKiir();
    szamokKonzolrolOsszegKiir();
    pozitivParatlanKiir(5);
    parosVagyParatlan();
    amigNemNulla();
    legnagyobbSzamAmigNemNulla();

    return 0;
}
