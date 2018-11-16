//a kiíratáshoz és a beolvasáshoz szükséges könyvtárat használjuk
#include <iostream>
//definiálunk egy konstans értéket
#define TOMBMERET 10

//ezt azért adjuk meg, hogy ne kelljen használni az std::-t
using namespace std;

//létrehozunk egy globális tömböt, amely annyi egész számot tud tárolni, amennyi a TOMBMERET
int globalisTomb[TOMBMERET];

bool csere(int elsoIndex, int masodikIndex){
    if(elsoIndex>=0&&elsoIndex<TOMBMERET&&masodikIndex>=0&&masodikIndex<TOMBMERET){
        int ideiglenes = globalisTomb[elsoIndex];
        globalisTomb[elsoIndex]=globalisTomb[masodikIndex];
        globalisTomb[masodikIndex]=ideiglenes;

        return true;
    }
    else return false;
}

//buborek rendezes algoritmusanak megvalositasa C++ -ban
void buborekRendezes()
{
    int i;
    int j;
    for (i = 0; i < TOMBMERET-1; i++) {
        for (j = 0; j < TOMBMERET - i - 1; j++){
            if (globalisTomb[j] > globalisTomb[j + 1])
                csere(j, j + 1);
        }
    }
}

//feltöltjük a tömböt konzolról bekért értékekkel.
void konzolrolFeltolt(){
    for(int i = 0; i < TOMBMERET; i++){
        cin >> globalisTomb[i];
    }
}

//kiíratjuk a tömb összes elemét
void kiir(){
    for(int i = 0; i < TOMBMERET; i++){
        cout << "A globalisTomb " << (i+1) << ". eleme: " << globalisTomb[i] << endl;
    }
}


int main() {
    //feltoltjuk a konzolrol a tombunk minden helyet
    konzolrolFeltolt();
    //kiirjuk a meg rendezetlen tombot
    kiir();
    //rendezzuk a tombot (ez nem jar kiirassal, igy nem latjuk a folyamatot)
    buborekRendezes();
    //kiirjuk a rendezett tomb elemeit
    kiir();


    std::cout << "Lefutottam vegig" << std::endl;
    return 0;
}
