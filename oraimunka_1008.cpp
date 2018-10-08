#include <iostream>
#define TOMBMERET 10

using namespace std;

int globalisTomb[TOMBMERET];

void feltolt(){
    int* pointer;
    pointer = globalisTomb;
    for(int i = 0; i < TOMBMERET; i++){
        *pointer = i;
        pointer++;
    }
}

int main()
{
    int tomb[10];
    for(int i = 0; i < 10; i++){
        tomb[i] = i;
        cout << "tomb " << i << ". elemenek a cime: " << &tomb[i] << "\terteke: " << tomb[i] << endl;
    }
    cout << "----||----" << endl;

    int* pointer;
    pointer = tomb;
    cout << "Pointer hova mutat: " << pointer << endl;
    cout << "Pointer ahova mutat, ott mi van: " << *pointer << endl;
    cout << "Pointer cime: " << &pointer << endl;
    cout << "----||----" << endl;

    pointer++;
    cout << "Pointer hova mutat: " << pointer << endl;
    cout << "Pointer ahova mutat, ott mi van: " << *pointer << endl;
    cout << "Pointer cime: " << &pointer << endl;
    cout << "----||----" << endl;

    feltolt();
    for(int i = 0; i < TOMBMERET; i++){
        cout << "globalisTomb " << i << ". elemenek a cime: " << &globalisTomb[i] << "\terteke: " << globalisTomb[i] << endl;
    }
    cout << "----||----" << endl;

    cout << "Lefutottam" << endl;
    return 0;
}
