#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Food {
private:
	string name;
	int cal;

public:
	Food(string _name, int _cal){
		name = _name;
		cal = _cal;
	}

	string &getName() {
		return name;
	}

	int getCal() {
		return cal;
	}

};

vector<Food> foods;

void readFile() {
	ifstream read("fajl.txt");
	if (read.is_open()) {
		string line;
		while (getline(read, line)) {
			int splitIndex = line.find("-");
			string name = line.substr(0, splitIndex);
			int cal = stoi(line.substr(splitIndex, line.size()));
			foods.push_back(Food(name, cal));
		}
	}
	read.close();
}

string getMaxCalFoodName() {
	string name = foods[0].getName();
	int cal = foods[0].getCal();
	for (int i = 0; i < foods.size(); i++) {
		if (foods[i].getCal() > cal) {
			name = foods[i].getName();
			cal = foods[i].getCal();
		}
	}
	return name;
}

string getMinCalFoodName() {
	string name = foods[0].getName();
	int cal = foods[0].getCal();
	for (int i = 0; i < foods.size(); i++) {
		if (foods[i].getCal() < cal) {
			name = foods[i].getName();
			cal = foods[i].getCal();
		}
	}
	return name;
}

int main(){
	readFile();
	cout << "Legkisebb kaloriat tartalmazo etel: " << getMinCalFoodName() << endl;
	cout << "Legtobb kaloriat tartalmazo etel: " << getMaxCalFoodName() << endl;
}
