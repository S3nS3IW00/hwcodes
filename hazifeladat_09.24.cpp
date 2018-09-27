#include <iostream>
#define TOMBMERET 10

using namespace std;

int tomb[TOMBMERET];
char tombChar[TOMBMERET];

void kiir(){
    for(int i = 0; i<TOMBMERET; i++){
        cout << tomb[i] << "\t";
    }
}

void feltoltParos(){
    for(int i = 0; i < TOMBMERET; i++){
        tomb[i] = (i+1)*2;
    }
}

int main()
{
    kiir();
    feltoltParos();
    cout << endl;
    kiir();
}
