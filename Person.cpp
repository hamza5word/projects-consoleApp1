#include "stdafx.h"
#include "Person.h"

int Person::personsNumber = 0;

Person::Person() : prenom("unnamed"), nom("unnamed"), date_reccrut(new Date()), telefone("0")
{
	personsNumber++;
	this->code = personsNumber;
}

Person::Person(Person const & P) : prenom(P.prenom), nom(P.nom), date_reccrut(new Date(*P.date_reccrut)), telefone(0)
{
	personsNumber++;
	this->code = personsNumber;
}

Person::Person(std::string const& prenom,std::string const& nom) : prenom(prenom), nom(nom), date_reccrut(new Date()), telefone("0")
{
	personsNumber++;
	this->code = personsNumber;
}

Person::Person(std::string const& prenom, std::string const& nom, Date const& date_reccrut) :  prenom(prenom), nom(nom), date_reccrut(new Date(date_reccrut)), telefone(0)
{
	personsNumber++;
	this->code = personsNumber;
}

Person::Person(std::string const& prenom, std::string const& nom, Date const& date_reccrut, std::string const& telefon) : prenom(prenom), nom(nom), date_reccrut(new Date(date_reccrut)), telefone(telefon)
{
	personsNumber++;
	this->code = personsNumber;
}


Person::~Person()
{
}

bool Person::operator==(Person const & P) const
{
	return (this->prenom == P.prenom && this->nom == P.nom && *this->date_reccrut == *P.date_reccrut && this->telefone == P.telefone);
}

bool Person::operator!=(Person const & P) const
{
	return !(*this == P);
}

Person Person::operator=(Person const & P)
{
	if (*this != P)
	{
		this->prenom = P.prenom;
		this->nom = P.nom;
		//*this->birthday = *P.birthday;                    // STATIC SYNTAX
		this->date_reccrut = new Date(*(P.date_reccrut));			// DYNAMIC SYNTAX
		this->telefone = P.telefone;
	}
	return *this;
}

int Person::getPersonNumber()
{
	return personsNumber;
}

int Person::getCode() const
{
	return this->code;
}

void Person::setPrenom(std::string const & prenom)
{
	this->prenom = prenom;
}

std::string Person::getPrenom() const
{
	return this->prenom;
}

void Person::setNom(std::string const& nom)
{
	this->nom = nom;
}

std::string Person::getNom() const
{
	return this->nom;
}

void Person::setDate(int day, int mounth, int year)
{
	this->date_reccrut = new Date(day, mounth, year);
}

void Person::setDate(Date const& date_reccrut)
{
	this->date_reccrut = new Date(date_reccrut);
}

Date Person::getDate() const
{
	return *this->date_reccrut;
}

void Person::setTelefon(std::string const& telefone)
{
	this->telefone = telefone;
}

std::string Person::getTelefon() const
{
	return this->telefone;
}



void Person::print() const
{
	std::cout << "Code Person           : " << this->code << std::endl;
	std::cout << "Identificateur Person : " << this->prenom << " " << this->nom << std::endl;
	std::cout << "Date de reccrutement  : "; this->date_reccrut->print();
	std::cout << "Telefone du Person    : " << this->telefone << std::endl;
}

double Person::getSalaire() const
{
	return this->salaire;
}

unsigned int Person::Ptype() const
{
	return this->type;
}



std::ostream & operator<<(std::ostream & flux, Person & P)
{
	flux << "([" << P.code << "][" << P.nom << " " << P.prenom << "],[" << *P.date_reccrut << "],[" << P.telefone << "])";
	return flux;
}
