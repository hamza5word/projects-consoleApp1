#include "stdafx.h"
#include "Group.h"

int Group::groups_number = 0;

Group::Group() : nom("unnamed")
{
	groups_number++;
	this->gid = groups_number;
}

Group::Group(std::string const & nom) : nom(nom)
{
	groups_number++;
	this->gid = groups_number;
}


Group::~Group()
{
}

Commune Group::operator[](std::string const & nom)
{
	return *this->getCommune(nom);
}

Commune Group::operator[](unsigned int index)
{
	return *this->getCommune(index);
}


int Group::getGroupsN() 
{
	return groups_number;
}

unsigned int Group::getCommN() const
{
	return this->group.size();
}

void Group::setNom(std::string const & nom)
{
	this->nom = nom;
}

std::string Group::getNom() const
{
	return this->nom;
}

void Group::addCommune(Commune * C)
{
	this->group.push_back(C);
}

void Group::addCommune(std::string const & nom)
{
	Commune *C = new Commune(nom);
	this->group.push_back(C);
}

void Group::changeCommune(std::string const & nom, Commune * C)
{
	for (unsigned int i(0); i < this->group.size(); ++i) {
		if (this->group[i]->getNom() == nom) *this->group[i] = *C;
	}
}

void Group::changeCommune(unsigned int index, Commune * C)
{
	if (index < this->group.size()) *this->group[index] = *C;
}

void Group::changeName(std::string const & current, std::string const & newer)
{
	for (unsigned int i(0); i < this->group.size(); ++i) {
		if (this->group[i]->getNom() == nom) this->group[i]->setNom(newer);
	}
}

void Group::deleteCommune(std::string const & nom)
{
	for (unsigned int i(0); i < this->group.size(); ++i) {
		if (this->group[i]->getNom() == nom) this->group.erase(this->group.begin() + i);
	}
}

void Group::deleteCommune(unsigned int index)
{
	if (index < this->group.size()) this->group.erase(this->group.begin() + index);
}

Commune * Group::getCommune(std::string const & nom)
{
	for (unsigned int i(0); i < this->group.size(); ++i) {
		if (this->group[i]->getNom() == nom) return this->group[i];
	}
	return NULL;
}

Commune * Group::getCommune(unsigned int index)
{
	if (index < this->group.size()) return this->group[index];
	return NULL;
}

void Group::print() const
{
	std::cout << " GROUP " << this->gid << "  {" << this->nom << "}  " << this->group.size() << " Communes " << std::endl << std::endl;
	for (unsigned int i(0); i < this->group.size(); ++i) {
		this->group[i]->print();
		std::cout << "______________________________________M___________________________________" << std::endl;
	}
}


