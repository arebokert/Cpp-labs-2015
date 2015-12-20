
// Inkluderingar efter behov

// Deklarera en funktion build_lists(inström, list_1, list_2) som läser namn 
// från inströmmen och använder insert() för att sätta in i list_1 och append()
// för att sätta in i list_2. build_lists() ska definieras efter main().

// Komplettera och modifiera:

#include <iostream>
#include <sstream>
#include <fstream>
#include "List.h"

using namespace std;

void build_lists(ifstream&, List&, List&);


int main(int argc, char* argv[])
{

  List list_1;
  List list_2;

  if (argc != 2) {
    cout << "Du måste fylla i ett filnamn att öppna som parameter när du kör detta program.";
    return 1;
  }
  else {
    ifstream input(argv[1]);
    if (!input.is_open()) {
      cout << "Filen kunde ej öppnas.";
      return 2;
    }
    else {
      if (list_1.empty())
	cout << "Lista 1 är tom.\n";
      else
	cout << "Lista 1 är inte tom.\n";

      if (list_2.empty())
	cout << "Lista 2 är tom.\n";
      else
	cout << "Lista 2 är inte tom.\n";

      build_lists(input, list_1, list_2);
    }
  }
	
  cout << "Lista 1 efter inläsning av namn:\n";
  list_1.print();
  cout << "Lista 2 efter inläsning av namn:\n";
  list_2.print();

  cout << "Lista 1 utskriven i omvänd ordning:\n";
  list_1.print_reversed();

	
  cout << "Lista 1 vänds.\n";
  list_1.reverse();
  cout << "Lista 1 efter vändning:\n";
  list_1.print();

  cout << "Lista 2 raderas.\n";
  list_2.clear();
	
  if (list_2.empty())
    cout << "Lista 2 är tom.\n";
  else
    cout << "Lista 2 är inte tom.\n";
	
  cout << "Lista 2 tilldelas en kopia av lista 1.\n";
  list_2 = list_1.copy();
  cout << "Lista 2 innehåller:\n";
  list_2.print();

	
  cout << "Lista 2 raderas.\n";
  list_2.clear();

	
  cout << "Lista 1 och 2 byter innehåller.\n";
  list_1.swap(list_2);
  if (list_1.empty())
    cout << "Lista 1 är tom.\n";
  else
    cout << "Lista 1 är inte tom.\n";
  cout << "Lista 2 innehåller:\n";
  list_2.print();

  cout << "Lista 2 raderas.\n";
  list_2.clear();

  if (list_1.empty())
    cout << "Lista 1 är tom.\n";
  else
    cout << "Lista 1 är inte tom.\n";

  if (list_2.empty())
    cout << "Lista 2 är tom.\n";
  else
    cout << "Lista 2 är inte tom.\n";

  cout << "Programmet avslutas.\n";
	
  return 0;
}

void build_lists(ifstream& input, List& list_1, List& list_2) {
  for (string line; getline(input, line); )
    {
      string name = line.substr(0, line.find(" "));
      int age = stoi(line.substr(line.find(" "), line.length()));
      list_2.append(name, age);
      list_1.insert(name, age);
    }
  input.close();
}
