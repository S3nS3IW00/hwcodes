#include <stdio.h>
#include <iostream>

using namespace std;

class Ember{
  
  int kor;
  string nev;
  
  public:
  Ember(int a, string b){
    kor = a;
    nev = b;
  }
  
  int getKor(){
    return kor;
  }
  
  string getNev(){
    return nev;
  }
  
  void setKor(int a){
    kor = a;
  }
  
  void setNev(string a){
    nev = a;
  }
  
  void toString(){
    std::cout << "Név: " << getNev() << " | Kor: " << getKor() << std::endl;
  }
  
};

class Alkalmazott : public Ember{
  
  int fizetes;
  
  public:
  Alkalmazott(int a, string b, int c) : Ember(a, b){
    fizetes = c;
  }
  
  int getFizetes(){
    return fizetes;
  }
  
  void setFizetes(int a){
    fizetes = a;
  }
  
  void toString(){
    std::cout << "Név: " << getNev() << " | Kor: " << getKor() << " | Fizetés: " << getFizetes() << std::endl;
  }
  
};

class Tanulo : public Ember{
  
  int diakszam;
  
  public:
  Tanulo(int a, string b, int c) : Ember(a, b){
    diakszam = c;
  }
  
  int getDiakszam(){
    return diakszam;
  }
  
  void setDiakszam(int a){
    diakszam = a;
  }
  
  void toString(){
    std::cout << "Név: " << getNev() << " | Kor: " << getKor() << " | Diákszám: " << getDiakszam() << std::endl;
  }
  
};

int main()
{
  Ember e(17, "Dani");
  e.toString();
  Alkalmazott a(18, "Berci", 250000);
  a.toString();
  Tanulo t(19, "Balu", 2654653);
  t.toString();

  return 0;
}
