#pragma once
#include "Person.h"
class Titulaire :
	public Person
{
public:
	Titulaire();
	Titulaire(Titulaire const& T);
	Titulaire(std::string const& prenom, std::string const& nom, std::string const & situation_familiale, unsigned int nombre_enfants, Grade const & grade);
	Titulaire(std::string const& prenom, std::string const& nom, Date const& date_reccrut, std::string const & situation_familiale, unsigned int nombre_enfants, Grade const & grade);
	Titulaire(std::string const& prenom, std::string const& nom, Date const& date_reccrut, std::string const& telefone, std::string const& situation_familiale, unsigned int nombre_enfants, Grade const& grade);
	virtual ~Titulaire();

	Titulaire operator=(Titulaire const& T);
	friend std::ostream& operator<<(std::ostream& flux, Titulaire & P);

	void setSitFam(std::string const& situation_familiale);
	std::string getSitFam() const;
	void setNbEnf(unsigned int nombre_enfants);
	unsigned int getNbEnf() const;
	void setGrade(Grade const& grade);
	Grade getGrade() const;

	void print() const;

protected :
	void calcSalaire();

private :
	std::string situation_familiale;
	unsigned int nombre_enfants;
	Grade *grade;
};

