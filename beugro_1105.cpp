#include <iostream>

using namespace std;

bool piramis(){
    int meret;
    cin >> meret;
    if(meret > 0){
        for(int i = 0; i < meret; i++){
            for(int j = i; j < meret; j++){
                cout << "A";
            }
            cout << endl;
        }
        return true;
    }
    return false;
}

int main()
{
    piramis();

    cout << "Lefutottam!" << endl;
    return 0;
}
