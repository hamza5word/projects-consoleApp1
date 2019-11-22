#include "stdafx.h"
#include "Stagier.h"


Stagier::Stagier() : Person()
{
	this->type = STAGIER;
	this->salaire = 0.0;
}

Stagier::Stagier(Stagier const & T) : Person(T.prenom, T.nom, *T.date_reccrut, T.telefone)
{
	this->type = STAGIER;
	this->salaire = 0.0;
}

Stagier::Stagier(std::string const & prenom, std::string const & nom) : Person(prenom, nom)
{
	this->type = STAGIER;
	this->salaire = 0.0;
}

Stagier::Stagier(std::string const & prenom, std::string const & nom, Date const & date_reccrut) : 
	Person(prenom, nom)
{
	this->date_reccrut = new Date(date_reccrut);
	this->type = STAGIER;
	this->salaire = 0.0;
}

Stagier::Stagier(std::string const & prenom, std::string const & nom, Date const & date_reccrut, std::string const & telefone) :
	Person(prenom, nom)
{
	this->date_reccrut = new Date(date_reccrut);
	this->telefone = telefone;
	this->type = STAGIER;
	this->salaire = 0.0;
}


Stagier::~Stagier()
{
}

Stagier Stagier::operator=(Stagier const & T)
{
	if (*this != T) {
		this->prenom = T.prenom;
		this->nom = T.nom;
		this->date_reccrut = new Date(*T.date_reccrut);
		this->telefone = T.telefone;
	}
	return *this;
}

void Stagier::print() const
{
	Person::print();
	std::cout << "Salaire du Person     : " << this->salaire << "DH" << std::endl;
	std::cout << "Type du fonctionnaire : Stagier" << std::endl;
}

std::ostream & operator<<(std::ostream & flux, Stagier & P)
{
	flux << "*({Stagier}-------[" << P.code << "]-[" << P.nom << " " << P.prenom << "],[" << *P.date_reccrut << "],[" << P.telefone << "],["
		 << P.salaire << "DH])";
	return flux;
}
