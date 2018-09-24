#include <iostream>

#define TOMBMERET 10

using namespace std;

int tomb[TOMBMERET];

void kiir(){
    for(int i = 0; i<TOMBMERET; i++){
        cout << tomb[i] << endl;
    }
}

void teddBe(int hova, int mit){
    tomb[hova] = mit;
}

int veddKi(int honnan){
    return tomb[honnan];
}

void feltolt(){
    for(int i = 0; i < TOMBMERET; i++){
        //tomb[i] = i;
        teddBe(i, i);
    }
}

int main()
{
    kiir();
    feltolt();
    kiir();
    cout << veddKi(4);

    return 0;
}
