#include <iostream>
#define TOMBMERET 10

using namespace std;

int globalisTomb[TOMBMERET];

bool csere(int index1, int index2){
    int temp;
    if(index1 >= 0 && index2 >= 0 && index1 < TOMBMERET && index2 < TOMBMERET){
        temp = globalisTomb[index1];
        globalisTomb[index1] = globalisTomb[index2];
        globalisTomb[index2] = temp;
        return true;
    }
    return false;
}

void feltolt(){
    for(int i =0; i < TOMBMERET; i++){
        cin >> globalisTomb[i];
    }
}

void bubbleSort()
{
   int i, j;
   for (i = 0; i < TOMBMERET-1; i++)
       for (j = 0; j < TOMBMERET-i-1; j++)
           if (globalisTomb[j] > globalisTomb[j+1])
              csere(j, j+1);
}

void kiir(){
    for(int i = 0; i < TOMBMERET; i++){
        cout << "A tomb " << (i+1) << ". eleme: " << globalisTomb[i] << endl;
    }
}

int main()
{
    feltolt();
    kiir();
    csere(2, 3);
    kiir();
    bubbleSort();
    kiir();


    cout << "Lefutottam!" << endl;
    return 0;
}
