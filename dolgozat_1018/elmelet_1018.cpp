#include <iostream>
#define TOMBMERET 10 //definiálunk egy méretet a tömbünknek.
using namespace std;

int tomb[TOMBMERET]; //létrehozzuk a tömbünket, mely egész számokst tud tárolni és mérete a definiált érték.

//ezzel a függvénnyel feltöltjük az indexekkel megegyezõ értékekkel a tömbünket egy ciklus segítségével.
void elsoFuggveny(){
    for (int index = 0; index < TOMBMERET; ++index) {
        tomb[index]=index;
    }
}

//ezzel a függvénnyel kiíratjuk a tömbünk elemeit egy for ciklussal.
void masodikFuggveny(){
    for (int index = 0; index < TOMBMERET; ++index) {
        cout<<"A tomb ["<<index<<"] eleme = "<<tomb[index]<<endl;
    }
}

//ezzel a függvénnyel egy szöveget írunk ki, mely egy elválasztást szimbolizál.
void harmadikFuggveny(){
    cout<<"-----||-----"<<endl;
}

int main() {
    masodikFuggveny(); //kiíratjuk a tömbök elemeit.
    harmadikFuggveny(); //elválasztót rakunk.

    elsoFuggveny(); //feltöltjük a tömbünket.
    masodikFuggveny(); //kiíratjuk a tömbök elemeit.

    harmadikFuggveny(); //elválasztót rakunk.
    std::cout << "Lefutottam!" << std::endl;

    return 0;
    }
