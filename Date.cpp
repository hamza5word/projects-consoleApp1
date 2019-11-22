#include "stdafx.h"
#include "Date.h"
#include <math.h>
#include <string>
using namespace std;

Date::Date() : day(0), mounth(0), year(0)
{
}

Date::Date(Date const & D) : day(fabs(D.day)), mounth(fabs(D.mounth)), year(fabs(D.year))
{
}

Date::Date(int day, int mounth, int year) : day(fabs(day)), mounth(fabs(mounth)), year(fabs(year))
{
	this->adjust();
}


Date::~Date()
{
}

Date Date::operator+(Date const & D) const
{
	Date S;
	S.day = this->day + D.day;
	S.mounth = this->mounth + D.mounth;
	S.year = (this->year >= D.year) ? this->year : D.year;
	S.adjust();
	return S;
}

Date Date::operator-(Date const & D) const
{
	Date S;
	S.day = fabs(this->day - D.day);
	S.mounth = fabs(this->mounth - D.mounth);
	S.year = (this->year <= D.year) ? this->year : D.year;
	S.adjust();
	return S;
}

bool Date::operator==(Date const & D) const
{
	return (this->day == D.day && this->mounth == D.mounth && this->year == D.year);
}

void Date::operator+=(Date const & D)
{
	*this = *this + D;
	this->year = D.year;
	this->adjust();
}

void Date::operator-=(Date const & D)
{
	*this = *this - D;
	this->year = D.year;
	this->adjust();
}

bool Date::operator!=(Date const & D) const
{
	return !(*this == D);
}

bool Date::operator>(Date const & D) const
{
	if (this->year > D.year) return true;
	else if (this->year == D.year && this->mounth > D.mounth) return true;
	else if (this->mounth == D.year && this->day > D.day) return true;
	else return false;
}

bool Date::operator<(Date const & D) const
{
	return !(*this > D || *this == D);
}

bool Date::operator>=(Date const & D) const
{
	return (*this > D || *this == D);
}

bool Date::operator<=(Date const & D) const
{
	return (*this < D || *this == D);
}


void Date::setday(int day)
{
	if (day > 0 && day <= 31) this->day = day;
}

int Date::getday()
{
	return this->day;
}

void Date::setmounth(int mounth)
{
	if (mounth > 0 && mounth <= 12) this->mounth = mounth;
}

int Date::getmounth()
{
	return this->mounth;
}

void Date::setyear(int year)
{
	if(year > 0) this->year = fabs(year);
}

int Date::getyear()
{
	return this->year;
}

void Date::print() const
{
	if (this->day == 0 || this->mounth == 0 || this->year == 0) cout << "Date not registred yet !" << endl;
	else {
		const string mounths[12] = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
		cout << this->day << " " << mounths[this->mounth - 1] << " " << this->year << " " << std::endl;
	}
}

void Date::adjust()
{
	while (fabs(this->day) > 31) {
			this->mounth++;
			this->day -= 31;
	}
	while (fabs(this->mounth) > 12) {
			this->year++;
			this->mounth -= 12;
	}
}

std::ostream & operator<<(std::ostream & flux, Date const & D)
{
	// TODO: insert return statement here
	flux << D.day << "/" << D.mounth << "/" << D.year;
	return flux;
}



