#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"

int estVideListe(liste L)
{
	return L.tete == NULL;
	//Ou encore L.fin == NULL
	//Equivalent à return !L.tete
	//Car si null => !NULL = !0 = vrai
}


cellule* creerElement(char *ligne)
{
	cellule *new_element = (cellule*)malloc(sizeof(cellule));
	if(new_element)
	{
		//allocation réussie
		strcpy(new_element->ligne, ligne);
		new_element -> suiv = NULL;
	}else{
		perror("Erreur allocation mémoire");
	}
	return new_element;
}


liste creerListe()
{
	//Nécessaire car si case mémoire déjà utilisé avant => champs de la structure peuvent être non NULL
	liste L;
	L.tete = NULL;
	L.fin = NULL;
	return L;
}
void insertionTete(liste *L, char *string)
{
	//Necessaire d'utiliser un pointeur pour modifier les champs de notre structure liste
	//Fonction à utiliser avec une liste réelle (&L)
	cellule *new_element = creerElement(string);
	new_element->suiv = L->tete;
	if(estVideListe(*L))
	{
		L -> fin = new_element;
	}

	L -> tete = new_element;

}


void insertionFin(liste *L, char *string)
{
	cellule *new_element = creerElement(string);
	if(estVideListe(*L))
	{
		L -> tete = new_element;
	}else{
		L -> fin -> suiv = new_element;
	}
	L -> fin = new_element;
}


void afficherListe(liste L)
{
	cellule *parcourir = L.tete;
	while(parcourir)
	{
		printf("%s", parcourir->ligne);
		parcourir = parcourir -> suiv;
	}
}

void libererListe(liste *L)
{
	cellule *parcourir = L->tete;
	while(parcourir)
	{
		cellule *tmp = parcourir;
		parcourir = parcourir->suiv;
		free(tmp);
	}
	L -> tete = NULL;
	L -> fin = NULL;
}



//Partie 2

//Même fonctions mais adaptation avec nouveau type
//2 modifications: creerElement & liberation
//On aurait pu utiliser une union mais inutile car on perdrait de la mémoire ce qui est contraire à l'objectif

int estVideListe2(liste2 L)
{
	return L.tete == NULL;
	//Ou encore L.fin == NULL
	//Equivalent à return !L.tete
	//Car si null => !NULL = !0 = vrai
}


cellule2* creerElement2(char *ligne)
{
	cellule2 *new_element = (cellule2*)malloc(sizeof(cellule2));
	if(new_element)
	{
		//allocation réussie
		new_element -> ligne = (char*)malloc(sizeof(char) * (1 + strlen(ligne)) );//On prévoit une case de plus pour '\0'
		if(new_element -> ligne){
			strcpy(new_element->ligne, ligne);
			new_element -> suiv = NULL;
		}else{
			perror("Erreur allocation mémoire\n");
		}
	}else{
		perror("Erreur allocation mémoire\n");
	}
	return new_element;
}


liste2 creerListe2()
{
	//Nécessaire car si case mémoire déjà utilisé avant => champs de la structure peuvent être non NULL
	liste2 L;
	L.tete = NULL;
	L.fin = NULL;
	return L;
}


void insertionTete2(liste2 *L, char *string)
{
	//Necessaire d'utiliser un pointeur pour modifier les champs de notre structure liste
	//Fonction à utiliser avec une liste réelle (&L)
	cellule2 *new_element = creerElement2(string);
	new_element->suiv = L->tete;
	if(estVideListe2(*L))
	{
		L -> fin = new_element;
	}

	L -> tete = new_element;

}


void insertionFin2(liste2 *L, char *string)
{
	cellule2 *new_element = creerElement2(string);
	if(estVideListe2(*L))
	{
		L -> tete = new_element;
	}else{
		L -> fin -> suiv = new_element;
	}
	L -> fin = new_element;
}


void afficherListe2(liste2 L)
{
	cellule2 *parcourir = L.tete;
	while(parcourir)
	{
		printf("%s", parcourir->ligne);
		parcourir = parcourir -> suiv;
	}
}

void libererListe2(liste2 *L)
{
	cellule2 *parcourir = L->tete;
	while(parcourir)
	{
		cellule2 *tmp = parcourir;
		parcourir = parcourir->suiv;
		free(tmp->ligne);
		free(tmp);
	}
	L -> tete = NULL;
	L -> fin = NULL;
}