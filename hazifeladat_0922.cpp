#include <stdio.h>
#include <iostream>

using namespace std;

void kiir1(int szam1, int szam2){
  while(szam1<=szam2){
    std::cout << szam1;
    szam1++;
  }
}

void kiir2(int szam1, int szam2){
  for (int i = szam1; i <= szam2; i++) {
    std::cout << i;
  }
}

int main()
{
    kiir1(1, 10);
    cout << endl;
    kiir2(1, 10);
    return 0;
}
