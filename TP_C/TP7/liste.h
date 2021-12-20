#ifndef LISTE_H
#define LISTE_H


#define TAILLE 255

typedef struct cellule{
	char ligne[TAILLE];
	struct cellule *suiv;
}cellule;


typedef struct liste{
	cellule *tete;
	cellule *fin;
}liste;

int estVideListe(liste L);
cellule* creerElement(char *ligne);
liste creerListe();
void insertionTete(liste *L, char *string);
void insertionFin(liste *L, char *string);
void afficherListe(liste L);
void libererListe(liste *L);

//partie 2

typedef struct cellule2{
	char *ligne;
	struct cellule2 *suiv;
}cellule2;

typedef struct liste2{
	cellule2 *tete;
	cellule2 *fin;
}liste2;

int estVideListe2(liste2 L);
cellule2* creerElement2(char *ligne);
liste2 creerListe2();
void insertionTete2(liste2 *L, char *string);
void insertionFin2(liste2 *L, char *string);
void afficherListe2(liste2 L);
void libererListe2(liste2 *L);

#endif