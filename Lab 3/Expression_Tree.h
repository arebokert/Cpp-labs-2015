/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>

/*
 * expression_error: kastas om ett fel inträffar i en Expression-operation;
 * ett diagnostiskt meddelande ska skickas med.
 */
// ATT GÖRA!


// OBSERVERA: NEDANSTÅENDE ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

/*
 * Expression_Tree: Abstrakt, polymorf basklass för alla trädnodklasser.
 */
using namespace std;

class expression_tree_error : public std::logic_error
{
 public:
  using logic_error::logic_error;
};

class Expression_Tree
{
 public:
 Expression_Tree& operator=(const Expression_Tree&) = delete;
  virtual long double evaluate() const = 0;
  virtual std::string get_postfix() const = 0;
  virtual std::string str() const = 0;
  virtual void print(ostream&, int) const = 0;
  virtual Expression_Tree* clone() const = 0;
  virtual ~Expression_Tree() = default;
};

class Binary_Operator : public Expression_Tree
{
 protected:
  Expression_Tree* _lhs;
  Expression_Tree* _rhs;
 Binary_Operator(Expression_Tree* lhs, Expression_Tree* rhs) : _lhs{lhs}, _rhs{rhs}{};
  Binary_Operator(const Binary_Operator&);
 public:
 Binary_Operator& operator=(const Binary_Operator&) = delete;
  ~Binary_Operator();
  std::string get_postfix() const override;
  void print(ostream&, int) const override;
};

class Operand : public Expression_Tree
{
 protected:
  Operand() = default;
  Operand(const Operand&) = default;
 public:
 Operand& operator=(const Operand&) = delete;  
  ~Operand() = default;
  std::string get_postfix() const override;
  void print(std::ostream&, int) const override;
};

class Assign : public Binary_Operator
{ 
 public:
 Assign& operator=(const Assign&) = delete;
  ~Assign() = default;
 Assign(Expression_Tree* lhs, Expression_Tree* rhs) : Binary_Operator(lhs, rhs) {};
  long double evaluate() const override;
  std::string str() const override;
  Assign* clone() const override;
};

class Plus : public Binary_Operator
{ 
 public:
 Plus& operator=(const Plus&) = delete;
  ~Plus() = default;
 Plus(Expression_Tree* lhs, Expression_Tree* rhs) : Binary_Operator(lhs, rhs) {};
  long double evaluate() const override;
  std::string str() const override;
  Plus* clone() const override;
};


class Minus : public Binary_Operator 
{
 public:
 Minus& operator=(const Minus&) = delete;
  ~Minus() = default;
 Minus(Expression_Tree* lhs, Expression_Tree* rhs) : Binary_Operator(lhs, rhs) {};
  long double evaluate() const override;
  std::string str() const override;
  Minus* clone() const override;
};

class Times : public Binary_Operator
{
 public:
 Times& operator=(const Times&) = delete;
  ~Times() = default;
 Times(Expression_Tree* lhs, Expression_Tree* rhs) : Binary_Operator(lhs, rhs) {};
  long double evaluate() const override;
  std::string str() const override;
  Times* clone() const override;
};

class Divide : public Binary_Operator
{
 public:
 Divide& operator=(const Divide&) = delete;
  ~Divide() = default;
 Divide(Expression_Tree* lhs, Expression_Tree* rhs) : Binary_Operator(lhs, rhs) {};
  long double evaluate() const override;
  std::string str() const override;
  Divide* clone() const override;
};

class Power: public Binary_Operator
{
 public:
 Power& operator=(const Power&) = delete;
  ~Power() = default;
 Power(Expression_Tree* lhs, Expression_Tree* rhs) : Binary_Operator(lhs, rhs) {};
  long double evaluate() const override;
  std::string str() const override;
  Power* clone() const override;
};

class Integer : public Operand
{
 private:
  long int _internalint;
 public:
 Integer& operator=(const Integer&) = delete;
  ~Integer() = default;
 Integer(const long int integer) : _internalint{integer} {};
  long double evaluate() const override;
  std::string str() const override;
  Integer* clone() const override;
};

class Real : public Operand
{
 private:
  long double _internaldouble;
 public:
 Real& operator=(const Real&) = delete;
  ~Real() = default;
 Real(const long double double_in) : _internaldouble{double_in} {};
  long double evaluate() const override;
  std::string str() const override;
  Real* clone() const override;
};

class Variable : public Operand
{
 private:
  std::string _variable;
  long double _value;
 public:
 Variable& operator=(const Variable&) = delete;
  ~Variable() = default;
 Variable(const std::string& variable) : _variable{variable} {};
  long double evaluate() const override;
  std::string str() const override;
  void set_value(const long double);
  long double get_value() const;
  Variable* clone() const override;
};

#endif
