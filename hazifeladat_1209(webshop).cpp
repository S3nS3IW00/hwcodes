#include <iostream>
#include <vector>

using namespace std;

class Termek {
private:
    int cikkszam;
    string nev;
    int ar;
    int suly;

public:
    Termek(){}
    Termek(int _cikkszam, string _nev, int _ar, int _suly){
        cikkszam = _cikkszam;
        nev = _nev;
        ar = _ar;
        suly = _suly;
    }

    int getCikkszam(){
        return cikkszam;
    }

    string &getNev(){
        return nev;
    }

    int getAr(){
        return ar;
    }

    int getSuly(){
        return suly;
    }
};

class Webshop {
private:
    vector<Termek> raktaron;
    vector<Termek> eladott;
    string nev;
    string cim;

    int bevetel = 0;
    int eladottDarab = 0;

public:
    Webshop(){}
    Webshop(string _nev, string _cim){
        nev = _nev;
        cim = _cim;
    }

    string &getNev(){
        return nev;
    }

    string &getCim(){
        return cim;
    }

    int getEladottDarab(){
        return eladottDarab;
    }

    int getBevetel(){
        return bevetel;
    }

    int getTermekPositionInRaktaron(Termek termek){
        for(int i = 0; i < raktaron.size(); i++){
            if(raktaron[i].getCikkszam() == termek.getCikkszam()){
                return i;
            }
        }
        return 0;
    }

    void addRaktaron(Termek termek){
        raktaron.push_back(termek);
    }

    void removeRaktaron(Termek termek){
        raktaron.erase(raktaron.begin()+getTermekPositionInRaktaron(termek));
    }

    bool isExistsRaktaron(Termek termek){
        for(int i = 0; i < raktaron.size(); i++){
            if(raktaron[i].getCikkszam() == termek.getCikkszam()){
                return true;
            }
        }
        return false;
    }

    void addEladott(Termek termek){
        eladott.push_back(termek);
    }

    bool isExistsEladott(Termek termek){
        for(int i = 0; i < eladott.size(); i++){
            if(eladott[i].getCikkszam() == termek.getCikkszam()){
                return true;
            }
        }
        return false;
    }

    void eladas(Termek termek){
        removeRaktaron(termek);
        addEladott(termek);
        bevetel+=termek.getAr();
        eladottDarab++;
    }

    Termek getLegdragabbEladott(){
        Termek temp;
        for(int i = 0; i < eladott.size(); i++){
            if(!isExistsEladott(temp) || eladott[i].getAr() > temp.getAr()){
                temp = eladott[i];
            }
        }
        return temp;
    }

    Termek getLegolcsobbEladott(){
        Termek temp;
        for(int i = 0; i < eladott.size(); i++){
            if(!isExistsEladott(temp) || eladott[i].getAr() < temp.getAr()){
                temp = eladott[i];
            }
        }
        return temp;
    }

    void termekTulajdonsagok(Termek termek){
        cout << "\t CIKKSZAM \t NEV \t AR \t SULY" << endl;
        cout << "\t\t" << termek.getCikkszam() << "\t" << termek.getNev() << "\t" << termek.getAr() << "Ft\t" << termek.getSuly() << "kg" << endl;
    }

    void termekekRaktaron(){
        cout << "Raktaron levo termekek:" << endl;
        cout << "\t CIKKSZAM \t NEV \t AR \t SULY" << endl;
        for(int i = 0; i < raktaron.size(); i++){
            cout << (i+1) << ".\t\t" << raktaron[i].getCikkszam() << "\t" << raktaron[i].getNev() << "\t" << raktaron[i].getAr() << "Ft\t" << raktaron[i].getSuly() << "kg" << endl;
        }
    }

    void termekekEladott(){
        cout << "Eladott termekek:" << endl;
        cout << "\t CIKKSZAM \t NEV \t AR \t SULY" << endl;
        for(int i = 0; i < eladott.size(); i++){
            cout << (i+1) << ".\t\t" << eladott[i].getCikkszam() << "\t" << eladott[i].getNev() << "\t" << eladott[i].getAr() << "Ft\t" << eladott[i].getSuly() << "kg" << endl;
        }
    }
};

void elvalaszto(){
    cout << "----[]-----" << endl;
}

int main(){

    Webshop w("Epp sztor", "420 Istenhatamogott sehol utca 69.");
    Termek t(1, "pabdzsi", 20000, 50);
    Termek t2(2, "getea", 10000, 1);
    Termek t3(3, "aszfalt", 500, 1);
    Termek t4(4, "empajor", 5000, 2);

    w.addRaktaron(t);
    w.addRaktaron(t2);
    w.addRaktaron(t3);
    w.addRaktaron(t4);

    w.termekekRaktaron();
    elvalaszto();
    w.termekekEladott();
    elvalaszto();

    w.eladas(t4);
    w.termekekRaktaron();
    elvalaszto();
    w.termekekEladott();
    elvalaszto();
    cout << "Eladott termekek szama: " << w.getEladottDarab() << endl;
    cout << "Bevetel: " << w.getBevetel() << "Ft" << endl;
    elvalaszto();

    w.eladas(t2);
    w.termekekRaktaron();
    elvalaszto();
    w.termekekEladott();
    elvalaszto();
    cout << "Eladott termekek szama: " << w.getEladottDarab() << endl;
    cout << "Bevetel: " << w.getBevetel() << "Ft" << endl;
    elvalaszto();

    cout << "Legolcsobb eladott termek:" << endl;
    w.termekTulajdonsagok(w.getLegolcsobbEladott());
    elvalaszto();
    cout << "Legdragabb eladott termek:" << endl;
    w.termekTulajdonsagok(w.getLegdragabbEladott());
    elvalaszto();

    cout << "Lefutottam" << endl;
    return 0;
}
