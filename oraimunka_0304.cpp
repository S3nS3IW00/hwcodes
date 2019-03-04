#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Futo {
private:
	string name;
	int distances[3];

public:
	Futo(string _name, int _distances[3]) {
		name = _name;
		for (int i = 0; i < 3; i++) {
			distances[i] = _distances[i];
		}
	}

	string &getName() {
		return name;
	}

	int getDistance(int i) {
		return distances[i];
	}

	double averageDistance() {
		int all = 0;
		for (int i = 0; i < 3; i++) {
			all += distances[i];
		}
		return all / 3;
	}

	int minDistanceRanDay() {
		int distancePerDay = distances[0];
		for (int i = 0; i < 3; i++) {
			if (distances[i] < distancePerDay) {
				distancePerDay = distances[i];
			}
		}
		return distancePerDay;
	}

	int maxDistanceRanDay() {
		int distancePerDay = distances[0];
		for (int i = 0; i < 3; i++) {
			if (distances[i] > distancePerDay) {
				distancePerDay = distances[i];
			}
		}
		return distancePerDay;
	}
};

vector<Futo> futok;

void readFile() {
	ifstream readFile("fajlom.txt");
	if (readFile.is_open()) {
		string line;
		while (getline(readFile, line)) {
			unsigned long splitIndex = line.find('\t');
			string name = line.substr(0, splitIndex);
			string remain = line.substr(splitIndex+1, line.size());
			int distances[3];
			for (int i = 0; i < 3; i++) {
				splitIndex = remain.find('\t');
				string distance = remain.substr(0, splitIndex);
				unsigned long distanceSplit = distance.find(',');
				distance = distance.substr(0, distanceSplit) + distance.substr(distanceSplit + 1, distance.size());
				distances[i] = stoi(distance);
				remain = remain.substr(splitIndex + 1, remain.size());
			}
			futok.push_back(Futo(name, distances));
		}
	}
	readFile.close();
}

void printLines() {
	for (int i = 0; i < futok.size(); i++) {
		cout << "Nev: " << futok[i].getName() << endl;
		cout << "\tFutott tavolsagok:" << endl;
		cout << "\t\t1.: " << futok[i].getDistance(0) << endl;
		cout << "\t\t2.: " << futok[i].getDistance(1) << endl;
		cout << "\t\t3.: " << futok[i].getDistance(2) << endl;
	}
}

double runnersAveragePerDay(int day) {
	int all = 0;
	for (int i = 0; i < futok.size(); i++) {
		all += futok[i].getDistance(day-1);
	}
	return all / futok.size();
}

double runnersAverageAll() {
	int all = 0;
	for (int i = 0; i < futok.size(); i++) {
		all += futok[i].getDistance(0);
		all += futok[i].getDistance(1);
		all += futok[i].getDistance(2);
	}
	return all / (futok.size()*3);
}

void runnerMinDistanceRan() {

}

int main() {
	readFile();
	printLines();
}
