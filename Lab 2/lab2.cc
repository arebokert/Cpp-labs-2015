#include <string>
#include <iostream>
#include "Monetary.h"

using namespace monetary;
using namespace std;

int main(){
  cout << "Testing faulty constructors and operators." << endl;
  try {
    // Create money object with faulty unit
    Money money1{-1};
  }
  catch (monetary_error e) {
    cout << "Error in try block 1: " << e.what() << endl;
  }

  try {
    // Create money object with faulty centesimal
    Money money1{ 100, -1 };
  }
  catch (monetary_error e) {
    cout << "Error in try block 2: " << e.what() << endl;
  }

  try {
    // Create money object with too large centesimal
    Money money1{ 100, 100 };
  }
  catch (monetary_error e) {
    cout << "Error in try block 3: " << e.what() << endl;
  }

  try {
    // Create money object with too long currency
    Money money1{ "SEK1" };
  }
  catch (monetary_error e) {
    cout << "Error in try block 4: " << e.what() << endl;
  }

  try {
    // Try to compare two money objects of different currencies
    Money money3{ "USD", 100, 50 };
    Money money4{ "SEK", 100, 50 };
    if (money3 == money4) {

    }
  }
  catch (monetary_error e) {
    cout << "Error in try block 5: " << e.what() << endl;
  }

  try {
    // Try to add two money objects of different currencies
    Money money3{ "USD", 100, 50 };
    Money money4{ "SEK", 100, 50 };
    money3 + money4;
  }
  catch (monetary_error e) {
    cout << "Error in try block 6: " << e.what() << endl;
  }

  try {
    // Try to add two money objects resulting in less than zero
    Money money3{ "USD", -200, 50 };
    Money money4{ "SEK", 100, 50 };
    money3 + money4;
  }
  catch (monetary_error e) {
    cout << "Error in try block 7: " << e.what() << endl;
  }

  try {
    // Try general usercase
    Money money4{ "USD", 55, 60 };
    Money money5{ "USD", 100, 50 };
    Money money6 = money4 + money5;
    cout << "Trying print function of money object with USD, 55 units and 60 centesimals." << endl;
    money4.print(cout);
    cout << endl;

    cout << "Trying print function of two money objects added. Should be USD, 156 units and 10 centesimals." << endl;
    money6.print(cout);
    cout << endl;

    cout << "Trying overload of bit shift operator on money object with USD, 55 units and 60 centesimals." << endl;
    cout << money4 << endl;

    cout << "Trying overload of equals operator. Is 55.60 USD more than 100.50 USD?" << endl;
    if (money4 > money5) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    cout << "Is it less?" << endl;
    if (money4 < money5) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    cout << "Is it less or equal?" << endl;
    if (money4 <= money5) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    cout << "Is it more or equal?" << endl;
    if (money4 >= money5) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    cout << "Setting money object equal to another money object. Do they contain the same values?" << endl;
    money4 = money5;
    if (money4 == money5) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }

    cout << "Trying overload of increment operator on money object with USD, 100 units and 50 centesimals." << endl;
    cout << "Value before increment with postfix: " << money4++ << endl;
    cout << "Value after increment: " << money4 << endl;
    cout << "Value after another increment with prefix: " << ++money4 << endl;

    cout << "Trying currency() fucntion on money object with USD, 100 units and 50 centesimals." << endl;
    cout << money4.currency();
  }
  catch (monetary_error e) {
    cout << "Error in try block where no error should be thrown: " << e.what() << endl;
  }

  return 0;
}
