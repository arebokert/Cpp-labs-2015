#ifndef MONETARY_ERROR_H
#define MONETARY_ERROR_H

class monetary_error : public std::exception
{
	using string = std::string;
public:
	monetary_error(const string m) :msg(m) {}
	const char* what() { return msg.c_str(); }
private:
	string msg;
};
#endif
