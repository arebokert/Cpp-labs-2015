#include <exception>
#include <string>
#include <iostream>
#include <utility>
#include "Monetary.h"

using namespace monetary;

Money::Money(const int& unit, const int& centesimal) {
  if (unit < 0) {
    _unitLessThanZero();
  }
  else if (centesimal > 99) {
    _centesimalMoreThanMax();
  }
  else if (centesimal < 0) {
    _centesimalLessThanZero();
  }
  else {
    _centesimal = centesimal;
    _unit = unit;
    _currency = "";
  }
}

Money::Money(const string& currency, const int& unit, const int& centesimal) {
  if (currency.length() > 3) {
    _currencyLengthMoreThanMax();
  }
  else if (unit < 0) {
    _unitLessThanZero();
  }
  else if (centesimal > 99) {
    _centesimalMoreThanMax();
  }
  else if (centesimal < 0) {
    _centesimalLessThanZero();
  }
  else {
    _currency = currency;
    _unit = unit;
    _centesimal = centesimal;
  }
}

bool Money::checkComparisonObject(const Money& other, const string& operand) const{
  Money tmp{other};
  if ((_currency != "") && (tmp._currency != _currency) && (operand == "=")) {
    throw monetary_error("Cannot assign different currency money objects to eachother.");
    return false;
  }
  else if ((_currency != "") && (other._currency != "") && (other._currency != _currency) && (operand == "+")) {
    throw monetary_error("Cannot add different currency money objects to eachother.");
    return false;
  }
  else if ((_unit + other._unit < 0) || (_centesimal + other._centesimal < 0) && (operand == "+")) {
    throw monetary_error("Result of adding two money objects cannot be less than zero.");
    return false;
  }
  else if ((_currency != "") && (other._currency != "") && (other._currency != _currency) && ((operand == "<") || (operand == "==")) ) {
    throw monetary_error("Can not compare two different currencies.");
    return false;
  }
  else {
    return true;
  }
}

double Money::convertMoneyToSingle(const Money& other) const{
  return (double)other._unit + ((double)other._unit / 100); 
}

Money Money::operator=(const Money& other) &  
{
  Money tmp{other};
  if (!checkComparisonObject(other, "=")) {
  }
  else if ((_currency != "") && (other._currency == "")) {
    std::swap(_unit, tmp._unit);
    std::swap(_centesimal, tmp._centesimal);
  }
  else {
    swap(tmp);
  }
  return *this;
}

Money Money::operator+(const Money& other) const
{
  Money tmp{};
  if(checkComparisonObject(other, "+")){
    tmp._unit = _unit + other._unit;
    tmp._centesimal = _centesimal + other._centesimal;
    if (tmp._centesimal >= 100) {
      tmp._unit++;
      tmp._centesimal -= 100;
    }
    tmp._currency = _currency;
  }
  return tmp;
}

bool Money::operator<(const Money& other) const
{
  checkComparisonObject(other, "<");
  double temp1 = convertMoneyToSingle(*this);
  double temp2 = convertMoneyToSingle(other);
  return temp1 < temp2;
}

bool Money::operator==(const Money& other) const
{
  checkComparisonObject(other, "==");
  double temp1 = convertMoneyToSingle(*this);
  double temp2 = convertMoneyToSingle(other);
  return temp1 == temp2;
}

bool Money::operator>(const Money& other) const
{
  return !((*this < other) || (*this == other)); 
}
bool Money::operator<=(const Money& other) const
{
  return (*this < other) || (*this == other);
}
bool Money::operator>=(const Money& other) const
{
  return !(*this < other);
}
bool Money::operator!=(const Money& other) const
{
  return !(*this == other);
}

std::ostream& monetary::operator<<(std::ostream& os, const Money& other)
{
  other.print(os);
  return os;
}

Money Money::operator++(int)
{
  Money tmp = *this;
  _centesimal++;
  return tmp;
}

Money& Money::operator++() {
  _centesimal++;
  return *this;
}

void Money::print(std::ostream& os) const{
  if (_centesimal < 10 && _currency.empty()) {
    os << _unit << "." << "0" << _centesimal;
  }
  else if (_centesimal < 10 && !_currency.empty()) {
    os << _currency << " " << _unit << "." << "0" << _centesimal;
  }
  else if (_currency.empty()) {
    os << _unit << "." << _centesimal;
  }
  else if (!_currency.empty()) {
    os << _currency << " " << _unit << "." << _centesimal;
  }
}


std::string Money::currency() const {
  return _currency;
}
