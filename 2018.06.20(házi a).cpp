#include <stdio.h>
#include <iostream>

using namespace std;

class Epulet{
    
    int ablak, terulet;
    
    public:
    Epulet(int a, int b){
        ablak = a;
        terulet = b;
    }
    
    int getAblak(){
        return ablak;
    }
    
    int getTerulet(){
        return terulet;
    }
    
    void setAblak(int a){
        ablak = a;
    }
    
    void setTerulet(int a){
        terulet = a;
    }
    
    void toString(){
        std::cout << "Ablakok száma: " << getAblak() << " | Alapterület: " << getTerulet() << std::endl;
    }
};

class Haz : Epulet{
    
    int szoba, ajto;
    
    public:
    Haz(int a, int b, int c, int d) : Epulet(a, b){
        szoba = c;
        ajto = d;
    }
    
    int getSzoba(){
        return szoba;
    }
    
    int getAjto(){
        return ajto;
    }
    
    void setSzoba(int a){
        szoba = a;
    }
    
    void setAjto(int a){
        ajto = a;
    }
    
    void toString(){
        std::cout << "Ablakok száma: " << getAblak() << " | Alapterület: " << getTerulet() << " | Szobák száma: " << getSzoba() << " | Ajtók száma: " << getAjto() << std::endl;
    }
};

class Garazs : Epulet{
    
    int parkolo;
    
    public:
    Garazs(int a, int b, int c) : Epulet(a, b){
        parkolo = c;
    }
    
    int getParkolo(){
        return parkolo;
    }
    
    void setParkolo(int a){
        parkolo = a;
    }
    
    void toString(){
        std::cout << "Ablakok száma: " << getAblak() << " | Alapterület: " << getTerulet() << " | Parkolók száma: " << getParkolo() << std::endl;
    }
};

int main()
{
    Epulet e(5, 100);
    e.toString();
    Haz h(10, 150, 5, 15);
    h.toString();
    Garazs g(0, 300, 50);
    g.toString();

    return 0;
}
