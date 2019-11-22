#include "stdafx.h"
#include "Commune.h"


Commune::Commune() : nom("unnamed"), adresse("unknown"), telefone("0"), list(0)
{
}

Commune::Commune(Commune const & C) : nom(C.nom), adresse(C.adresse), telefone(C.telefone), list(C.list)
{
}

Commune::Commune(std::string const & nom) : nom(nom), adresse("unknown"), telefone("0"), list(0)
{
}

Commune::Commune(std::string const & nom, std::string const & adresse) : nom(nom), adresse(adresse), telefone("0"), list(0)
{
}

Commune::Commune(std::string const & nom, std::string const & adresse, std::string const & telefone) :
	nom(nom), adresse(adresse), telefone(telefone), list(0)
{
}


Commune::~Commune()
{
}

bool Commune::operator==(Commune const & C) const
{
	return (this->nom == C.nom && this->adresse == C.adresse && this->telefone == C.telefone);
}
 
bool Commune::operator!=(Commune const & C) const
{
	return !(*this == C);
}

Commune Commune::operator=(Commune const & C)
{
	if (*this != C) {
		this->nom = C.nom;
		this->adresse = C.adresse;
		this->telefone = C.telefone;
		this->list = C.list;
	}
	return *this;
}

unsigned int Commune::getPersN() const
{
	return this->list.size();
}

void Commune::setNom(std::string const & nom)
{
	this->nom = nom;
}

std::string Commune::getNom() const
{
	return this->nom;
}

void Commune::setAdresse(std::string const & adresse)
{
	this->adresse = adresse;
}

std::string Commune::getAdresse() const
{
	return this->adresse;
}

void Commune::setTelefone(std::string const & telefone)
{
	this->telefone = telefone;
}

std::string Commune::getTelefone() const
{
	return this->telefone;
}

void Commune::updateList(std::vector<Person*> list)
{
	this->list = list;
}

std::vector<Person*> Commune::getList() const
{
	return this->list;
}

void Commune::print() const
{
	int P(0), P2(0), P3(0), P4(0);
	std::cout << "Nom du Commune      : " << this->nom << std::endl;
	std::cout << "Adresse du Commune  : " << this->adresse << std::endl;
	std::cout << "Telefone du Commune : " << this->telefone << std::endl;
	std::cout << "Nombre des Persons  : " << this->list.size() << std::endl;
	std::cout << "Liste des Persons du Commune : " << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	if (!this->list.size()) std::cout << "Liste Vide !! Pas de Persons" << std::endl;
	else {
		for (unsigned int i(0); i < this->list.size(); ++i) {
			if (list[i]->Ptype() == TITULAIRE) { std::cout << *dynamic_cast<Titulaire*>(list[i]) << std::endl; P++; }
			if (list[i]->Ptype() == NON_TITULAIRE) { std::cout << *dynamic_cast<Nontitulaire*>(list[i]) << std::endl; P2++; }
			if (list[i]->Ptype() == CONTRACTUEL) { std::cout << *dynamic_cast<Contractuel*>(list[i]) << std::endl; P3++; }
			if (list[i]->Ptype() == STAGIER) { std::cout << *dynamic_cast<Stagier*>(list[i]) << std::endl; P4++; }
		}
		std::cout << "---------------------------------------------------------------------" << std::endl;
		std::cout << "Titulaires(" << P << ") Non-Titulaires(" << P2 << ") Contractuels(" << P3 << ") Stagiers(" << P4 << ")" <<  std::endl;
	}
}

std::ostream & operator<<(std::ostream & flux, Commune const & C)
{
	flux << "([" << C.nom << "],[" << C.adresse << "],[" << C.telefone << "],[<" << C.list.size() << ">Persons])";
	return flux;
}
