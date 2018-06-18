#include <stdio.h>
#include <iostream>

using namespace std;

bool oszthato(int szamok[10], int oszto){
    for(int i = 0; i < 10; i++){
        if(szamok[i] % oszto == 0){
            return true;
        }
    }
    return false;
}

void osztas(bool oszthato, int oszto){
    if(oszthato){
        std::cout << "A számok közt van olyan, szám, ami osztható ezzel: " << oszto << std::endl;
    } else {
        std::cout << "A számok közt nincs olyan, szám, ami osztható ezzel: " << oszto << std::endl;
    }
}

int main()
{
    int oszto;
    std::cout << "Adja meg az osztót:" << std::endl;
    std::cin >> oszto;
    int szamok[10];
    for(int i = 0; i < 10; i++){
        szamok[i] = (i+1)*5;
    }
    osztas(oszthato(szamok, oszto), oszto);
    return 0;
}
