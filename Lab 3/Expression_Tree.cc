/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
// INKLUDERA F�R DET SOM KOMMER ATT ANV�NDAS I DENNA FIL!
using namespace std;

// SEPARATA DEFINITIONER F�R F�R EXPRESSION_TREE-KLASSERNA DEFINIERAS H�R.

Binary_Operator::~Binary_Operator()
{
  delete _lhs; 
  delete _rhs;
}

Binary_Operator::Binary_Operator(const Binary_Operator& op)
{
    
  _lhs = op._lhs->clone();
  try{
    _rhs = op._rhs->clone();
  }
  catch(std::bad_alloc& alloc_fail)
    {
      delete _lhs;
      throw;
    }
}

void Binary_Operator::print(ostream& os, int indentation) const
{
  indentation = indentation + 2;
  _rhs->print(os, indentation);
  os << std::setw(indentation - 2) << " /" << endl;
  os << std::setw(indentation - 3) << str() << endl;
  os << std::setw(indentation - 2) << "\\" << endl;
  _lhs->print(os, indentation);
}

string Binary_Operator::get_postfix() const
{
  return _lhs->get_postfix() + " " +_rhs->get_postfix() + " " + str();
}

string Operand::get_postfix() const
{
  return str();
}

void Operand::print(std::ostream& os, int indentation) const{
  os << std::setw(indentation) << str() << endl;
}

long double Assign::evaluate() const
{
  return _rhs->evaluate();
}

string Assign::str() const 
{
  return "=";
}

Expression_Tree* Assign::clone() const
{
  return new Assign{_lhs, _rhs};
}

long double Plus::evaluate() const
{
  return _lhs->evaluate() + _rhs->evaluate();
}

string Plus::str() const 
{
  return "+";
}

Expression_Tree* Plus::clone() const
{
  return new Plus{_lhs, _rhs};
}

long double Minus::evaluate() const
{
  return _lhs->evaluate() - _rhs->evaluate();
}

string Minus::str() const 
{
  return "-";
}

Expression_Tree* Minus::clone() const
{
  return new Minus{_lhs, _rhs};
}

long double Times::evaluate() const
{
  return _lhs->evaluate() * _rhs->evaluate();
}

string Times::str() const 
{
  return "*";
}

Expression_Tree* Times::clone() const
{
  return new Times{_lhs, _rhs};
}

long double Divide::evaluate() const
{
  if(_rhs->evaluate() == 0)
    {
      throw expression_tree_error("You may not divide by zero.");
    }
  else {
    return _lhs->evaluate() / _rhs->evaluate();        
  }
}

string Divide::str() const 
{
  return "/";
}

Expression_Tree* Divide::clone() const
{
  return new Divide{_lhs, _rhs};
}

long double Power::evaluate() const
{
  return std::pow(_lhs->evaluate(), _rhs->evaluate());
}

string Power::str() const 
{
  return "^";
}

Expression_Tree* Power::clone() const
{
  return new Power{_lhs, _rhs};
}

long double Integer::evaluate() const
{
  return _internalint;
}

string Integer::str() const
{
  return to_string(_internalint);
}

Expression_Tree* Integer::clone() const
{
  return new Integer{_internalint};
}

long double Real::evaluate() const
{
  return _internaldouble;
}

string Real::str() const
{
  std::stringstream temp_string;
  temp_string << _internaldouble;
  return temp_string.str();
}

Expression_Tree* Real::clone() const
{
  return new Real{_internaldouble};
}

long double Variable::evaluate() const
{
  return _value;
}

string Variable::str() const
{
  return _variable;
}

Expression_Tree* Variable::clone() const
{
  return new Variable{_variable};
}

void Variable::set_value(const long double value)
{
  _value = value;
}


