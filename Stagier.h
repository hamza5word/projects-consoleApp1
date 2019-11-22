#pragma once
#include "Person.h"
class Stagier :
	public Person
{
public:
	Stagier();
	Stagier(Stagier const& T);
	Stagier(std::string const& prenom, std::string const& nom);
	Stagier(std::string const& prenom, std::string const& nom, Date const& date_reccrut);
	Stagier(std::string const& prenom, std::string const& nom, Date const& date_reccrut, std::string const& telefone);
	virtual ~Stagier();

	Stagier operator=(Stagier const& T);
	friend std::ostream& operator<<(std::ostream& flux, Stagier & P);

	void print() const;
};

