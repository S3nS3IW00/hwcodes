#include <iostream>
#define TOMBMERET 25

using namespace std;

char karakter;
int szam;
int* szamPointer;
char* karPointer;
int szamokTomb[TOMBMERET];
char szoveg[5];

void indexekkelFeltolt(){
    for(int i = 0; i < TOMBMERET; i++){
        szamokTomb[i] = i;
    }
}

void indexekkelFeltoltKetszer(){
    for(int i = 0; i < TOMBMERET; i++){
        szamokTomb[i] = (i*2)+1;
    }
}

void szamTombKiir(){
    for(int i = 0; i < TOMBMERET; i++){
        cout << "A tomb " << (i+1) << ". eleme = " << szamokTomb[i] << endl;
    }
}

void vegeBeTolt(){
    szoveg[0] = 'V';
    szoveg[1] = 'E';
    szoveg[2] = 'G';
    szoveg[3] = 'E';
    szoveg[4] = '\n';
}

void szovegKiir(){
    for(int i = 0; i < 5; i++){
        cout << szoveg[i];
    }
}

void elvalaszto(){
    cout << "-----||-----" << endl;
}



int main()
{
    szamTombKiir();
    elvalaszto();
    indexekkelFeltoltKetszer();
    szamTombKiir();
    elvalaszto();
    vegeBeTolt();
    szovegKiir();
    elvalaszto();

    szamPointer = szamokTomb;
    for(int i = 0; i < TOMBMERET; i++){
        cout << szamPointer << endl; //mivel az int mérete 4 bájt, ezért a memóricímek négyessével vannak.
        szamPointer++;
    }

    elvalaszto();

    karPointer = szoveg;
    for(int i = 0; i < 5; i++){
        cout << (int*)karPointer << endl; //mivel az karakter mérete 1 bájt, ezért a memóricímek egyesével vannak.
        karPointer++;
    }

    cout << "Lefutottam" << endl;
    return 0;
}
