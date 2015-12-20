#include <string>
#include <iostream>
using namespace std;

int main() {
  string tempLine;
  string cinInput;
  int resultCount[5]{ 0,0,0,0,0 };


  cout << "Skriv in en text som ska räknas, avsluta med EOF(Ctrl + Z): ";
  while (getline(cin, tempLine)) {
    cinInput += tempLine + "\n";
  }

  for (char& c : cinInput) {
    if (iswalpha(c)) {
      resultCount[0]++;
    }
    else if (iswdigit(c)) {
      resultCount[1]++;
    }
    else if (iswpunct(c)) {
      resultCount[2]++;
    }
    else if (iswspace(c)) {
      resultCount[3]++;
    }
    resultCount[4]++;

  }

  cout << "Indata innehöll:\n" 
       << resultCount[0] 
       << " alfabetiska tecken\n" 
       << resultCount[1] 
       << " siffertecken\n" 
       << resultCount[2] 
       << " interpunktionstecken\n" 
       << resultCount[3] 
       << " vita tecken\n" 
       << resultCount[4] 
       << " tecken totalt";
  return 0;
}
