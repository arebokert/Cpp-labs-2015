#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct word_entry {
  word_entry(const string& inputWord) {
    word = inputWord;
    quantity = 1;
  }

  bool operator <(const word_entry& rhs) const {
    return word < rhs.word;
  }

  string word;
  int quantity;
};

void insert(vector<word_entry>& wordList, string& word) {
  int insertPos{ -1 };
  bool found{ false };
  transform(word.begin(), word.end(), word.begin(), tolower);
  for (int i{ 0 }; i < wordList.size(); i++) {
    if (wordList.at(i).word > word && insertPos == -1) {
      insertPos = i;
    }
    if (wordList.at(i).word == word) {
      wordList.at(i).quantity++;
      found = true;
    }
  }
  if (!found) {
    if (insertPos == -1 && wordList.size() >= 0) {
      insertPos = wordList.size();
    } 
	else if(insertPos == -1){
      insertPos = 0;
    }
    word_entry newWord{ word };
    wordList.insert(wordList.begin() + insertPos, newWord);
  }
}

void print(const vector<word_entry>& wordList) {
  cout << setw(10) << "Ord" << setw(7) << "Antal" << endl;
  for (int i{ 0 }; i < wordList.size(); i++) {
    cout << "\n" 
	 << setw(10) 
	 << wordList.at(i).word 
	 << setw(3) 
	 << wordList.at(i).quantity;
  }
}

int main(){
  vector<word_entry> wordList;

  cout << "Skriv ett eller flera ord: ";

  string tempWord;
  while (cin >> tempWord) {
	  insert(wordList, tempWord);
  }

  print(wordList);

  return 0;
}
