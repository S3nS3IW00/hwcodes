#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void hatvany(int szam, int n){
    int osszeg = szam;
    for(int i = 0; i < n-1; i++){
        osszeg*=szam;
    }
    cout << osszeg;
}

void fpiramis(int meret){
    for(int i = meret; i > 0; i--){
        for(int j = i; j > 0; j--){
            cout << j;
        }
        cout << endl;
    }
}

int main()
{
    for (int i = 1; i <= 10; ++i){
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    hatvany(3, 2);
    cout << endl;
    fpiramis(4);
    return 0;
}
