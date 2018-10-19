#include <iostream>
#define TOMBMERET 10

using namespace std;

int szamok[TOMBMERET];
char karakterek[TOMBMERET];

void szamokFeltolt(){
    for(int i = 0; i < TOMBMERET; i++){
        szamok[i] = i;
    }
}

void szamokFeltoltParos(){
    for(int i = 0; i < TOMBMERET; i++){
        szamok[i] = (i+1)*2;
    }
}

bool szamokAdottHelyre(int index, int szam){
    if(index >= 0 && index < TOMBMERET){
        szamok[index] = szam;
        return true;
    }
    return false;
}

bool szamokCsere(int index, int index2){
    if(index >= 0 && index < TOMBMERET && index2 >= 0 && index2 < TOMBMERET){
        int temp = szamok[index];
        szamok[index] = szamok[index2];
        szamok[index2] = temp;
        return true;
    }
    return false;
}

void szamokKiir(){
    for(int i = 0; i < TOMBMERET; i++){
        cout << "A szamok tomb " << (i+1) << ". eleme = " << szamok[i] << endl;
    }
}

void karakterekBellitUtolsoHelyre(char karakter){
    karakterek[TOMBMERET-1] = karakter;
}

void karakterekFeltolt(){
    karakterek[0] = 'A';
    karakterek[1] = 'z';
    karakterek[2] = ' ';
    karakterek[3] = 'a';
    karakterek[4] = 'l';
    karakterek[5] = 'm';
    karakterek[6] = 'a';
    karakterek[7] = ' ';
    karakterek[8] = 'j';
    karakterek[9] = 'o';
}

bool karakterekAdottHelyre(int index, char karakter){
    if(index >= 0 && index < TOMBMERET){
        karakterek[index] = karakter;
        return true;
    }
    return false;
}

void karakterekKiir(){
    for(int i = 0; i < TOMBMERET; i++){
        cout << karakterek[i];
    }
    cout << endl;
}

void konzolrolFeltolt(){
    for(int i = 0; i < TOMBMERET; i++){
        cout << "Kerem adja meg a(z) " << (i+1) << ". elemet:" << endl;
        cin >> szamok[i];
    }
}

void elvalaszto(){
    cout << "-----||-----" << endl;
}

int main()
{
    konzolrolFeltolt();
    szamokKiir();

    cout << "Lefutottam!" << endl;
    return 0;
}
