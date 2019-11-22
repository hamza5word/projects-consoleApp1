#include "stdafx.h"
#include "Grade.h"
#include "math.h"

Grade::Grade() : salaire_base(0.0), code_grade(0)
{
	this->setCG();
}

Grade::Grade(double salaire_base) : salaire_base(salaire_base)
{
	this->setCG();
}

Grade Grade::operator+(Grade const & G) const
{
	Grade S;
	S.salaire_base = this->salaire_base + G.salaire_base;
	return S;
}

Grade Grade::operator-(Grade const & G) const
{
	Grade S;
	S.salaire_base = fabs(this->salaire_base - G.salaire_base);
	return S;
}

bool Grade::operator==(Grade const & G) const
{
	return (this->salaire_base == G.salaire_base);
}

void Grade::operator+=(Grade const & G)
{
	*this = *this + G;
}

void Grade::operator-=(Grade const & G)
{
	*this = *this - G;
}

bool Grade::operator!=(Grade const & G) const
{
	return !(*this == G);
}

bool Grade::operator>(Grade const & G) const
{
	return (this->salaire_base > G.salaire_base);
}

bool Grade::operator<(Grade const & G) const
{
	return !(*this > G || *this == G);
}

bool Grade::operator>=(Grade const & G) const
{
	return (*this > G || *this == G);
}

bool Grade::operator<=(Grade const & G) const
{
	return (*this < G || *this == G);
}


void Grade::setSValue(double salaire_base)
{
	this->salaire_base = salaire_base;
	this->setCG();
}

double Grade::getSValue()
{
	return this->salaire_base;
}

char Grade::getCG() const
{
	return this->code_grade;
}

Grade::~Grade()
{
}

void Grade::print() const
{
	std::cout << this->salaire_base << " CG [" << this->code_grade << "]" << std::endl;
}

void Grade::setCG()
{
	if (!salaire_base) code_grade = 'X';
	if (salaire_base >= 1000 && salaire_base < 3000) code_grade = 'D';
	if (salaire_base >= 3000 && salaire_base < 5000) code_grade = 'C';
	if (salaire_base >= 5000 && salaire_base < 7000) code_grade = 'B';
	if (salaire_base >= 7000 && salaire_base < 10000) code_grade = 'A';
}

std::ostream & operator<<(std::ostream & flux, Grade const & G)
{
	flux << G.salaire_base << "DH [" << G.code_grade << "]";
	return flux;
}
