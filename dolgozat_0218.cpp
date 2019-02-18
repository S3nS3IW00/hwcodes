//created by Dani 12/D
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Car {
private:
	string plate;
	int strength;

public:
	Car(string _plate, int _strength) {
		plate = _plate;
		strength = _strength;
	}

	string &getPlate() {
		return plate;
	}

	int getStrenght(){
		return strength;
	}
};

vector<Car> cars;

string maximumStrengthCar() {
	int strength = cars[0].getStrenght();
	string plate = cars[0].getPlate();
	for (int i = 0; i < cars.size(); i++) {
		if (cars[i].getStrenght() > strength) {
			strength = cars[i].getStrenght();
			plate = cars[i].getPlate();
		}
	}
	return plate;
}

int main(){
	ifstream readFile("fajlom.txt");
	if (readFile.is_open()) {
		string line;
		while (getline(readFile, line)) {
			int splitIndex = line.find('\t');
			string plate = line.substr(0, splitIndex);
			int strength = stoi(line.substr(splitIndex, line.size()));
			cars.push_back(Car(plate, strength));
		}
	}
	cout << "Legnagyobb loerovel rendelkezo auto rendszama: " << maximumStrengthCar() << endl;
}
