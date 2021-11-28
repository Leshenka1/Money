#pragma once
#include <iostream>
#include <exception>
using namespace std;
class money
{
protected:
	double pound, shilling, penny,remainder;

public:
	money(double = 0, double = 0, double = 0);
	void SetPound(double _pound);
	double GetPound() const;
	void SetShilling(double _pound);
	double GetShilling() const;
	void SetPenny(double _pound);
	double GetPenny() const;

	money operator + (const money& p) const;
	money operator - (const money& p) const;
	money operator - () const;
	money operator += (const money& p)const;
	money operator -= (const money& p)const;
	bool operator == (const money & p)const;


	friend ostream& operator << (ostream&, const money&);
};

