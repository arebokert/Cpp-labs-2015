#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void print_table(int n) {
	cout << "\n" << setw(6) << "DEC" << setw(6) << "OCT" << setw(6) << "HEX";
	for (int i = 1; i <= n; i++) {
		cout << "\n" << setw(6) << dec << i << setw(6) << oct << i << setw(6) << hex << i;
	}
}

int main() {
	int input;

	cout << "Skriv ett hetal större än eller lika med 1: ";
	cin >> input;

	while (!cin || input < 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max());
		cout << "\n" << "Heltalet måste vara mer eller lika med 1, försök igen: ";
		cin >> input;
	}

	print_table(input);
	return 0;
}
