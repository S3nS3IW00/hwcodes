#include <iostream>

using namespace std;

class Teendok{

private:
    string datum;
    string idotartam;
    unsigned int fontossag;

public:
    Teendok(){}
    Teendok(string _datum, string _idotartam, unsigned int _fontossag){
        datum=_datum;
        idotartam=_idotartam;
        fontossag=_fontossag;
    }

    const string &getDatum() const {
        return datum;
    }

    const string &getIdotartam() const {
        return idotartam;
    }

    unsigned int getFontossag() const {
        return fontossag;
    }
};

Teendok* list = NULL;
int elementNum;

bool isEmpty(){
    if(elementNum == 0){
        return true;
    }
    return false;
}
void deleteAllElements(){
    if(elementNum != 0 || list != NULL){
        delete[] list;
        elementNum = 0;
    }
}

void putLast(Teendok newElement){
    Teendok *tempList = new Teendok[elementNum+1];
    for (int i = 0; i < elementNum; ++i) {
        tempList[i] = list[i];
    }
    tempList[elementNum] = newElement;
    if(list) delete[] list;
    list = tempList;
    elementNum++;
}

void elvalaszto(){
    cout << "----||----" << endl;
}

void printListElementsToConsole(){
    cout << "\t\t DATUM \t\t IDOTARTAM \t FONTOSSAG" << endl;
    for (int i = 0; i < elementNum; ++i) {
        cout << "A(z) " << (i+1) <<". teendo:\t" << list[i].getDatum() << "\t" << list[i].getIdotartam() << "\t\t" << list[i].getFontossag() <<endl;
    }
    elvalaszto();
}

int main() {
    int menu = 0;
    do{
        cout << "\t Teendo hozzadasa: 1" << endl;
        cout << "\t Teendok megtekintese: 2" << endl;
        cout << "\t Kilepes: 0" << endl;
        cin >> menu;

        if(menu == 1){
            string tempdatum;
            string tempidotartam;
            int tempfontossag;

            cout << "Adja meg a teendo datumat:" << endl;
            cin >> tempdatum;
            cout << "Adja meg a teendo idotartamat:" << endl;
            cin >> tempidotartam;
            cout << "Adja meg a teendo fontossagat:" << endl;
            cin >> tempfontossag;

            putLast(Teendok(tempdatum, tempidotartam, tempfontossag));
        } else if(menu == 2){
            printListElementsToConsole();
        }
    }while(menu > 0);

    cout << "Vegleges teendok:" << endl;
    printListElementsToConsole();

    cout << "Lefutottam" << endl;
    return 0;
}
