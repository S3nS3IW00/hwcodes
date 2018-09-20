#include <iostream>

using namespace std;

void parosSzamok(){
    for(int i = 1; i <= 20; i++){
        if(i % 2 == 0){
            cout << i << " ";
        }
    }
}

void sSzamszor(int n){
    for(int i = 0; i < n; i++){
        cout << "S";
    }
}

void lTeglalap(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "L";
        }
        cout << endl;
    }
}

void ePiramis(int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << "E";
        }
        cout << endl;
    }
}

int main()
{
    cout << "A program sikeresen lefutott" << endl;
    parosSzamok();
    cout << endl;
    sSzamszor(10);
    cout << endl;
    lTeglalap(3);
    cout << endl;
    ePiramis(5);
    return 0;
}
