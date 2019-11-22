#pragma once
#include <iostream>
class Date
{
public:
	Date();
	Date(Date const& D);
	Date(int day, int mounth, int year);
	~Date();

	Date operator+(Date const& D) const;
	Date operator-(Date const& D) const;
	bool operator==(Date const& D) const;
	void operator+=(Date const& D);
	void operator-=(Date const& D);
	bool operator !=(Date const& D) const;
	bool operator >(Date const& D) const;
	bool operator <(Date const& D) const;
	bool operator >=(Date const& D) const;
	bool operator <=(Date const& D) const;
	friend std::ostream& operator <<(std::ostream& flux, Date const& D);

	void setday(int day);
	int  getday();
	void setmounth(int mounth);
	int  getmounth();
	void setyear(int year);
	int  getyear();

	void print() const;
protected:
	void adjust();
private:
	int day;
	int mounth;
	int year;
};

