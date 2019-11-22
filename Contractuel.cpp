#include "stdafx.h"
#include "Contractuel.h"


Contractuel::Contractuel() : Person()
{
	this->type = CONTRACTUEL;
	this->salaire = 0.0;
}

Contractuel::Contractuel(double salaire) : Person()
{
	this->type = CONTRACTUEL;
	this->salaire = salaire;
}

Contractuel::Contractuel(Contractuel const & T) : Person(T.prenom, T.nom, *T.date_reccrut, T.telefone)
{
	this->type = CONTRACTUEL;
	this->salaire = T.salaire;
}

Contractuel::Contractuel(std::string const & prenom, std::string const & nom, double salaire) : Person(prenom, nom)
{
	this->type = CONTRACTUEL;
	this->salaire = salaire;
}

Contractuel::Contractuel(std::string const & prenom, std::string const & nom, Date const & date_reccrut, double salaire) :
	Person(prenom, nom, date_reccrut)
{
	this->date_reccrut = new Date(date_reccrut);
	this->type = CONTRACTUEL;
	this->salaire = salaire;
}

Contractuel::Contractuel(std::string const & prenom, std::string const & nom, Date const & date_reccrut, 
	std::string const & telefone, double salaire) :
		Person(prenom, nom)
{
	this->date_reccrut = new Date(date_reccrut);
	this->telefone = telefone;
	this->type = CONTRACTUEL;
	this->salaire = salaire;
}

Contractuel::~Contractuel()
{
}

Contractuel Contractuel::operator=(Contractuel const & T)
{
	if (*this != T) {
		this->prenom = T.prenom;
		this->nom = T.nom;
		this->date_reccrut = new Date(*T.date_reccrut);
		this->telefone = T.telefone;
		this->salaire = T.salaire;
	}
	return *this;
}

void Contractuel::print() const
{
	Person::print();
	std::cout << "Salaire du Person     : " << this->salaire << "DH" << std::endl;
	std::cout << "Type du fonctionnaire : Contractuel" << std::endl;
}


std::ostream & operator<<(std::ostream & flux, Contractuel & P)
{
	flux << "*({Contractuel}---[" << P.code << "]-[" << P.nom << " " << P.prenom << "],[" << *P.date_reccrut << "],[" << P.telefone << "],["
		 << P.salaire << "DH])";
	return flux;
}
