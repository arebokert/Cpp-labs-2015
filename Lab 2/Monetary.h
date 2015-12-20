#ifndef MONETARY_H
#define MONTEARY_H

namespace monetary {
  
  class monetary_error : public std::exception
  {
  using string = std::string;
  public:
    monetary_error(const string m) :msg(m) {}
    const char* what() { return msg.c_str(); }
  private:
    string msg;
  };
  
  class Money
  {

  public:
    using string = std::string;


    Money() = default;

    Money(const int& unit, const int& centesimal = 0);

    Money(const string& currency, const int& unit = 0, const int& centesimal = 0);

    Money(const Money& other);


    Money& operator=(const Money& other);

    Money operator+(const Money& other);

    bool operator>(const Money& other);

    bool operator<(const Money& other);

    bool operator<=(const Money& other);

    bool operator>=(const Money& other);

    bool operator==(const Money& other);

    bool operator!=(const Money& other);

    void swap(Money& other) noexcept {
      std::swap(_currency, other._currency);
      std::swap(_unit, other._unit);
      std::swap(_centesimal, other._centesimal);
    };

    friend std::ostream& operator<<(std::ostream& os, const Money& other);
    Money& operator++();
    Money operator++(int);

    void print(std::ostream& os);

    string currency() const;


  private:
    string _currency;
    int _unit;
    int _centesimal;
    inline bool _unitLessThanZero() {
      throw monetary_error("Unit may not be less than zero.");
    };
    inline bool _centesimalLessThanZero() {
      throw monetary_error("Centesimal may not be less than zero.");
    };
    inline bool _centesimalMoreThanMax() {
      throw monetary_error("Centesimal may not be more than 99.");
    };
    inline bool _currencyLengthMoreThanMax() {
      throw monetary_error("Currency name may not be longer than three letters.");
    };
  };
  std::ostream& operator<<(std::ostream& os, const Money& other);
}

#endif
