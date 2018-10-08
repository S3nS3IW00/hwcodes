#include <iostream>

using namespace std;

int duplazzMeg(int engem){
    return engem*2;
}

bool duplazzMegPointer(int& engem){
    engem*=2;
    return true;
}

bool negyzet(int& engem){
    engem*=engem;
    return true;
}

int szamHaromszorEsSzamNegyszer(int szam, int& eredmeny){
    eredmeny = szam*4;
    return szam*3;
}

int main()
{
    int elsoSzam = 10;
    int masodikSzam;
    int* elsoPointer;

    cout << "elsoSzam = " << elsoSzam << endl;
    cout << "masodikSzam = " << masodikSzam << endl;

    cout << "elsoSzam cime = " << &elsoSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;
    cout << "----||----" << endl;

    masodikSzam = elsoSzam;

    cout << "elsoSzam = " << elsoSzam << endl;
    cout << "masodikSzam = " << masodikSzam << endl;

    cout << "elsoSzam cime = " << &elsoSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;
    cout << "----||----" << endl;

    duplazzMeg(masodikSzam);

    cout << "elsoSzam = " << elsoSzam << endl;
    cout << "masodikSzam = " << masodikSzam << endl;

    cout << "elsoSzam cime = " << &elsoSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;
    cout << "----||----" << endl;

    int harmadikSzam = duplazzMeg(masodikSzam);

    cout << "elsoSzam = " << elsoSzam << endl;
    cout << "masodikSzam = " << masodikSzam << endl;

    cout << "elsoSzam cime = " << &elsoSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;

    cout << "harmadikSzam = " << harmadikSzam << endl;
    cout << "harmadikSzam cime = " << &harmadikSzam << endl;
    cout << "----||----" << endl;

    cout << "elsoPointer = " << elsoPointer << endl;
    cout << "elsoPointer cime = " << &elsoPointer << endl;
    cout << "----||----" << endl;

    elsoPointer = &masodikSzam;

    cout << "masodikSzam = " << masodikSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;
    cout << "elsoPointer = " << elsoPointer << endl;
    cout << "elsoPointer cime = " << &elsoPointer << endl;
    cout << "----||----" << endl;

    *elsoPointer = 120;

    cout << "masodikSzam = " << masodikSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;
    cout << "elsoPointer = " << elsoPointer << endl;
    cout << "elsoPointer cime = " << &elsoPointer << endl;
    cout << "----||----" << endl;

    cout << "Ahova mutat az elsoPointer = " << *elsoPointer << endl;
    cout << "----||----" << endl;

    int tomb[10];
    for(int i = 0; i < 10; i++){
        cout << "Tomb " << i << ". = " << tomb[i];
        cout << "\t\t A cime = " << &tomb[i] << endl;
    }
    cout << "----||----" << endl;

    for(int i = 0; i < 10; i++){
        tomb[i] = i;
    }

    for(int i = 0; i < 10; i++){
        cout << "Tomb " << i << ". = " << tomb[i];
        cout << "\t\t A cime = " << &tomb[i] << endl;
    }
    cout << "----||----" << endl;

    cout << "masodikSzam = " << masodikSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;
    cout << "----||----" << endl;

    duplazzMegPointer(masodikSzam);

    cout << "masodikSzam = " << masodikSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;
    cout << "----||----" << endl;

    negyzet(masodikSzam);

    cout << "masodikSzam = " << masodikSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;
    cout << "----||----" << endl;

    cout << "elsoSzam = " << elsoSzam << endl;
    cout << "masodikSzam = " << masodikSzam << endl;

    cout << "elsoSzam cime = " << &elsoSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;

    int negyedikSzam = szamHaromszorEsSzamNegyszer(masodikSzam, elsoSzam);

    cout << "elsoSzam = " << elsoSzam << endl;
    cout << "masodikSzam = " << masodikSzam << endl;

    cout << "elsoSzam cime = " << &elsoSzam << endl;
    cout << "masodikSzam cime = " << &masodikSzam << endl;

    cout << "negyedikSzam = " << negyedikSzam << endl;
    cout << "negyedikSzam cime = " << &negyedikSzam << endl;
    cout << "----||----" << endl;

    cout << "Lefutottam" << endl;
    return 0;
}
