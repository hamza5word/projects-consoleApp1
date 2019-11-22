#pragma once
#include <iostream>

class Grade
{
public:
	Grade();
	Grade(double salaire_base);

	Grade operator+(Grade const& G) const;
	Grade operator-(Grade const& G) const;
	bool operator==(Grade const& G) const;
	void operator+=(Grade const& G);
	void operator-=(Grade const& G);
	bool operator !=(Grade const& G) const;
	bool operator >(Grade const& G) const;
	bool operator <(Grade const& G) const;
	bool operator >=(Grade const& G) const;
	bool operator <=(Grade const& G) const;
	friend std::ostream& operator <<(std::ostream& flux, Grade const& G);

	void setSValue(double salaire_base);
	double getSValue();
	char getCG() const;
	~Grade();

	void print() const;
protected :
	void setCG();
private:
	char code_grade;
	double salaire_base;
};

