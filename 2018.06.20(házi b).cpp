#include <stdio.h>
#include <iostream>

using namespace std;

class Novenyek{
    
    int meret;
    
    public:
    Novenyek(int a){
        meret = a;
    }
    
    int getMeret(){
        return meret;
    }
    
    void setMeret(int a){
        meret = a;
    }
    
    void toString(){
        std::cout << "Méret: " << getMeret() << std::endl;
    }
    
};

class Zoldseg : public Novenyek{
    
    int csipos;
    
    public:
    Zoldseg(int a, int b) : Novenyek(a){
        csipos = b;
    }
    
    int getCsipos(){
        return csipos;
    }
    
    void setCsipos(int a){
        csipos = a;
    }
    
    void toString(){
        std::cout << "Méret: " << getMeret() << " | Csipősség foka: " << getCsipos() << std::endl;
    }
    
};

class Gyumolcs : public Novenyek{
    
    int edes;
    
    public:
    Gyumolcs(int a, int b) : Novenyek(a){
        edes = b;
    }
    
    int getEdes(){
        return edes;
    }
    
    void setEdes(int a){
        edes = a;
    }
    
    void toString(){
        std::cout << "Méret: " << getMeret() << " | Édesség foka: " << getEdes() << std::endl;
    }
    
};

class Paprika : Zoldseg{
    
    string szin;
    
    public:
    Paprika(int a, int b, string c) : Zoldseg(a, b){
        szin = c;
    }
    
    string getSzin(){
        return szin;
    }
    
    void setSzin(string a){
        szin = a;
    }
    
    void toString(){
        std::cout << "Méret: " << getMeret() << " | Csipősség foka: " << getCsipos() << " | Szín: " << getSzin() << std::endl;
    }
    
};

class Hagyma : Zoldseg{
    
    int reteg;
    
    public:
    Hagyma(int a, int b, int c) : Zoldseg(a, b){
        reteg = c;
    }
    
    int getReteg(){
        return reteg;
    }
    
    void setReteg(int a){
        reteg = a;
    }
    
    void toString(){
        std::cout << "Méret: " << getMeret() << " | Csipősség foka: " << getCsipos() << " | Rétegek száma: " << getReteg() << std::endl;
    }
    
};

class Meggy : Gyumolcs{
    
    bool magozott;
    
    public:
    Meggy(int a, int b, bool c) : Gyumolcs(a, b){
        magozott = c;    
    }
    
    bool getMagozott(){
        return magozott;
    }
    
    void setMagozott(bool a){
        magozott = a;
    }
    
    void toString(){
        std::cout << "Méret: " << getMeret() << " | Édesség foka: " << getEdes() << " | Magozott: " << (getMagozott() ? "Igen" : "Nem") << std::endl;
    }
    
};

class Korte : Gyumolcs{
    
    bool erett;
    
    public:
    Korte(int a, int b, bool c) : Gyumolcs(a, b){
        erett = c;    
    }
    
    bool getErett(){
        return erett;
    }
    
    void setErett(bool a){
        erett = a;
    }
    
    void toString(){
        std::cout << "Méret: " << getMeret() << " | Édesség foka: " << getEdes() << " | Érett: " << (getErett() ? "Igen" : "Nem") << std::endl;
    }
    
};

int main()
{
    Novenyek n(5);
    n.toString();
    Zoldseg z(8, 3);
    z.toString();
    Gyumolcs gy(7, 6);
    gy.toString();
    Paprika p(8, 2, "piros");
    p.toString();
    Hagyma h(7, 5, 3);
    h.toString();
    Meggy m(2, 2, true);
    m.toString();
    Korte k(10, 5, false);
    k.toString();

    return 0;
}
