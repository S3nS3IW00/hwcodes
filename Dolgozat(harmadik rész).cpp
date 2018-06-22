#include <stdio.h>
#include <iostream>

using namespace std;

class Szemely{
  
  string nev;
  int eletkor;
  
  public:
  Szemely(){}
  Szemely(string _nev, int _eletkor){
    nev = _nev;
    eletkor = _eletkor;
  }
  
  string getNev(){
    return nev;
  }
  
  int getEletkor(){
    return eletkor;
  }
  
  void setNev(string _nev){
    nev = _nev;
  }
  
  void setEletKor(int _eletkor){
    eletkor = _eletkor;
  }
  
  void toString(){
    std::cout << "Név: " << getNev() << " | Kor: " << getEletkor() << std::endl;
  }
  
};

class Szamla{
  
  Szemely tulaj;
  int egyenleg;
  
  public:
  Szamla(string _nev, int _eletkor, int _egyenleg){
    egyenleg = _egyenleg;
    tulaj.setNev(_nev);
    tulaj.setEletKor(_eletkor);
  }
  
  int getEgyenleg(){
    return egyenleg;
  }
  
  void befizet(int osszeg){
    egyenleg += osszeg;
  }
  
  bool kivesz(int osszeg){
    if(egyenleg - osszeg > 0){
      egyenleg -= osszeg;
      return true;
    }
    return false;
  }
  
  void toString(){
    std::cout << "Név: " << tulaj.getNev() << " | Egyenleg: " << getEgyenleg() << std::endl;
  }
  
};

int main()
{
  Szemely szemely("Jancsi", 20);
  szemely.toString();
  Szamla szamla("Juliska", 25, 50000);
  szamla.toString();
  szamla.befizet(5000);
  szamla.toString();

  return 0;
}
