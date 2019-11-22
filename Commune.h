#pragma once
#include<vector>
#include "Titulaire.h"
#include "Nontitulaire.h"
#include "Contractuel.h"
#include "Stagier.h"
#include "Person.h"

class Commune
{
public:
	Commune();
	Commune(Commune const& C);
	Commune(std::string const& nom);
	Commune(std::string const& nom, std::string const& adresse);
	Commune(std::string const& nom, std::string const& adresse, std::string const& telefone);
	~Commune();

	bool operator==(Commune const& C) const;
	bool operator!=(Commune const& C) const;
	Commune operator=(Commune const& C);
	friend std::ostream& operator<<(std::ostream& flux, Commune const& C);

	unsigned int getPersN() const;
	void setNom(std::string const& nom);
	std::string getNom() const;
	void setAdresse(std::string const& adresse);
	std::string getAdresse() const;
	void setTelefone(std::string const& telefone);
	std::string getTelefone() const;
	void updateList(std::vector<Person*> list);
	std::vector<Person*> getList() const;

	void print() const;

private:
	std::string nom;
	std::string adresse;
	std::string telefone;
	std::vector<Person*> list;
};
