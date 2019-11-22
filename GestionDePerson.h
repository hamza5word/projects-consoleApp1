#pragma once
#include "Group.h"
#include "Titulaire.h"
#include "Nontitulaire.h"
#include "Contractuel.h"
#include "Stagier.h"
#include "Commune.h"
class GestionDePerson
{
public:
	~GestionDePerson();

	Person *subscribe();
	Commune *newPerson(Commune * C);
	Commune *newPerson(Commune * C, Person * P);
	Commune *editPerson(Commune *C, int code, Person *P);
	Commune *deletePerson(Commune *C, Person *P);
	Commune *deletePerson(Commune *C, int code);
	std::vector<Person*> getTilutaires(Commune * C);
	std::vector<Person*> getNonTilutaires(Commune * C);
	std::vector<Person*> getContractuels(Commune * C);
	std::vector<Person*> getStagiers(Commune * C);
	Person *getPersonByCode(Commune * C, int code);
	Person *getPersonByIden(Commune * C, std::string const& prenom, std::string const& nom);
	std::vector<Person*> getPersonsByGrade(Commune * C, Grade *G);
	int occurPerson(Commune * C, Person *P);
	bool isIn(int Code,Group G);
	bool isIn(std::string prenom, std::string nom, Group G);
	int getMyCode(Commune * C, std::string const& prenom, std::string const& nom);
	int getIndexOf(Commune * C, std::string const& prenom, std::string const& nom);
	void showList(Commune * C);
};

