/*
 * (1.) Feladat
 * Publikus oszt�ly
 */

include <iostream>

using namespace std;

class Klassz {
    public:
    int x, y;
    Klassz(int _x, int _y){
        x=_x;
        y=_y;
    }
};

int main {
    cout << "Lefutottam" << endl;
    return 0;
}


/*
 * (2.) Feladat
 * Karakter t�mb csere
 */

include <iostream>

using namespace std;

char tomb[100];

int main {
    for(int i = 0; i < 100; i++){
        if(tomb[i] == 'n'){
            tomb[i] = '\n';
        }
    }
    cout << "Lefutottam" << endl;
    return 0;
}