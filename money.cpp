#include <iostream>
#include "money.h"
using namespace std;

money transfer(double pound, double shilling, double penny)
{
	shilling = shilling + (int)(penny / 12);
	penny = penny - 12* (int)(penny / 12);
	pound = pound + (int)(shilling / 20);
	shilling = shilling - 20 * (int)(shilling / 20);
	return money(pound, shilling, penny);
}

void money::SetPound(double _pound)
{
	remainder = (((double)(int)((_pound - (int)_pound) * 480)) / 2);
	pound = (int)_pound;
}

double money::GetPound() const
{
	return pound;
}

void money::SetShilling(double _shilling)
{
	if (abs(_shilling) >= 20)
	{
		throw exception(" !!!amount of pounds should be less than 20!!! ");
	}
	remainder += (((double)(int)((_shilling - (int)_shilling) * 24)) / 2);
	shilling = (int)_shilling;
	pound += (int)(remainder / 240);
	remainder -= 240*(int)(remainder / 240);
}
  
double money::GetShilling() const
{
	return shilling;
}

void money::SetPenny(double _penny)
{
	if (abs(_penny) >= 20)
	{
		throw exception(" !!!amount of pounds should be less than 20!!! ");
	}
	remainder += _penny;
	shilling += (int)(remainder / 12);
	pound += (int)(shilling / 20);
	shilling -= (int)(shilling / 20)*20;
	remainder -= 12*(int)(remainder / 12);
	penny = remainder;
}

double money::GetPenny() const
{
	return penny;
}

money money::operator + (const money& p) const
{
	double Pound = pound + p.pound;
	double Shilling = shilling + p.shilling;
	double Penny = penny + p.penny;
	return transfer(Pound,Shilling,Penny);
}

money money::operator-(const money& p) const
{
	double Pound = pound - p.pound;
	double Shilling = shilling - p.shilling;
	double Penny = penny - p.penny;
	return transfer(Pound, Shilling, Penny);
}

money money::operator-() const
{
	return money(-pound, -shilling, -penny);
}

money money::operator += (const money& p) const
{
	double Pound = pound + p.pound;
	double Shilling = shilling + p.shilling;
	double Penny = penny + p.penny;
	return transfer(Pound, Shilling, Penny);
}

money money::operator-=(const money& p) const
{
	double Pound = pound - p.pound;
	double Shilling = shilling - p.shilling;
	double Penny = penny - p.penny;
	return transfer(Pound, Shilling, Penny);
}

bool money::operator==(const money& p) const
{
	return (pound==p.pound&&shilling==p.shilling&&penny==p.penny);
}



money::money(double _pound, double _shilling, double _penny)
{
	SetPound(_pound);
	SetShilling(_shilling);
	SetPenny(_penny);
}

ostream& operator<<(ostream& s, const money& d)
{
	if (d.pound != 0)
	{
		s << d.pound << "pd.";
	}
	if (d.shilling!=0)
	{ 
		s << d.shilling << "sh.";
	}
	if (d.penny != 0)
	{
		s << d.penny << "p.";
	}
	return s;
}
