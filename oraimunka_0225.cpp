#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class AutoAlkatresz {
private:
	int suly, gyartasiEv, ar;
	string marka;

public:
	AutoAlkatresz(int _suly, int _gyartasiEv, string _marka, int _ar) {
		suly = _suly;
		gyartasiEv = _gyartasiEv;
		marka = _marka;
		ar = _ar;
	}

	int getSuly() {
		return suly;
	}

	int getGyartasiEv() {
		return gyartasiEv;
	}

	string getMarka() {
		return marka;
	}

	int getAr() {
		return ar;
	}
};

vector<AutoAlkatresz> autoAlkatreszek;

void readFile() {
	ifstream input("autoalkatreszek.txt");
	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			unsigned long splitIndex = line.find('\t');
			string readLine = line.substr(splitIndex+1, line.size());
			string marka = line.substr(0, splitIndex);

			splitIndex = readLine.find('\t');
			int gyartasiEv = stoi(readLine.substr(0, splitIndex));
			readLine = readLine.substr(splitIndex+1, readLine.size());

			splitIndex = readLine.find('\t');
			int suly = stoi(readLine.substr(0, splitIndex));
			readLine = readLine.substr(splitIndex + 1, readLine.size());

			int ar = stoi(readLine.substr(0, readLine.size()));

			autoAlkatreszek.push_back(AutoAlkatresz(suly, gyartasiEv, marka, ar));
		}
	}
	input.close();
}

int main() {
	readFile();
	for (int i = 0; i < autoAlkatreszek.size(); i++) {
		cout << "==========" << endl;
		cout << "(" << (i + 1) << ") " << autoAlkatreszek[i].getMarka() << ":" << endl;
		cout << "\tSULY:\t" << autoAlkatreszek[i].getSuly() << "kg" << endl;
		cout << "\tGY. EV:\t" << autoAlkatreszek[i].getGyartasiEv() << endl;
		cout << "\tAR:\t" << autoAlkatreszek[i].getAr() << "ft" << endl;
		cout << "==========" << endl;
	}
}
