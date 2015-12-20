
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
	double input;

	do {
		cout << "Skriv in ett reellt tal som representerar en temperatur i kelvin skalan. Skriv 0 för att avsluta: ";
		cin >> input;

		while (input < 0) {
			cout <<  "Värdet får ej vara mindra än 0, försök igen: ";
			cin >> input;
		}

		cout << input << " Kelvin motsvarar " << input - 273.15 << " grader Celsius eller " << input * 1.8 - 495.67 << " grader Fahrenheit." << "\n";
	} while (input != 0);

	cout << "Slut.";

	return 0;
}
