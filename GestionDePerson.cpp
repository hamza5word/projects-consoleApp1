#include "stdafx.h"
#include "GestionDePerson.h"
using namespace std;
GestionDePerson::~GestionDePerson()
{
}

Person* GestionDePerson::subscribe() {
	// Readers
	string sreader; int nreader; double dreader;
	cout << "\t\t-----------------------------[Subscription formular]-----------------------------" << endl;
	cout << "\t\tAjoute manuelle du person numero N " << Person::getPersonNumber()+1 << endl;
	cout << endl;
	cout << "Choix du type du contract : " << endl << endl << "1-[Titulaire]		(<!> Salaire varie)" << endl <<
		"2-[Non-Titulaire]	(<!> Salaire varie)" << endl << "3-[Contractuel]		(<!> Salaire Fixe)"
		<< endl << "4-[Stagier]		(<!> Pas du Salaire)" << endl << endl << "Votre choix : "; cin >> nreader;
	system("cls");
	if (nreader == TITULAIRE) {
		Date *D = new Date();
		Grade *G = new Grade();
		Titulaire *T = new Titulaire();
		cout << "Vote Prenom	   : "; cin >> sreader; T->setPrenom(sreader); cout << endl;
		cout << "Votre Nom          : "; cin >> sreader; T->setNom(sreader); cout << endl;
		cout << "Votre Date jour    : "; cin >> nreader; D->setday(nreader); cout << endl;
		cout << "Votre Date mois    : "; cin >> nreader; D->setmounth(nreader); cout << endl;
		cout << "Votre Date annee   : "; cin >> nreader; D->setyear(nreader);  cout << endl; T->setDate(*D);
		cout << "Votre Telefone	    : "; cin >> sreader; T->setTelefon(sreader); cout << endl << endl;
		cout << "Vote Situation Familiale   : "; cin >> sreader; T->setSitFam(sreader); cout << endl;
		cout << "Le Nombre des enfants ?    : "; cin >> nreader; T->setNbEnf(nreader); cout << endl;
		cout << "Salaire de base ?          : "; cin >> dreader; G->setSValue(dreader); cout << endl; T->setGrade(*G);
		delete D;
		delete G;
		return T;
	}
	if (nreader == NON_TITULAIRE) {
		Date *D = new Date();
		Grade *G = new Grade();
		Nontitulaire *T = new Nontitulaire();
		cout << "Vote Prenom	   : "; cin >> sreader; T->setPrenom(sreader); cout << endl;
		cout << "Votre Nom          : "; cin >> sreader; T->setNom(sreader); cout << endl;
		cout << "Votre Date jour    : "; cin >> nreader; D->setday(nreader); cout << endl;
		cout << "Votre Date mois    : "; cin >> nreader; D->setmounth(nreader); cout << endl;
		cout << "Votre Date annee   : "; cin >> nreader; D->setyear(nreader);  cout << endl; T->setDate(*D);
		cout << "Votre Telefone	    : "; cin >> sreader; T->setTelefon(sreader); cout << endl << endl;
		cout << "Salaire de base ?          : "; cin >> dreader; G->setSValue(dreader); cout << endl; T->setGrade(*G);
		delete D;
		delete G;
		return T;
	}
	if (nreader == CONTRACTUEL) {
		cout << "Entrez Votre salaire pour le fixer dans le contract : "; cin >> dreader; cout << endl;
		Date *D = new Date();
		Contractuel *T = new Contractuel(dreader);
		cout << "Vote Prenom	   : "; cin >> sreader; T->setPrenom(sreader); cout << endl;
		cout << "Votre Nom          : "; cin >> sreader; T->setNom(sreader); cout << endl;
		cout << "Votre Date jour    : "; cin >> nreader; D->setday(nreader); cout << endl;
		cout << "Votre Date mois    : "; cin >> nreader; D->setmounth(nreader); cout << endl;
		cout << "Votre Date annee   : "; cin >> nreader; D->setyear(nreader);  cout << endl; T->setDate(*D);
		cout << "Votre Telefone	    : "; cin >> sreader; T->setTelefon(sreader); cout << endl << endl;
		delete D;
		return T;
	}
	if (nreader == STAGIER) {
		Date *D = new Date();
		Stagier *T = new Stagier();
		cout << "Vote Prenom	   : "; cin >> sreader; T->setPrenom(sreader); cout << endl;
		cout << "Votre Nom          : "; cin >> sreader; T->setNom(sreader); cout << endl;
		cout << "Votre Date jour    : "; cin >> nreader; D->setday(nreader); cout << endl;
		cout << "Votre Date mois    : "; cin >> nreader; D->setmounth(nreader); cout << endl;
		cout << "Votre Date annee   : "; cin >> nreader; D->setyear(nreader);  cout << endl; T->setDate(*D);
		cout << "Votre Telefone	    : "; cin >> sreader; T->setTelefon(sreader); cout << endl << endl;
		delete D;
		return T;
	}
	return NULL;
}

