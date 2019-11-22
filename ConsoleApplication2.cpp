// ConsoleApplication2.cpp : Defines the entry point for the console application. 
//
/// INCLUDE FILES AND CLASSES ------------------------------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Titulaire.h"
#include "Nontitulaire.h"
#include "Contractuel.h"
#include "Stagier.h"
#include "GestionDePerson.h"
#include "Group.h"
/// MACROS DEFINITIONS --------------------------------------------------------------------------------------
#define GR1 "GROUP A"
#define GR2 "GROUP B"
#define GR3 "GROUP C"
	
#define CO1 "Marrakech"
#define CO2 "Fes"
#define CO3 "Casablanca"
#define CO4 "Essaouira"
#define CO5 "Tanger"
#define CO6 "Rabat"
#define CO7 "Chefchaouen"
#define CO8 "Meknes"
#define CO9 "Agadir"

#define MISEaJOUR 1
#define DETERTITULAIR 2
#define DETERNONTITULAIR 3
#define DETERCONTRACTUEL 4
#define DETERSTAGIER 5
#define SEARCHCODE 6
#define SEARCHIDENT 7
#define SEARCHGRADE 8
#define QUIT 9
/// NAMESPACES USED IN THE PROJECTS -------------------------------------------------------------------------
using namespace std;
/// TEST FUNCTIONS ------------------------------------------------------------------------------------------
void test() {
	Person *P1 = new Stagier("hamza", "alawi", Date(1, 9, 1998), "0635382580");
	Person *P2 = new Titulaire("youssef", "mabchouch", Date(2, 7, 1998), "0623527192", "celib", 0, 9856);
	Person *P3 = new Nontitulaire("mohammed", "brighli", Date(1, 7, 1998), "0707527192", 4588);
	Person *P4 = new Contractuel("ali", "talbi", Date(28, 6, 1998), "0646758580", 1500);
	P1->print();
	cout << endl;
	P2->print();
	cout << endl;
	P3->print();
	cout << endl;
	P4->print();
	cout << endl;
}
void test2() {
	Commune *C = new Commune("SMI");
	GestionDePerson G;
	C = G.newPerson(C, new Titulaire("hamza", "alawi", "celibataire", 0, 9856));
	C = G.newPerson(C, new Nontitulaire("salma", "alawi", 1956));
	C = G.newPerson(C, new Contractuel("hamid", "alami", 3856));
	C = G.newPerson(C, new Stagier("salma", "zerki"));
	G.getPersonByCode(C, 1)->setDate(1, 9, 1998);
	dynamic_cast<Titulaire*>(G.getPersonByCode(C, 1))->setNbEnf(7);
	C = G.newPerson(C);
	G.showList(C);
}
void test3() {
	Commune *C = new Commune("Lokal");
	GestionDePerson M;
	C = M.newPerson(C, new Stagier("hamza", "alawi"));
	Group G("Gaming");
	G.addCommune("Online");
	G.addCommune(C);
	G.print();
}
void test4() {
	Group G1("Computer Science"), G2("Physics");
	// GROUP 1 MANAGEMENT-----------------------------------------------------------------------------------------
	GestionDePerson M;
	// COMMUNE 1 PROGRAMMING MANAGEMENT-----------------------------------------------------------------------
	Commune *C1 = new Commune("Programming");
	C1 = M.newPerson(C1, new Titulaire("hamza", "alaoui", Date(1, 9, 1998), "0652101282", "Celibataire", 0, 3496.7));
	C1 = M.newPerson(C1, new Nontitulaire("youssef", "mabchouch", Date(2, 6, 1998), "0623629162", 2899.5));
	C1 = M.newPerson(C1, new Contractuel("hamid", "alami", Date(3, 9, 1997), "0632719268", 3856));
	C1 = M.newPerson(C1, new Stagier("salma", "zerki", Date(3, 11, 1999), "0682902682"));
	G1.addCommune(C1);
	// COMMUNE 2 ELECTRONICS MANAGEMENT-----------------------------------------------------------------------
	Commune *C2 = new Commune("Electronics");
	C2 = M.newPerson(C2, new Nontitulaire("mohammed", "brighli", Date(2, 12, 1998), "0707666219", 8790.5));
	C2 = M.newPerson(C2, new Contractuel("rhita", "essafi", Date(3, 5, 1998), "0632919068", 9728.8));
	C2 = M.newPerson(C2, new Stagier("chaimae", "allali", Date(8, 10, 1999), "0682992982"));
	G1.addCommune(C2);
	// COMMUNE 3 SECURITY MANAGEMENT-----------------------------------------------------------------------
	Commune *C3 = new Commune("Security");
	C3 = M.newPerson(C3, new Stagier("musstapha", "khalifa", Date(8, 1, 1976), "0682902682"));
	C3 = M.newPerson(C3, new Stagier("walid", "elhamdi", Date(12, 9, 1998), "0682202682"));
	G1.addCommune(C3);
	// GROUP 1 MANAGEMENT-----------------------------------------------------------------------------------------
	// COMMUNE 1 MECHANIC MANAGEMENT
	C1 = new Commune("Mechanic");
	C1 = M.newPerson(C1, new Titulaire("said", "ahmadi", "Marier", 4, 6000));
	G2.addCommune(C1);
	G1.print();
	G2.print();
	delete C1, C2, C3;
}
/// MAIN BLOCK ----------------------------------------------------------------------------------------------
int main()
{
		/// CLASS DE GESTION
		GestionDePerson M;
		/// Groupes 
		Group G1(GR1), G2(GR2), G3(GR3);
		// LES COMMUNES DE GROUPE 1
		Commune *C1 = new Commune(CO1, "Etage 1 - Bureau 1", "011");	G1.addCommune(C1);
		Commune *C2 = new Commune(CO2, "Etage 1 - Bureau 2", "012");	G1.addCommune(C2);
		Commune *C3 = new Commune(CO3, "Etage 1 - Bureau 3", "013");	G1.addCommune(C3);
		// LES COMMUNES DE GROUPE 2
		Commune *C4 = new Commune(CO4, "Etage 2 - Bureau 1", "021");	G2.addCommune(C4);
		Commune *C5 = new Commune(CO5, "Etage 2 - Bureau 2", "022");	G2.addCommune(C5);
		Commune *C6 = new Commune(CO6, "Etage 2 - Bureau 3", "023");	G2.addCommune(C6);
		// LES COMMUNES DE GROUPE 3
		Commune *C7 = new Commune(CO7, "Etage 3 - Bureau 1", "031");	G3.addCommune(C7);
		Commune *C8 = new Commune(CO8, "Etage 3 - Bureau 2", "032");	G3.addCommune(C8);
		Commune *C9 = new Commune(CO9, "Etage 3 - Bureau 3", "033");	G3.addCommune(C9);
		/// VARIABLES
		bool continuer1(true), continuer2(true), continuer3(true), continuer4(true);
		int choix(0), N(0), P(0), P2(0), P3(0), P4(0);
		double F(0);
		string S,S2;
		///------------------------------------------------------------------------------------------------------
		while (continuer1) { // BOUCLE PRINCIPALE
			cout << endl << endl
				<< "\t\tExercice 4 " << endl
				<< "\t\t*************************PROGRAMME DE GESTION DE PERSONNEL******************************" << endl
				<< "\t\t*                                     -[MENU]-                                         *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*     [1]     - Mise a jour du personnel : Ajout suppression, modification.            *" << endl
				<< "\t\t*     [2]     - Determiner la liste des Titulaires.                                    *" << endl
				<< "\t\t*     [3]     - Determiner la liste des Non-Titulaires.                                *" << endl
				<< "\t\t*     [4]     - Determiner la liste des Contractuel.                                   *" << endl
				<< "\t\t*     [5]     - Determiner la liste des stagiaires.                                    *" << endl
				<< "\t\t*     [6]     - Chercher un fonctionnaire par son code.                                *" << endl
				<< "\t\t*     [7]     - Chercher un fonctionnaire par son nom et son prenom.                   *" << endl
				<< "\t\t*     [8]     - Chercher la liste des fonctionnaires ayant un grade donne.             *" << endl
				<< "\t\t*     [9]     - Quitter.                                                               *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*      **[Tip : Utilisez (-1) si vous voulez retourner directement au cet Menu]**      *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*       **[Autres Cles : (0) AFFICHAGE TOTAL (10) PAR GROUP (11) PAR COMMUNE]**        *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*                                                                                      *" << endl
				<< "\t\t*                         -[Effectuer Par Ismaili Alaoui Hamza]-                       *" << endl
				<< "\t\t*                                  +[Prof N. Chenfour]+                                *" << endl
				<< "\t\t****************************************************************************************" << endl
				<< endl << endl;
			cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
			continuer2 = true;
			/// SWITCHING CHOICES
			switch (choix)
			{
			case MISEaJOUR:
				while (continuer2) {
					cout
						<< "\t\t[0] - Retourner " << endl
						<< "\t\t[1] - Ajout     " << endl
						<< "\t\t[2] - Modifier  " << endl
						<< "\t\t[3] - Supprimer " << endl;
					cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
					system("cls");
					continuer3 = true;
					switch (choix)
					{
					case -1: //MENU
						continuer2 = false;
					case 0: //RETOUR
						continuer2 = false;
						break;
					case 1: // AJOUT
						while (continuer3) {
							cout << "\t\tQuelle Group veuillez-vous ajouter ce person ? :" << endl
								<< "\t\t[0] - Retourner " << endl
								<< "\t\t[1] Groupe <" << GR1 << ">" << endl
								<< "\t\t[2] Groupe <" << GR2 <<">" << endl
								<< "\t\t[3] Groupe <" << GR3 << ">" << endl;
							cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
							system("cls");
							continuer4 = true;
							switch (choix)
							{
							case -1: //MENU
								continuer3 = false;
								continuer2 = false;
								break;
							case 0: // RETOUR
								continuer3 = false;
								break;
							case 1:  // GROUPE 1 CASE
								while (continuer4) {
									cout << "\t\tQuelle Commune veuillez-vous ajouter ce person ? :" << endl
										<< "\t\t[0] - Retourner " << endl
										<< "\t\t[1] Commune <" << CO1 << ">" << endl
										<< "\t\t[2] Commune <" << CO2 << ">" << endl
										<< "\t\t[3] Commune <" << CO3 << ">" << endl;
									cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
									system("cls");
									switch (choix)
									{
									case -1: //MENU
										continuer4 = false;
										continuer3 = false;
										continuer2 = false;
									case 0: // RETOUR
										continuer4 = false;
										break;
									case 1: // COMMUNE 1 CASE
										C1 = M.newPerson(C1);
										G1.changeCommune(C1->getNom(), C1);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									case 2: // COMMUNE 2 CASE
										C2 = M.newPerson(C2);
										G1.changeCommune(C2->getNom(), C2);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									case 3: // COMMUNE 3 CASE
										C3 = M.newPerson(C3);
										G1.changeCommune(C3->getNom(), C3);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									default:
										cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
										break;
									}
								}
								break;
							case 2: // GROUPE 2 CASE
								while (continuer4) {
									cout << "\t\tQuelle Commune veuillez-vous ajouter ce person ? :" << endl
										<< "\t\t[0] - Retourner " << endl
										<< "\t\t[1] Commune <" << CO4 << ">" << endl
										<< "\t\t[2] Commune <" << CO5 << ">" << endl
										<< "\t\t[3] Commune <" << CO6 << ">" << endl;
									cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
									system("cls");
									switch (choix)
									{
									case -1:
										continuer4 = false;
										continuer3 = false;
										continuer2 = false;
									case 0:
										continuer4 = false;
										break;
									case 1: //COMMUNE 4 CASE
										C4 = M.newPerson(C4);
										G2.changeCommune(C4->getNom(), C4);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									case 2: // COMMUNE 5 CASE
										C5 = M.newPerson(C5);
										G2.changeCommune(C5->getNom(), C5);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									case 3: // COMMUNE 6 CASE
										C6 = M.newPerson(C6);
										G2.changeCommune(C6->getNom(), C6);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									default:
										cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
										break;
									}
								}
								break;
							case 3: // GROUPE 3 CASE
								while (continuer4) {
									cout << "\t\tQuelle Commune veuillez-vous ajouter ce person ? :" << endl
										<< "\t\t[0] - Retourner " << endl
										<< "\t\t[1] Commune <" << CO7 << ">" << endl
										<< "\t\t[2] Commune <" << CO8 << ">" << endl
										<< "\t\t[3] Commune <" << CO9 << ">" << endl;
									cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
									system("cls");
									switch (choix)
									{
									case -1:
										continuer4 = false;
										continuer3 = false;
										continuer2 = false;
									case 0:
										continuer4 = false;
										break;
									case 1: // COMMUNE 7 CASE
										C7 = M.newPerson(C7);
										G3.changeCommune(C7->getNom(), C7);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									case 2: // COMMUNE 8 CASE
										C8 = M.newPerson(C8);
										G3.changeCommune(C8->getNom(), C8);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									case 3: // COMMUNE 9 CASE
										C9 = M.newPerson(C9);
										G3.changeCommune(C9->getNom(), C9);
										system("cls");

										cout << "\t\t\t\t\tTerminaison D'ajout" << endl;
										system("pause");
										system("cls");
										continuer4 = false;
										break;
									default:
										cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
										break;
									}
								}
								break;
							default:
								cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
								break;
							}
						}
						break;
					case 2: // MODIFICATION
						cout << "\t\tEntrez le code du person que vous voulez modifier :"; cin >> N;
						if (N <= Person::getPersonNumber()) {
							bool accessGr1(false), accessGr2(false), accessGr3(false);
							accessGr1 = M.isIn(N, G1);
							accessGr2 = M.isIn(N, G2);
							accessGr3 = M.isIn(N, G3);
							continuer3 = true;
							if (accessGr1)
								while (continuer3) {
										for (unsigned int i(0); i < G1.getCommN(); ++i) {
											if (M.getPersonByCode(G1.getCommune(i), N)) {
												M.getPersonByCode(G1.getCommune(i), N)->print();
												cout << endl << endl;
												cout
													<< "\t\t[0] - Retourner " << endl
													<< "\t\t[1] - Modifier Le Nom     " << endl
													<< "\t\t[2] - Modifier Le Prenom  " << endl
													<< "\t\t[3] - Modifier Le Telefone " << endl;

												if (M.getPersonByCode(G1.getCommune(i), N)->Ptype() == TITULAIRE) {
													Titulaire *T = dynamic_cast<Titulaire*>(M.getPersonByCode(G1.getCommune(i), N));
													Date *D = new Date();
													Grade *G = new Grade();
													cout
														<< "\t\t[4] - Modifier La Situation Familliale " << endl
														<< "\t\t[5] - Modifier Le Grade  " << endl;
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													case 4: //MODIF SIT FAM
														cout << "\t\tSituation Familliale du Person " <<
															T->getSitFam() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setSitFam(S);
														break;
													case 5: //MODIF GRAD
														cout << "\t\tGrade du Person " <<
															T->getGrade() << endl << endl;
														cout << "\t\tEntrez le nouveau nombre salaire de base : "; cin >> F; G->setSValue(F);
														T->setGrade(*G);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G1.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G1.changeCommune(i, C1);
												}
												if (M.getPersonByCode(G1.getCommune(i), N)->Ptype() == NON_TITULAIRE) {
													Nontitulaire *T = dynamic_cast<Nontitulaire*>(M.getPersonByCode(G1.getCommune(i), N));
													Date *D = new Date();
													Grade *G = new Grade();
													cout
														<< "\t\t[4] - Modifier Le Grade  " << endl;
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													case 4: //MODIF GRAD
														cout << "\t\tGrade du Person " <<
															T->getGrade() << endl << endl;
														cout << "\t\tEntrez le nouveau nombre salaire de base : "; cin >> F; G->setSValue(F);
														T->setGrade(*G);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G1.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G1.changeCommune(i, C1);
												}
												if (M.getPersonByCode(G1.getCommune(i), N)->Ptype() == CONTRACTUEL ||
													M.getPersonByCode(G1.getCommune(i), N)->Ptype() == STAGIER) {
													Person *T = M.getPersonByCode(G1.getCommune(i), N);
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G1.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G1.changeCommune(i, C1);
												}
												system("cls");
											}
										}
									}
							if (accessGr2)
								while (continuer3) {
										for (unsigned int i(0); i < G2.getCommN(); ++i) {
											if (M.getPersonByCode(G2.getCommune(i), N)) {
												M.getPersonByCode(G2.getCommune(i), N)->print();
												cout << endl << endl;
												cout
													<< "\t\t[0] - Retourner " << endl
													<< "\t\t[1] - Modifier Le Nom     " << endl
													<< "\t\t[2] - Modifier Le Prenom  " << endl
													<< "\t\t[3] - Modifier Le Telefone " << endl;

												if (M.getPersonByCode(G2.getCommune(i), N)->Ptype() == TITULAIRE) {
													Titulaire *T = dynamic_cast<Titulaire*>(M.getPersonByCode(G2.getCommune(i), N));
													Date *D = new Date();
													Grade *G = new Grade();
													cout
														<< "\t\t[4] - Modifier La Situation Familliale " << endl
														<< "\t\t[5] - Modifier Le Grade  " << endl;
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													case 4: //MODIF SIT FAM
														cout << "\t\tSituation Familliale du Person " <<
															T->getSitFam() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setSitFam(S);
														break;
													case 5: //MODIF GRAD
														cout << "\t\tGrade du Person " <<
															T->getGrade() << endl << endl;
														cout << "\t\tEntrez le nouveau nombre salaire de base : "; cin >> F; G->setSValue(F);
														T->setGrade(*G);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G2.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G2.changeCommune(i, C1);
												}
												if (M.getPersonByCode(G2.getCommune(i), N)->Ptype() == NON_TITULAIRE) {
													Nontitulaire *T = dynamic_cast<Nontitulaire*>(M.getPersonByCode(G2.getCommune(i), N));
													Date *D = new Date();
													Grade *G = new Grade();
													cout
														<< "\t\t[4] - Modifier Le Grade  " << endl;
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													case 4: //MODIF GRAD
														cout << "\t\tGrade du Person " <<
															T->getGrade() << endl << endl;
														cout << "\t\tEntrez le nouveau nombre salaire de base : "; cin >> F; G->setSValue(F);
														T->setGrade(*G);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G2.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G2.changeCommune(i, C1);
												}
												if (M.getPersonByCode(G2.getCommune(i), N)->Ptype() == CONTRACTUEL ||
													M.getPersonByCode(G2.getCommune(i), N)->Ptype() == STAGIER) {
													Person *T = M.getPersonByCode(G2.getCommune(i), N);
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G2.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G2.changeCommune(i, C1);
												}
												system("cls");
											}
										}
									}
							if (accessGr3)
								while (continuer3) {
										for (unsigned int i(0); i < G3.getCommN(); ++i) {
											if (M.getPersonByCode(G3.getCommune(i), N)) {
												M.getPersonByCode(G3.getCommune(i), N)->print();
												cout << endl << endl;
												cout
													<< "\t\t[0] - Retourner " << endl
													<< "\t\t[1] - Modifier Le Nom     " << endl
													<< "\t\t[2] - Modifier Le Prenom  " << endl
													<< "\t\t[3] - Modifier Le Telefone " << endl;

												if (M.getPersonByCode(G3.getCommune(i), N)->Ptype() == TITULAIRE) {
													Titulaire *T = dynamic_cast<Titulaire*>(M.getPersonByCode(G3.getCommune(i), N));
													Date *D = new Date();
													Grade *G = new Grade();
													cout
														<< "\t\t[4] - Modifier La Situation Familliale " << endl
														<< "\t\t[5] - Modifier Le Grade  " << endl;
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													case 4: //MODIF SIT FAM
														cout << "\t\tSituation Familliale du Person " <<
															T->getSitFam() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setSitFam(S);
														break;
													case 5: //MODIF GRAD
														cout << "\t\tGrade du Person " <<
															T->getGrade() << endl << endl;
														cout << "\t\tEntrez le nouveau nombre salaire de base : "; cin >> F; G->setSValue(F);
														T->setGrade(*G);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G3.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G3.changeCommune(i, C1);
												}
												if (M.getPersonByCode(G3.getCommune(i), N)->Ptype() == NON_TITULAIRE) {
													Nontitulaire *T = dynamic_cast<Nontitulaire*>(M.getPersonByCode(G3.getCommune(i), N));
													Date *D = new Date();
													Grade *G = new Grade();
													cout
														<< "\t\t[4] - Modifier Le Grade  " << endl;
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													case 4: //MODIF GRAD
														cout << "\t\tGrade du Person " <<
															T->getGrade() << endl << endl;
														cout << "\t\tEntrez le nouveau nombre salaire de base : "; cin >> F; G->setSValue(F);
														T->setGrade(*G);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G3.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G3.changeCommune(i, C1);
												}
												if (M.getPersonByCode(G3.getCommune(i), N)->Ptype() == CONTRACTUEL ||
													M.getPersonByCode(G3.getCommune(i), N)->Ptype() == STAGIER) {
													Person *T = M.getPersonByCode(G3.getCommune(i), N);
													cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
													system("cls");
													switch (choix)
													{
													case -1: //MENU
														continuer3 = false;
														continuer2 = false;
														break;
													case 0: //RETOUR
														continuer3 = false;
														break;
													case 1: //MODIF NOM
														cout << "\t\tNom du Person " <<
															T->getNom() << endl << endl;
														cout << "\t\tEntrez le nouveau Nom : "; cin >> S;
														T->setNom(S);
														break;
													case 2: //MODIF PRENOM
														cout << "\t\tPrenom du Person " <<
															T->getPrenom() << endl << endl;
														cout << "\t\tEntrez le nouveau Prenom : "; cin >> S;
														T->setPrenom(S);
														break;
													case 3: //MODIF TELEFONE
														cout << "\t\tTelefone du Person " <<
															T->getTelefon() << endl << endl;
														cout << "\t\tEntrez le nouveau Telefone : "; cin >> S;
														T->setTelefon(S);
														break;
													default:
														cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
														break;
													}
													C1 = G3.getCommune(i);
													C1 = M.editPerson(C1, N, T);
													G3.changeCommune(i, C1);
												}
												system("cls");
											}
										}
									}
							}
							else cout << "\t\t\t\t\t<!> Code introuvable <!>" << endl;
							cout << "\t\t\t\t\tTerminaison De Modification" << endl;
							system("pause");
							system("cls");
							break;
					case 3: // SUPPRESSION
						cout << "\t\tEntrez le code du person que vous voulez supprimer :"; cin >> N;
						if (N <= Person::getPersonNumber()) {
							bool accessGr1(false), accessGr2(false), accessGr3(false);
							accessGr1 = M.isIn(N, G1);
							accessGr2 = M.isIn(N, G2);
							accessGr3 = M.isIn(N, G3);
							if (accessGr1)
								for (unsigned int i(0); i < G1.getCommN(); ++i) {
									if (M.getPersonByCode(G1.getCommune(i), N)) {
										M.getPersonByCode(G1.getCommune(i), N)->print();
										cout << endl << endl;
										C1 = G1.getCommune(i);
										C1 = M.deletePerson(C1, N);
										G1.changeCommune(i, C1);
									}
								}
							if (accessGr2)
								for (unsigned int i(0); i < G2.getCommN(); ++i) {
									if (M.getPersonByCode(G2.getCommune(i), N)) {
										M.getPersonByCode(G2.getCommune(i), N)->print();
										cout << endl << endl;
										C1 = G2.getCommune(i);
										C1 = M.deletePerson(C1, N);
										G2.changeCommune(i, C1);
									}
								}
							if (accessGr3)
								for (unsigned int i(0); i < G3.getCommN(); ++i) {
									if (M.getPersonByCode(G3.getCommune(i), N)) {
										M.getPersonByCode(G3.getCommune(i), N)->print();
										cout << endl << endl;
										C1 = G3.getCommune(i);
										C1 = M.deletePerson(C1, N);
										G3.changeCommune(i, C1);
									}
								}
						}
						else cout << "\t\t\t\t\t<!> Code introuvable <!>" << endl;
						cout << "\t\t\t\t\tTerminaison De Suppression" << endl;
						system("pause");
						system("cls");
						break;
					default:
						cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
						break;
						}
					}
					break;
			case DETERTITULAIR:
				N = 0;
				cout << "\t\tChoisir le type d'affichage " << endl
					<< "\t\t[1] Affichage Simplifier" << endl
					<< "\t\t[2] Affichage Detailler" << endl;
				cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
				system("cls");
				if (choix == 1) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getTilutaires(G1.getCommune(i)).size(); ++j) {
							cout << *M.getTilutaires(G1.getCommune(i))[j] << " Commune <" << *G1.getCommune(i) << "> Group <"
								<< G1.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getTilutaires(G2.getCommune(i)).size(); ++j) {
							cout << *M.getTilutaires(G2.getCommune(i))[j] << " Commune <" << *G2.getCommune(i) << "> Group <"
								<< G2.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getTilutaires(G3.getCommune(i)).size(); ++j) {
							cout << *M.getTilutaires(G3.getCommune(i))[j] << " Commune <" << *G3.getCommune(i) << "> Group <"
								<< G3.getNom() << ">" << endl;
							N++;
						}
					}
				}
				if (choix == 2) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getTilutaires(G1.getCommune(i)).size(); ++j) {
							M.getTilutaires(G1.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G1.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G1.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getTilutaires(G2.getCommune(i)).size(); ++j) {
							M.getTilutaires(G2.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G2.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G2.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getTilutaires(G3.getCommune(i)).size(); ++j) {
							M.getTilutaires(G3.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G3.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G3.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
				}
				cout << "Total des Titulaire trouvee : " << N << endl;
				cout << "\t\t\t\t\tFin Liste" << endl;
				system("pause");
				system("cls");
				break;
			case DETERNONTITULAIR:
				N = 0;
				cout << "\t\tChoisir le type d'affichage " << endl
					<< "\t\t[1] Affichage Simplifier" << endl
					<< "\t\t[2] Affichage Detailler" << endl;
				cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
				system("cls");
				if (choix == 1) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getNonTilutaires(G1.getCommune(i)).size(); ++j) {
							cout << *M.getNonTilutaires(G1.getCommune(i))[j] << " Commune <" << *G1.getCommune(i) << "> Group <"
								<< G1.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getNonTilutaires(G2.getCommune(i)).size(); ++j) {
							cout << *M.getNonTilutaires(G2.getCommune(i))[j] << " Commune <" << *G2.getCommune(i) << "> Group <"
								<< G2.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getNonTilutaires(G3.getCommune(i)).size(); ++j) {
							cout << *M.getNonTilutaires(G3.getCommune(i))[j] << " Commune <" << *G3.getCommune(i) << "> Group <"
								<< G3.getNom() << ">" << endl;
							N++;
						}
					}
				}
				if (choix == 2) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getNonTilutaires(G1.getCommune(i)).size(); ++j) {
							M.getNonTilutaires(G1.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G1.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G1.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getNonTilutaires(G2.getCommune(i)).size(); ++j) {
							M.getNonTilutaires(G2.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G2.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G2.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getNonTilutaires(G3.getCommune(i)).size(); ++j) {
							M.getNonTilutaires(G3.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G3.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G3.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
				}
				cout << "Total des Non-Titulaire trouvee : " << N << endl;
				cout << "\t\t\t\t\tFin Liste" << endl;
				system("pause");
				system("cls");
				break;
			case DETERCONTRACTUEL:
				N = 0;
				cout << "\t\tChoisir le type d'affichage " << endl
					<< "\t\t[1] Affichage Simplifier" << endl
					<< "\t\t[2] Affichage Detailler" << endl;
				cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
				system("cls");
				if (choix == 1) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getContractuels(G1.getCommune(i)).size(); ++j) {
							cout << *M.getContractuels(G1.getCommune(i))[j] << " Commune <" << *G1.getCommune(i) << "> Group <"
								<< G1.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getContractuels(G2.getCommune(i)).size(); ++j) {
							cout << *M.getContractuels(G2.getCommune(i))[j] << " Commune <" << *G2.getCommune(i) << "> Group <"
								<< G2.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getContractuels(G3.getCommune(i)).size(); ++j) {
							cout << *M.getContractuels(G3.getCommune(i))[j] << " Commune <" << *G3.getCommune(i) << "> Group <"
								<< G3.getNom() << ">" << endl;
							N++;
						}
					}
				}
				if (choix == 2) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getContractuels(G1.getCommune(i)).size(); ++j) {
							M.getContractuels(G1.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G1.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G1.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getContractuels(G2.getCommune(i)).size(); ++j) {
							M.getContractuels(G2.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G2.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G2.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getContractuels(G3.getCommune(i)).size(); ++j) {
							M.getContractuels(G3.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G3.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G3.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
				}
				cout << "Total des Contractuels trouvee : " << N << endl;
				cout << "\t\t\t\t\tFin Liste" << endl;
				system("pause");
				system("cls");
				break;
			case DETERSTAGIER:
				N = 0;
				cout << "\t\tChoisir le type d'affichage " << endl
					<< "\t\t[1] Affichage Simplifier" << endl
					<< "\t\t[2] Affichage Detailler" << endl;
				cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
				system("cls");
				if (choix == 1) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getStagiers(G1.getCommune(i)).size(); ++j) {
							cout << *M.getStagiers(G1.getCommune(i))[j] << " Commune <" << *G1.getCommune(i) << "> Group <"
								<< G1.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getStagiers(G2.getCommune(i)).size(); ++j) {
							cout << *M.getStagiers(G2.getCommune(i))[j] << " Commune <" << *G2.getCommune(i) << "> Group <"
								<< G2.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getStagiers(G3.getCommune(i)).size(); ++j) {
							cout << *M.getStagiers(G3.getCommune(i))[j] << " Commune <" << *G3.getCommune(i) << "> Group <"
								<< G3.getNom() << ">" << endl;
							N++;
						}
					}
				}
				if (choix == 2) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getStagiers(G1.getCommune(i)).size(); ++j) {
							M.getStagiers(G1.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G1.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G1.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getStagiers(G2.getCommune(i)).size(); ++j) {
							M.getStagiers(G2.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G2.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G2.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getStagiers(G3.getCommune(i)).size(); ++j) {
							M.getStagiers(G3.getCommune(i))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G3.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G3.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
				}
				cout << "Total des Stagiers trouvee : " << N << endl;
				cout << "\t\t\t\t\tFin Liste" << endl;
				system("pause");
				system("cls");
				break;
			case SEARCHCODE:
				cout << "\t\tEntrez le code du person :"; cin >> N;
				system("cls");
				cout << endl << endl;
				if (N <= Person::getPersonNumber()) {
					bool accessGr1(false), accessGr2(false), accessGr3(false);
					accessGr1 = M.isIn(N, G1);
					accessGr2 = M.isIn(N, G2);
					accessGr3 = M.isIn(N, G3);
					if (accessGr1)
						for (unsigned int i(0); i < G1.getCommN(); ++i) {
							if (M.getPersonByCode(G1.getCommune(i), N)) {
								M.getPersonByCode(G1.getCommune(i), N)->print();
								cout << endl;
								cout << "Commune  <" << *G1.getCommune(i) << ">" << endl;
								cout << "Groupe   <" << G1.getNom() << ">" << endl;
							}
						}
					if(accessGr2)
						for (unsigned int i(0); i < G2.getCommN(); ++i) {
							if (M.getPersonByCode(G2.getCommune(i), N)) {
								M.getPersonByCode(G2.getCommune(i), N)->print();
								cout << endl;
								cout << "Commune  <" << *G2.getCommune(i) << ">" << endl;
								cout << "Groupe   <" << G2.getNom() << ">" << endl;
							}
						}
					if (accessGr3)
						for (unsigned int i(0); i < G3.getCommN(); ++i) {
							if (M.getPersonByCode(G3.getCommune(i), N)) {
								M.getPersonByCode(G3.getCommune(i), N)->print();
								cout << endl;
								cout << "Commune  <" << *G3.getCommune(i) << ">" << endl;
								cout << "Groupe   <" << G3.getNom() << ">" << endl;
							}
						}
				}
				else cout << "\t\t\t\t\t<!> Code introuvable <!>" << endl;
				cout << endl << endl;
				system("pause");
				system("cls");
				break;
			case SEARCHIDENT:
				cout << "\t\tEntrez le prenom du person :"; cin >> S;
				cout << "\t\tEntrez le nom du person :"; cin >> S2;
				system("cls");
				cout << endl << endl;
				if (N <= Person::getPersonNumber()) {
					bool accessGr1(false), accessGr2(false), accessGr3(false);
					accessGr1 = M.isIn(S, S2, G1);
					accessGr2 = M.isIn(S, S2, G2);
					accessGr3 = M.isIn(S, S2, G3);
					if(accessGr1)
						for (unsigned int i(0); i < G1.getCommN(); ++i) {
						if (M.getPersonByIden(G1.getCommune(i), S, S2)) {
							M.getPersonByIden(G1.getCommune(i), S, S2)->print();
							cout << endl;
							cout << "Commune  <" << *G1.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G1.getNom() << ">" << endl;
							}
						}
					if (accessGr2)
						for (unsigned int i(0); i < G2.getCommN(); ++i) {
							if (M.getPersonByIden(G2.getCommune(i), S, S2)) {
								M.getPersonByIden(G2.getCommune(i), S, S2)->print();
								cout << endl;
								cout << "Commune  <" << *G2.getCommune(i) << ">" << endl;
								cout << "Groupe   <" << G2.getNom() << ">" << endl;
							}
						}
					if (accessGr3)
						for (unsigned int i(0); i < G1.getCommN(); ++i) {
							if (M.getPersonByIden(G3.getCommune(i), S, S2)) {
								M.getPersonByIden(G3.getCommune(i), S, S2)->print();
								cout << endl;
								cout << "Commune  <" << *G3.getCommune(i) << ">" << endl;
								cout << "Groupe   <" << G3.getNom() << ">" << endl;
							}
						}
				}
				else cout << "\t\t\t\t\t<!> Identificateur introuvable <!>" << endl;
				cout << endl << endl;
				system("pause");
				system("cls");
				break;
			case SEARCHGRADE:
				N = 0; P = 0; P2 = 0;
				cout << "\t\tEntrez le grade(salaire de base) du person :"; cin >> F;
				cout << "\t\tChoisir le type d'affichage " << endl
					<< "\t\t[1] Affichage Simplifier" << endl
					<< "\t\t[2] Affichage Detailler" << endl;
				cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
				system("cls");
				if (choix == 1) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getPersonsByGrade(G1.getCommune(i), new Grade(F)).size(); ++j) {
							if (M.getPersonsByGrade(G1.getCommune(i), new Grade(F))[j]->Ptype() == TITULAIRE) P++;
							if (M.getPersonsByGrade(G1.getCommune(i), new Grade(F))[j]->Ptype() == NON_TITULAIRE) P2++;
							cout << *M.getPersonsByGrade(G1.getCommune(i), new Grade(F))[j] << " Commune <" << *G1.getCommune(i) << "> Group <"
								<< G1.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getPersonsByGrade(G2.getCommune(i), new Grade(F)).size(); ++j) {
							if (M.getPersonsByGrade(G2.getCommune(i), new Grade(F))[j]->Ptype() == TITULAIRE) P++;
							if (M.getPersonsByGrade(G2.getCommune(i), new Grade(F))[j]->Ptype() == NON_TITULAIRE) P2++;
							cout << *M.getPersonsByGrade(G2.getCommune(i), new Grade(F))[j] << " Commune <" << *G2.getCommune(i) << "> Group <"
								<< G2.getNom() << ">" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getPersonsByGrade(G3.getCommune(i), new Grade(F)).size(); ++j) {
							if (M.getPersonsByGrade(G3.getCommune(i), new Grade(F))[j]->Ptype() == TITULAIRE) P++;
							if (M.getPersonsByGrade(G3.getCommune(i), new Grade(F))[j]->Ptype() == NON_TITULAIRE) P2++;
							cout << *M.getPersonsByGrade(G3.getCommune(i), new Grade(F))[j] << " Commune <" << *G3.getCommune(i) << "> Group <"
								<< G3.getNom() << ">" << endl;
							N++;
						}
					}
				}
				if (choix == 2) {
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getPersonsByGrade(G1.getCommune(i), new Grade(F)).size(); ++j) {
							if (M.getPersonsByGrade(G1.getCommune(i), new Grade(F))[j]->Ptype() == TITULAIRE) P++;
							if (M.getPersonsByGrade(G1.getCommune(i), new Grade(F))[j]->Ptype() == NON_TITULAIRE) P2++;
							M.getPersonsByGrade(G1.getCommune(i), new Grade(F))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G1.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G1.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getPersonsByGrade(G2.getCommune(i), new Grade(F)).size(); ++j) {
							if (M.getPersonsByGrade(G2.getCommune(i), new Grade(F))[j]->Ptype() == TITULAIRE) P++;
							if (M.getPersonsByGrade(G2.getCommune(i), new Grade(F))[j]->Ptype() == NON_TITULAIRE) P2++;
							M.getPersonsByGrade(G2.getCommune(i), new Grade(F))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G2.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G2.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						for (unsigned int j(0); j < M.getPersonsByGrade(G3.getCommune(i), new Grade(F)).size(); ++j) {
							if (M.getPersonsByGrade(G3.getCommune(i), new Grade(F))[j]->Ptype() == TITULAIRE) P++;
							if (M.getPersonsByGrade(G3.getCommune(i), new Grade(F))[j]->Ptype() == NON_TITULAIRE) P2++;
							M.getPersonsByGrade(G3.getCommune(i), new Grade(F))[j]->print();
							cout << endl;
							cout << "Commune  <" << *G3.getCommune(i) << ">" << endl;
							cout << "Groupe   <" << G3.getNom() << ">" << endl;
							cout << "---------------------------------------------------------------------------" << endl;
							N++;
						}
					}
				}
				cout << "Total des Persons trouvee : " << N << endl;
				cout << "Titulaires trouvee     : " << P << endl;
				cout << "Non-Titulaires trouvee : " << P2 << endl;
				cout << "\t\t\t\t\tFin Liste" << endl;
				system("pause");
				system("cls");
				break;
			case QUIT:
				continuer1 = false;
				break;
			case 10:
				N = 0; P = 0; P2 = 0; P3 = 0; P4 = 0;
				cout << "\t\tQuelle Group ? :" << endl
					<< "\t\t[0] - Retourner " << endl
					<< "\t\t[1] Groupe <" << GR1 << ">" << endl
					<< "\t\t[2] Groupe <" << GR2 << ">" << endl
					<< "\t\t[3] Groupe <" << GR3 << ">" << endl;
				cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
				system("cls");
				if (choix == 1) {
					G1.print();
					for (unsigned int i(0); i < G1.getCommN(); ++i) {
						N += G1.getCommune(i)->getPersN();
						P += M.getTilutaires(G1.getCommune(i)).size();
						P2 += M.getNonTilutaires(G1.getCommune(i)).size();
						P3 += M.getContractuels(G1.getCommune(i)).size();
						P4 += M.getStagiers(G1.getCommune(i)).size();
					}
					cout << endl
						<< "\t\tNombre de Persons dans ce Group : " << N << endl
						<< "\t\tTitulaires     : " << P << endl
						<< "\t\tNon-Titulaires : " << P2 << endl
						<< "\t\tContractuels   : " << P3 << endl
						<< "\t\tStagiers       : " << P4 << endl;
				}
				if (choix == 2) {
					G2.print();
					for (unsigned int i(0); i < G2.getCommN(); ++i) {
						N += G2.getCommune(i)->getPersN();
						P += M.getTilutaires(G2.getCommune(i)).size();
						P2 += M.getNonTilutaires(G2.getCommune(i)).size();
						P3 += M.getContractuels(G2.getCommune(i)).size();
						P4 += M.getStagiers(G2.getCommune(i)).size();
					}
					cout << endl
						<< "\t\tNombre de Persons dans ce Group : " << N << endl
						<< "\t\tTitulaires     : " << P << endl
						<< "\t\tNon-Titulaires : " << P2 << endl
						<< "\t\tContractuels   : " << P3 << endl
						<< "\t\tStagiers       : " << P4 << endl;
				}
				if (choix == 3) {
					G3.print();
					for (unsigned int i(0); i < G3.getCommN(); ++i) {
						N += G3.getCommune(i)->getPersN();
						P += M.getTilutaires(G3.getCommune(i)).size();
						P2 += M.getNonTilutaires(G3.getCommune(i)).size();
						P3 += M.getContractuels(G3.getCommune(i)).size();
						P4 += M.getStagiers(G3.getCommune(i)).size();
					}
					cout << endl
						<< "\t\tNombre de Persons dans ce Group : " << N << endl
						<< "\t\tTitulaires     : " << P << endl
						<< "\t\tNon-Titulaires : " << P2 << endl
						<< "\t\tContractuels   : " << P3 << endl
						<< "\t\tStagiers       : " << P4 << endl;
				}
				system("pause");
				system("cls");
				break;
			case 11:
				cout << "\t\tQuelle Commune veuillez-vous ajouter ce person ? :" << endl
					<< "\t\t[0] - Retourner " << endl
					<< "\t\t[1] Commune <" << CO1 << ">" << endl
					<< "\t\t[2] Commune <" << CO2 << ">" << endl
					<< "\t\t[3] Commune <" << CO3 << ">" << endl
					<< "\t\t[4] Commune <" << CO4 << ">" << endl
					<< "\t\t[5] Commune <" << CO5 << ">" << endl
					<< "\t\t[6] Commune <" << CO6 << ">" << endl
					<< "\t\t[7] Commune <" << CO7 << ">" << endl
					<< "\t\t[8] Commune <" << CO8 << ">" << endl
					<< "\t\t[9] Commune <" << CO9 << ">" << endl;
				cout << "\t\tEntrez votre Choix (SVP) : "; cin >> choix;
				system("cls");
				if (choix >= 1 && choix <= 3) for (unsigned int i(0); i < G1.getCommN(); ++i) if ((choix - 1) == i) M.showList(&G1[i]);
				if (choix >= 4 && choix <= 6) for (unsigned int i(0); i < G2.getCommN(); ++i) if ((choix - 4) == i) M.showList(&G2[i]);
				if (choix >= 7 && choix <= 9) for (unsigned int i(0); i < G3.getCommN(); ++i) if ((choix - 7) == i) M.showList(&G3[i]);
				system("pause");
				system("cls");
				break;
			case 0:
				N = 0; P = 0; P2 = 0; P3 = 0; P4 = 0;
				system("cls");
				G1.print();
				for (unsigned int i(0); i < G1.getCommN(); ++i) {
					N += G1.getCommune(i)->getPersN();
					P += M.getTilutaires(G1.getCommune(i)).size();
					P2 += M.getNonTilutaires(G1.getCommune(i)).size();
					P3 += M.getContractuels(G1.getCommune(i)).size();
					P4 += M.getStagiers(G1.getCommune(i)).size();
				}
				cout << "\t\t\tNext ";
				system("pause");
				system("cls");
				G2.print();
				for (unsigned int i(0); i < G2.getCommN(); ++i) {
					N += G2.getCommune(i)->getPersN();
					P += M.getTilutaires(G2.getCommune(i)).size();
					P2 += M.getNonTilutaires(G2.getCommune(i)).size();
					P3 += M.getContractuels(G2.getCommune(i)).size();
					P4 += M.getStagiers(G2.getCommune(i)).size();
				}
				cout << "\t\t\tNext ";
				system("pause");
				system("cls");
				G3.print();
				for (unsigned int i(0); i < G3.getCommN(); ++i) {
					N += G3.getCommune(i)->getPersN();
					P += M.getTilutaires(G3.getCommune(i)).size();
					P2 += M.getNonTilutaires(G3.getCommune(i)).size();
					P3 += M.getContractuels(G3.getCommune(i)).size();
					P4 += M.getStagiers(G3.getCommune(i)).size();
				}
				cout << endl
					<< "\t\tNombre de Persons  : " << N << endl
					<< "\t\tTitulaires         : " << P << endl
					<< "\t\tNon-Titulaires     : " << P2 << endl
					<< "\t\tContractuels       : " << P3 << endl
					<< "\t\tStagiers           : " << P4 << endl;
				cout << endl << endl;
				system("pause");
				system("cls");
				break;
			default:
				cout << "\t\tChoix pas valable veuillez essayer !!" << endl;
				system("cls");
				break;
				}
			}
    return 0;
}

