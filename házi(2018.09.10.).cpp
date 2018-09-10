#include <iostream>
#include <stdio.h>

using namespace std;

double sum(int szamig){
  int szam = 0;
  for (int i = 0; i < szamig; i++) {
    szam+=szamig-i;
  }
  return szam;
}

void piramis(int szam){
  for (int i = 1; i < szam+1; i++) {
    for (int j = 1; j < i+1; j++) {
      std::cout << j << (j == i ? "" : "+");
    }
    std::cout << "=" << sum(i) << std::endl;
  }
}

int recsum(int szamig){
    if(szamig == 1){
        return 1;
    } else {
        return recsum(szamig-1)+szamig;
    }
}

int main()
{
    piramis(3);
    std::cout << std::endl;
    std::cout << recsum(3) << std::endl;
    return 0;
}
