#pragma once
#include "Commune.h"
class Group
{
public:
	Group();
	Group(std::string const& nom);
	~Group();

	Commune operator[](std::string const& nom);
	Commune operator[](unsigned int index);

	static int getGroupsN();
	unsigned int getCommN() const;
	void setNom(std::string const& nom);
	std::string getNom() const;
	void addCommune(Commune * C);
	void addCommune(std::string const& nom);
	void changeCommune(std::string const& nom, Commune * C);
	void changeCommune(unsigned int index, Commune *C);
	void changeName(std::string const& current, std::string const& newer);
	void deleteCommune(std::string const& nom);
	void deleteCommune(unsigned int index);
	Commune *getCommune(std::string const& nom);
	Commune *getCommune(unsigned int index);

	void print() const;
	bool isIn(Person *P);

private:
	static int groups_number;
	unsigned int gid;
	std::string nom;
	std::vector<Commune*> group;
};

