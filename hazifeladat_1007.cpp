#include <iostream>
#define TOMBMERET 10

using namespace std;

int elsoSzam = 1;
int masodikSzam = 2;
int harmadikSzam;
int negyedikSzam;

int tomb[TOMBMERET];

void negativPiramis(int meret){
    for(int i = 0; i < meret; i++){
        for(int j = i; j < meret; j++){
            cout << "L";
        }
        cout << endl;
    }
}

void pozitivPiramis(int meret){
    for(int i = 0; i < meret; i++){
        for(int j = 0; j <= i; j++){
            cout << "L";
        }
        cout << endl;
    }
}

void teljesPiramis(int darab, int meret){
    for(int i = 0; i < darab; i++){
        pozitivPiramis(meret);
        negativPiramis(meret);
    }
}

bool duplazzMeg(int& szam){
    szam*=2;
    return true;
}

int negyzet(int szam){
    return szam*szam;
}

int main()
{
    negativPiramis(3);
    cout << endl;
    pozitivPiramis(3);
    cout << endl;
    teljesPiramis(2, 5);
    cout << endl;

    cout << "----||----" << endl;
    cout << "elsoSzam erteke: " << elsoSzam << endl;
    cout << "elsoSzam cime: " << &elsoSzam << endl;
    cout << "masodikSzam erteke: " << masodikSzam << endl;
    cout << "masodikSzam cime: " << &masodikSzam << endl;
    cout << "harmadikSzam erteke: " << harmadikSzam << endl;
    cout << "harmadikSzam cime: " << &harmadikSzam << endl;
    cout << "negyedikSzam erteke: " << negyedikSzam << endl;
    cout << "negyedikSzam cime: " << &negyedikSzam << endl;
    cout << "----||----" << endl;

    duplazzMeg(elsoSzam);

    cout << "elsoSzam erteke: " << elsoSzam << endl;
    cout << "elsoSzam cime: " << &elsoSzam << endl;
    cout << "masodikSzam erteke: " << masodikSzam << endl;
    cout << "masodikSzam cime: " << &masodikSzam << endl;
    cout << "harmadikSzam erteke: " << harmadikSzam << endl;
    cout << "harmadikSzam cime: " << &harmadikSzam << endl;
    cout << "negyedikSzam erteke: " << negyedikSzam << endl;
    cout << "negyedikSzam cime: " << &negyedikSzam << endl;
    cout << "----||----" << endl;

    harmadikSzam = negyzet(elsoSzam);

    cout << "elsoSzam erteke: " << elsoSzam << endl;
    cout << "elsoSzam cime: " << &elsoSzam << endl;
    cout << "masodikSzam erteke: " << masodikSzam << endl;
    cout << "masodikSzam cime: " << &masodikSzam << endl;
    cout << "harmadikSzam erteke: " << harmadikSzam << endl;
    cout << "harmadikSzam cime: " << &harmadikSzam << endl;
    cout << "negyedikSzam erteke: " << negyedikSzam << endl;
    cout << "negyedikSzam cime: " << &negyedikSzam << endl;
    cout << "----||----" << endl;

    for(int i = 0; i < TOMBMERET; i++){
        cout << "tomb[" << i << "] erteke: " << tomb[i] << "\t\t cime: " << &tomb[i] << endl;
    }
    cout << "----||----" << endl;

    for(int i = 0; i < TOMBMERET; i++){
        tomb[i] = i;
    }

    for(int i = 0; i < TOMBMERET; i++){
        cout << "tomb[" << i << "] erteke: " << tomb[i] << "\t\t cime: " << &tomb[i] << endl;
    }
    cout << "----||----" << endl;

    return 0;
}
