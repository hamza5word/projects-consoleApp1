#include "stdafx.h"
#include "Titulaire.h"


Titulaire::Titulaire() :
	Person(), situation_familiale("unadded"), nombre_enfants(0), grade(new Grade())
{
	this->type = TITULAIRE;
	this->calcSalaire();
}

Titulaire::Titulaire(Titulaire const & T) :
	Person(T.prenom, T.nom, *T.date_reccrut, T.telefone), situation_familiale(T.situation_familiale),
	nombre_enfants(T.nombre_enfants), grade(new Grade(*T.grade))
{
	this->type = TITULAIRE;
	this->calcSalaire();
}


Titulaire::Titulaire(std::string const& prenom, std::string const& nom, std::string const & situation_familiale, 
	unsigned int nombre_enfants, Grade const & grade) :
		Person(prenom, nom), situation_familiale(situation_familiale), nombre_enfants(nombre_enfants), 
	grade(new Grade(grade))
{
	this->type = TITULAIRE;
	this->calcSalaire();
}

Titulaire::Titulaire(std::string const& prenom, std::string const& nom, Date const & date_reccrut,
	std::string const & situation_familiale, unsigned int nombre_enfants, Grade const & grade) :
	Person(prenom, nom), situation_familiale(situation_familiale), nombre_enfants(nombre_enfants),
	grade(new Grade(grade))
{
	this->date_reccrut = new Date(date_reccrut);
	this->type = TITULAIRE;
	this->calcSalaire();
}


Titulaire::Titulaire(std::string const& prenom, std::string const& nom, Date const & date_reccrut, std::string const & telefone,
	std::string const & situation_familiale, unsigned int nombre_enfants, Grade const & grade) : 
	Person(prenom,nom), situation_familiale(situation_familiale), nombre_enfants(nombre_enfants),
	grade(new Grade(grade))
{
	this->date_reccrut = new Date(date_reccrut);
	this->telefone = telefone;
	this->type = TITULAIRE;
	this->calcSalaire();
}

Titulaire::~Titulaire()
{
}

Titulaire Titulaire::operator=(Titulaire const & T)
{
	if (*this != T) {
		this->prenom = T.prenom;
		this->nom = T.nom;
		this->date_reccrut = new Date(*T.date_reccrut);
		this->telefone = T.telefone;
		this->situation_familiale = T.situation_familiale;
		this->nombre_enfants = T.nombre_enfants;
		this->grade = new Grade(*T.grade);
		this->salaire = T.salaire;
	}
	return *this;
}

void Titulaire::setSitFam(std::string const & situation_familiale)
{
	this->situation_familiale = situation_familiale;
}

std::string Titulaire::getSitFam() const
{
	return this->situation_familiale;
}

void Titulaire::setNbEnf(unsigned int nombre_enfants)
{
	this->nombre_enfants = nombre_enfants;
	this->calcSalaire();
}

unsigned int Titulaire::getNbEnf() const
{
	return this->nombre_enfants;
}

void Titulaire::setGrade(Grade const & grade)
{
	this->grade = new Grade(grade);
	this->calcSalaire();
}

Grade Titulaire::getGrade() const
{
	return *this->grade;
}

void Titulaire::print() const
{
	Person::print();
	std::cout << "Situation familliale  : " << this->situation_familiale << std::endl;
	std::cout << "Nombre des enfants    : " << this->nombre_enfants << std::endl;
	std::cout << "Grade du Person       : "; this->grade->print(); 
	std::cout << "Salaire du Person     : " << this->salaire << "DH" << std::endl;
	std::cout << "Type du fonctionnaire : Titulaire" << std::endl;
}

void Titulaire::calcSalaire()
{
	this->salaire = (this->grade->getSValue() + (this->nombre_enfants * 150));
}

std::ostream & operator<<(std::ostream & flux, Titulaire & P)
{
	flux << "*({Titulaire}-----[" << P.code << "]-[" << P.nom << " " << P.prenom << "],[" << *P.date_reccrut << "],[" << P.telefone << "],["
		 << P.situation_familiale << "],[" << P.nombre_enfants << "],[" << *P.grade << "],[" << P.salaire << "DH])";
	return flux;
}
