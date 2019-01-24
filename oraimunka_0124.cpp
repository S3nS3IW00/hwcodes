#include <iostream>
#include <string>

using namespace std;

char tomb[100] = "norqipenwabhqxygapjtuevfufnsyfwkibhlfrzpefpnisqnvmbtcbogcqtspednjbpbghahujfrxobntdedydyjlzrmaljeneo";
char szamosTomb[100] = "ly658jh2qar0z5h1mgl3tz2d7vm783uwcojm4ab7fcm4k25yypj3sdmdsqwa4hmm4rh51kopptnj32vphhxhjx0d862pw7mhd4";

int main() {
	for (int i = 0; i < 100; i++) {
		if (tomb[i] == 't') {
			tomb[i] = '\t';
		} else if (tomb[i] == 'm') {
			tomb[i] = '\n';
		}
	}

	for (int i = 0; i < 100; i++) {
		cout << tomb[i];
	}

	cout << endl;

	for (int i = 0; i < 100; i++) {
		if (szamosTomb[i] == '3') {
			cout << "e";
		}
		else if (szamosTomb[i] == '5') {
			cout << "s";
		}
		else if (szamosTomb[i] == '1') {
			cout << "i";
		}
		else if(szamosTomb[i] == '7') {
			cout << "z";
		}
		else if (szamosTomb[i] == '0') {
			cout << "o";
		}
		else {
			cout << szamosTomb[i];
		}
	}

	cout << endl;

    cout << "Lefutottam!" << endl; 
}
