#pragma once
#include "Person.h"
class Nontitulaire :
	public Person
{
public:
	Nontitulaire();
	Nontitulaire(Nontitulaire const& T);
	Nontitulaire(std::string const& prenom, std::string const& nom, Grade const & grade);
	Nontitulaire(std::string const& prenom, std::string const& nom, Date const& date_reccrut, Grade const & grade);
	Nontitulaire(std::string const& prenom, std::string const& nom, Date const& date_reccrut, std::string const& telefone, Grade const& grade);
	virtual ~Nontitulaire();

	Nontitulaire operator=(Nontitulaire const& T);
	friend std::ostream& operator<<(std::ostream& flux, Nontitulaire & P);

	void setGrade(Grade const& grade);
	Grade getGrade() const;

	void print() const;

protected:
	void calcSalaire();

private:
	Grade *grade;
};