Commune * GestionDePerson::newPerson(Commune * C)
{
	C = this->newPerson(C, this->subscribe());
	return C;
}

Commune *GestionDePerson::newPerson(Commune * C, Person * P)
{
	vector<Person*> L = C->getList();
	bool add = true;
	for (unsigned int i(0); i < L.size(); ++i) {
		if (*L[i] == *P)
			if (this->occurPerson(C, P) == 1) {
				cout << "Deja existe !" << endl;
				delete P;
				add = false;
			}
	}
	if (add) {
		L.push_back(P);
		C->updateList(L);
	}
	return C;
}

Commune *GestionDePerson::editPerson(Commune * C, int code, Person * P)
{
	vector<Person*> L = C->getList();
	for (unsigned int i(0); i < L.size(); ++i) 
		if (L[i]->getCode() == code) {
			L[i]->setNom(P->getNom());
			L[i]->setPrenom(P->getPrenom());
			L[i]->setDate(P->getDate());
			L[i]->setTelefon(P->getTelefon());
			if (P->Ptype() == TITULAIRE) {
				dynamic_cast<Titulaire*>(L[i])->setSitFam(dynamic_cast<Titulaire*>(P)->getSitFam());
				dynamic_cast<Titulaire*>(L[i])->setNbEnf(dynamic_cast<Titulaire*>(P)->getNbEnf());
				dynamic_cast<Titulaire*>(L[i])->setGrade(dynamic_cast<Titulaire*>(P)->getGrade());
			}
			if (P->Ptype() == NON_TITULAIRE) {
				dynamic_cast<Nontitulaire*>(L[i])->setGrade(dynamic_cast<Nontitulaire*>(P)->getGrade());
			}
		}
	C->updateList(L);
	return C;
}

Commune *GestionDePerson::deletePerson(Commune * C, Person * P)
{
	vector<Person*> L = C->getList();
	for (unsigned int i(0); i < L.size(); ++i)
		if (*L[i] == *P) L.erase(L.begin() + i);
	C->updateList(L);
	return C;
}

Commune * GestionDePerson::deletePerson(Commune * C, int code)
{
	vector<Person*> L = C->getList();
	for (unsigned int i(0); i < L.size(); ++i)
		if (L[i]->getCode() == code) L.erase(L.begin() + i);
	C->updateList(L);
	return C;
}

vector<Person*> GestionDePerson::getTilutaires(Commune * C)
{
	vector<Person*> L = C->getList();
	vector<Person*> R(0);
	for (unsigned int i(0); i < L.size(); ++i) 
		if (L[i]->Ptype() == TITULAIRE) R.push_back(L[i]);
	return R;
}

std::vector<Person*> GestionDePerson::getNonTilutaires(Commune * C)
{
	vector<Person*> L = C->getList();
	vector<Person*> R(0);
	for (unsigned int i(0); i < L.size(); ++i)
		if (L[i]->Ptype() == NON_TITULAIRE) R.push_back(L[i]);
	return R;
}

std::vector<Person*> GestionDePerson::getContractuels(Commune * C)
{
	vector<Person*> L = C->getList();
	vector<Person*> R(0);
	for (unsigned int i(0); i < L.size(); ++i)
		if (L[i]->Ptype() == CONTRACTUEL) R.push_back(L[i]);
	return R;
}

std::vector<Person*> GestionDePerson::getStagiers(Commune * C)
{
	vector<Person*> L = C->getList();
	vector<Person*> R(0);
	for (unsigned int i(0); i < L.size(); ++i)
		if (L[i]->Ptype() == STAGIER) R.push_back(L[i]);
	return R;
}



