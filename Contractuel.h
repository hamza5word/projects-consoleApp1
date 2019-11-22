#pragma once
#include "Person.h"
class Contractuel :
	public Person
{
public:
	Contractuel();
	Contractuel(double salaire);
	Contractuel(Contractuel const& T);
	Contractuel(std::string const& prenom, std::string const& nom, double salaire);
	Contractuel(std::string const& prenom, std::string const& nom, Date const& date_reccrut, double salaire);
	Contractuel(std::string const& prenom, std::string const& nom, Date const& date_reccrut, std::string const& telefone, double salaire);
	virtual ~Contractuel();

	Contractuel operator=(Contractuel const& T);
	friend std::ostream& operator<<(std::ostream& flux, Contractuel & P);

	void print() const;
};

