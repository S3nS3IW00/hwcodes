#include "pch.h"
#include <string>
#include <iostream>
#include "oraimunka_1130.h"

using namespace std;

class Tanulo
{
public:
	Tanulo() {}
	Tanulo(string _nev, int _eletkor, int _igazolvany) {
		nev = _nev;
		eletkor = _eletkor;
		igazolvany = _igazolvany;
	}
	~Tanulo() {}

	string getNev() {
		return nev;
	}

	int getEletkor() {
		return eletkor;
	}

	void setEletkor(int _eletkor) {
		eletkor = _eletkor;
	}

	int getIgazolvany() {
		return igazolvany;
	}

private:
	string nev;
	unsigned int eletkor;
	unsigned int igazolvany;
};

class Osztaly
{

private:
	Tanulo *list = nullptr;
	int elementNum = 0;

public:
	Osztaly() {}
	~Osztaly() {}

	void addTanulo(Tanulo newElement) {
		Tanulo *tempList = new Tanulo[elementNum + 1];
		for (int i = 0; i < elementNum; i++) {
			tempList[i] = list[i];
		}
		tempList[elementNum] = newElement;
		if(list) delete[] list;
		list = tempList;
		elementNum++;
	}

	void swap(int index1, int index2) {
		Tanulo temp = list[index1];
		list[index1] = list[index2];
		list[index2] = temp;
	}

	void sort() {
		int i, j;
		for (i = 0; i < elementNum - 1; i++)
			for (j = 0; j < elementNum - i - 1; j++)
				if (list[j].getEletkor() > list[j + 1].getEletkor())
					swap(j, j+1);
	}

	int getMaximumEletkor() {
		int temp = 0;
		for (int i = 0; i < elementNum; i++) {
			if (temp < list[i].getEletkor()) {
				temp = list[i].getEletkor();
			}
		}
		return temp;
	}

	int getMinimumEletkor() {
		int temp = getMaximumEletkor();
		for (int i = 0; i < elementNum; i++) {
			if (temp > list[i].getEletkor()) {
				temp = list[i].getEletkor();
			}
		}
		return temp;
	}

	void printAllTanulo() {
		cout << "\t\t NEV \t ELETKOR \t IGAZOLVANY" << endl;
		for (int i = 0; i < elementNum; i++) {
			cout << "\t" << (i + 1) << ".\t" << list[i].getNev() << "\t\t" << list[i].getEletkor() << "\t" << list[i].getIgazolvany() << endl;
		}
	}
};



int main()
{
	Osztaly o;
	Tanulo t1("Berci", 19, 53774);
	Tanulo t("Balu", 21, 67368);
	Tanulo t2("Rita", 21, 74686);

	o.addTanulo(t);
	o.addTanulo(t1);
	o.addTanulo(t2);

	o.printAllTanulo();

	cout << "Minimum eletkor: " << o.getMinimumEletkor() << endl;
	cout << "Maximum eletkor: " << o.getMaximumEletkor() << endl;

	o.sort();
	
	cout << "Sorba rendezett lista eletkor szerint: " << endl;

	o.printAllTanulo();

    std::cout << "Lefutottam\n"; 
}
