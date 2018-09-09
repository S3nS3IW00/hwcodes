#include <stdio.h>
#include <iostream>

using namespace std;

class Edesseg{
    int cukormennyiseg;
    
    public:
    Edesseg(int _cukormennyiseg){
        cukormennyiseg = _cukormennyiseg;
    }
    
    int getCukormennyiseg(){
        return cukormennyiseg;
    }
    
    void setCukormennyiseg(int _cukormennyiseg){
        cukormennyiseg = _cukormennyiseg;
    }
    
    void toString(){
        std::cout << "Cukormennyiség: " << getCukormennyiseg() << std::endl;
    }
};

class HidegEdesseg : public Edesseg{
    int hofok;
    
    public:
    HidegEdesseg(int _cukormennyiseg, int _hofok) : Edesseg(_cukormennyiseg){
        hofok = _hofok;
    }
    
    int getHofok(){
        return hofok;
    }
    
    void setHofok(int _hofok){
        hofok = _hofok;
    }
    
    void toString(){
        std::cout << "Cukormennyiség: " << getCukormennyiseg() << " | Hőfok: " << getHofok() << std::endl;
    }
};

class Sutemeny : public Edesseg{
    int sutesido;
    
    public:
    Sutemeny(int _cukormennyiseg, int _sutesido) : Edesseg(_cukormennyiseg){
        sutesido = _sutesido;
    }
    
    int getSutesido(){
        return sutesido;
    }
    
    void setSutesido(int _sutesido){
        sutesido = _sutesido;
    }
    
    void toString(){
        std::cout << "Cukormennyiség: " << getCukormennyiseg() << " | Sütésidő: " << getSutesido() << std::endl;
    }
};

class Fagylalt : public Edesseg{
    string iz;
    
    public:
    Fagylalt(int _cukormennyiseg, string _iz) : Edesseg(_cukormennyiseg){
        iz = _iz;
    }
    
    string getIz(){
        return iz;
    }
    
    void setIz(string _iz){
        iz = _iz;
    }
    
    void toString(){
        std::cout << "Cukormennyiség: " << getCukormennyiseg() << " | Íz: " << getIz() << std::endl;
    }
};

int main()
{
    Edesseg e(10);
    e.toString();
    HidegEdesseg he(11, 5);
    he.toString();
    Sutemeny s(5, 120);
    s.toString();
    Fagylalt f(4, "Csokoládé");
    f.toString();

    return 0;
}