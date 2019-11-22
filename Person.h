#pragma once
#include<iostream>
#include <string>
#include "Date.h"
#include "Grade.h"
#define TITULAIRE 1
#define NON_TITULAIRE 2
#define CONTRACTUEL 3
#define STAGIER 4

class Person
{
public:
	Person();
	Person(Person const& P);
	Person(std::string const& prenom, std::string const& nom);
	Person(std::string const& prenom, std::string const& nom, Date const& date_reccrut);
	Person(std::string const& prenom, std::string const& nom, Date const& date_reccrut, std::string const& telefone);
	~Person();

	bool operator==(Person const& D) const;
	bool operator!=(Person const& D) const;
	Person operator=(Person const& P);
	friend std::ostream& operator<<(std::ostream& flux, Person & P);

	static int getPersonNumber();
	int getCode() const;
	void setPrenom(std::string const& prenom);
	std::string getPrenom() const;
	void setNom(std::string const& nom);
	std::string getNom() const;
	void setDate(int day, int mounth, int year);
	void setDate(Date const& date_reccrut);
	Date getDate() const;
	void setTelefon(std::string const& telefone);
	std::string getTelefon() const;

	virtual void print() const;
	double getSalaire() const;
	unsigned int Ptype() const;

protected:
	static int personsNumber;
	int code;
	std::string nom;
	std::string prenom;
	Date *date_reccrut;
	std::string telefone;
	double salaire;
	unsigned int type;
};

