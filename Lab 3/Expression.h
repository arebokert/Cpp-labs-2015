/*
 * Expression.h
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iosfwd>
#include <stdexcept>
#include <string>

/**
 * expression_error: kastas om fel inträffar i en Expression- operation;
 * ett diagnostiskt meddelande ska skickas med.
 */
// ATT GÖRA!

/**
 * Expression: Klass för att representera ett enkelt aritmetiskt uttryck.
 */
 
class expression_error : public std::logic_error
{
 public:
  using logic_error::logic_error;
};
 
class Expression
{
 public:
  // OBSERVERA: DETTA ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

 Expression(class Expression_Tree* tree = nullptr) : _tree{tree} {}
  Expression(Expression&&) noexcept;
  Expression(const Expression&);
  long double evaluate() const;
  std::string get_postfix() const;
  bool        empty() const;
  void        print_tree(std::ostream&) const;
  void        swap(Expression&) noexcept;
  Expression& operator=(const Expression&) & noexcept;
  Expression& operator=(Expression&&) & noexcept;
  ~Expression();
 protected:
  Expression_Tree* _tree;
};



/**
 * swap: Byter innehåll på två Expression-objekt.
 */
void swap(Expression&, Expression&) noexcept;

/**
 * make_expression: Hjälpfunktion för att skapa ett Expression-objekt, givet
 * ett infixuttryck i form av en sträng.
 */
Expression make_expression(const std::string& infix);

#endif
