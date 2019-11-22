#include "stdafx.h"
#include "Nontitulaire.h"


Nontitulaire::Nontitulaire() :
	Person(), grade(new Grade())
{
	this->type = NON_TITULAIRE;
	this->calcSalaire();
}

Nontitulaire::Nontitulaire(Nontitulaire const & T) :
	Person(T.prenom, T.nom, *T.date_reccrut, T.telefone) , grade(new Grade(*T.grade))
{
	this->type = NON_TITULAIRE;
	this->calcSalaire();
}

Nontitulaire::Nontitulaire(std::string const & prenom, std::string const & nom, Grade const & grade) :
	Person(prenom, nom), grade(new Grade(grade))
{
	this->type = NON_TITULAIRE;
	this->calcSalaire();
}

Nontitulaire::Nontitulaire(std::string const & prenom, std::string const & nom, Date const & date_reccrut,
	Grade const & grade) :
	Person(prenom, nom) , grade(new Grade(grade))	
{
	this->date_reccrut = new Date(date_reccrut);
	this->type = NON_TITULAIRE;
	this->calcSalaire();
}

Nontitulaire::Nontitulaire(std::string const & prenom, std::string const & nom, Date const & date_reccrut,
	std::string const & telefone, Grade const & grade) :
	Person(prenom, nom), grade(new Grade(grade))
{
	this->date_reccrut = new Date(date_reccrut);
	this->telefone = telefone;
	this->type = NON_TITULAIRE;
	this->calcSalaire();
}


Nontitulaire::~Nontitulaire()
{
}

Nontitulaire Nontitulaire::operator=(Nontitulaire const & T)
{
	if (*this != T) {
		this->prenom = T.prenom;
		this->nom = T.nom;
		this->date_reccrut = new Date(*T.date_reccrut);
		this->telefone = T.telefone;
		this->grade = new Grade(*T.grade);
		this->salaire = T.salaire;
	}
	return *this;
}

void Nontitulaire::setGrade(Grade const & grade)
{
	this->grade = new Grade(grade);
	this->calcSalaire();
}

Grade Nontitulaire::getGrade() const
{
	return *this->grade;
}

void Nontitulaire::print() const
{
	Person::print();
	std::cout << "Grade du Person       : "; this->grade->print();
	std::cout << "Salaire du Person     : " << this->salaire << "DH" << std::endl;
	std::cout << "Type du fonctionnaire : Non Titulaire" << std::endl;
}

void Nontitulaire::calcSalaire()
{
	this->salaire = (this->grade->getSValue()*0.8);
}

std::ostream & operator<<(std::ostream & flux, Nontitulaire & P)
{
	flux << "*({Non-Titulaire}-[" << P.code << "]-[" << P.nom << " " << P.prenom << "],[" << *P.date_reccrut << "],[" << P.telefone << "],["
		 << *P.grade << "],[" << P.salaire << "DH])";
	return flux;
}
