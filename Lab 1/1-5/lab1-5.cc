
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

void build_lists(ifstream&, List_Node*, List_Node*);

int main(int argc, char* argv[])
{

  List_Node* list_1{nullptr};
  List_Node* list_2{nullptr};

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
      if (empty(list_1))
	cout << "Lista 1 är tom.\n";
      else
	cout << "Lista 1 är inte tom.\n";

      if (empty(list_2))
	cout << "Lista 2 är tom.\n";
      else
	cout << "Lista 2 är inte tom.\n";
      build_lists(input, list_1, list_2);
    }
  }
	
  cout << "Lista 1 efter inläsning av namn:\n";
  print(list_1, cout);
  cout << "Lista 2 efter inläsning av namn:\n";
  print(list_2, cout);

  /*cout << "Lista 1 utskriven i omvänd ordning:\n";
  print_reversed(list_1, cout);

	
  cout << "Lista 1 vänds.\n";
  reverse(list_1);
  cout << "Lista 1 efter vändning:\n";
  print(list_1, cout);

  cout << "Lista 2 raderas.\n";
  clear(list_2);
	
  if (empty(list_2))
    cout << "Lista 2 är tom.\n";
  else
    cout << "Lista 2 är inte tom.\n";
	
  cout << "Lista 2 tilldelas en kopia av lista 1.\n";
  list_2 = copy(list_1);
  cout << "Lista 2 innehåller:\n";
  print(list_2, cout);

	
  cout << "Lista 2 raderas.\n";
  clear(list_2);

	
  cout << "Lista 1 och 2 byter innehåller.\n";
  swap(list_1, list_2);
  if (empty(list_1))
    cout << "Lista 1 är tom.\n";
  else
    cout << "Lista 1 är inte tom.\n";
  cout << "Lista 2 innehåller:\n";
  print(list_2, cout);

  cout << "Lista 2 raderas.\n";
  clear(list_2);

  if (empty(list_1))
    cout << "Lista 1 är tom.\n";
  else
    cout << "Lista 1 är inte tom.\n";

  if (empty(list_2))
    cout << "Lista 2 är tom.\n";
  else
    cout << "Lista 2 är inte tom.\n";

  cout << "Programmet avslutas.\n";
	*/
  return 0;
}



void build_lists(ifstream& input, List_Node* list_1, List_Node* list_2) {
  for (string line; getline(input, line); )
    {
      string name = line.substr(0, line.find(" "));
      int age = stoi(line.substr(line.find(" "), line.length()));
      append(list_2, name, age);
      //insert(list_1, name, age);
    }
  input.close();
}

