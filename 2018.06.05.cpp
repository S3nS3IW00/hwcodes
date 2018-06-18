#include <stdio.h>
#include <iostream>

using namespace std;

int szorzat(int a, int b){
    return a*b;
}

int osztas(int a, int b){
    if(a > b){
        return a/b;
    } else {
        return b/a;
    }
    return 0;
}

int main()
{
    std::cout << "Szorzat: " << szorzat(5, 2) << std::endl;
    std::cout << "Osztás: " << osztas(6, 2) << std::endl;

    return 0;
}
