
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
	double input;

	do {
		cout << "Skriv in ett reellt tal som representerar en temperatur i kelvin skalan. Skriv 0 f�r att avsluta: ";
		cin >> input;

		while (input < 0) {
			cout <<  "V�rdet f�r ej vara mindra �n 0, f�rs�k igen: ";
			cin >> input;
		}

		cout << input << " Kelvin motsvarar " << input - 273.15 << " grader Celsius eller " << input * 1.8 - 495.67 << " grader Fahrenheit." << "\n";
	} while (input != 0);

	cout << "Slut.";

	return 0;
}