Person *GestionDePerson::getPersonByCode(Commune * C, int code) {
	vector<Person*> L = C->getList();
	for (unsigned int i(0); i < L.size(); ++i) {
		if (L[i]->getCode() == code) return L[i];
	}
	return NULL;
}

Person * GestionDePerson::getPersonByIden(Commune * C, string const & prenom, string const & nom)
{
	vector<Person*> L = C->getList();
	for (unsigned int i(0); i < L.size(); ++i) {
		if (L[i]->getPrenom() == prenom && L[i]->getNom() == nom) {
			return L[i];
		}
	}
	return NULL;
}

std::vector<Person*> GestionDePerson::getPersonsByGrade(Commune * C, Grade * G)
{
	vector<Person*> L = C->getList();
	vector<Person*> R(0);
	for (unsigned int i(0); i < L.size(); ++i) {
		if (L[i]->Ptype() == TITULAIRE) 
			if (dynamic_cast<Titulaire*>(L[i])->getGrade() == *G) R.push_back(L[i]);
		if(L[i]->Ptype() == NON_TITULAIRE)
			if (dynamic_cast<Nontitulaire*>(L[i])->getGrade() == *G) R.push_back(L[i]);
	}
	return R;
}


int GestionDePerson::occurPerson(Commune * C, Person * P)
{
	int counter(0);
	for (unsigned int i(0); i < C->getList().size(); ++i) {
		if (*C->getList()[i] == *P) counter++;
	}
	return counter;
}

bool GestionDePerson::isIn(int Code, Group G)
{
	for (unsigned int i(0); i < G.getCommN(); ++i) {
		for (unsigned int j(0); j < G.getCommune(i)->getPersN(); ++j) {
			if (this->getPersonByCode(G.getCommune(i), Code)) return true;
		}
	}
	return false;
}

bool GestionDePerson::isIn(std::string prenom, std::string nom, Group G)
{
	for (unsigned int i(0); i < G.getCommN(); ++i) {
		for (unsigned int j(0); j < G.getCommune(i)->getPersN(); ++j) {
			if (this->getPersonByIden(G.getCommune(i), prenom, nom)) return true;
		}
	}
	return false;
}

int GestionDePerson::getMyCode(Commune * C, std::string const & prenom, std::string const & nom)
{
	vector<Person*> L = C->getList();
	for (unsigned int i(0); i < L.size(); ++i) {
		if (L[i]->getPrenom() == prenom && L[i]->getNom() == nom) {
			return L[i]->getCode();
		}
	}
	return NULL;
}

int GestionDePerson::getIndexOf(Commune * C, std::string const & prenom, std::string const & nom)
{
	vector<Person*> L = C->getList();
	for (unsigned int i(0); i < L.size(); ++i) {
		if (L[i]->getPrenom() == prenom && L[i]->getNom() == nom) {
			return i;
		}
	}
	return NULL;
}

void GestionDePerson::showList(Commune *C)
{
	int t(0), n(0), c(0), s(0);
	vector<Person*> L = C->getList();
	for (unsigned int i(0); i < L.size(); ++i) {
		if (L[i]->Ptype() == TITULAIRE) t++;
		if (L[i]->Ptype() == NON_TITULAIRE) n++;
		if (L[i]->Ptype() == CONTRACTUEL) c++;
		if (L[i]->Ptype() == STAGIER) s++;
	}
	system("cls");
	cout << "*********************Commune <" << C->getNom() << "> " << C->getAdresse() << "----------[" << C->getTelefone() << 
		"]***********" << endl << endl;
	for (int i(1); i <= Person::getPersonNumber(); ++i) {
		if (this->getPersonByCode(C, i)) {
			this->getPersonByCode(C, i)->print();
			cout << "---------------------------------------------------------------------" << endl;
		}
	}
	cout << "Titulaires	->  (" << t << ")" << endl;
	cout << "Non Titulaires  ->  (" << n << ")" << endl;
	cout << "Contractuels    ->  (" << c << ")" << endl;
	cout << "Stagiers        ->  (" << s << ")" << endl;
	cout << "Total           ->  (" << L.size() << ")" << endl;
}
