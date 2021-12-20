#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct noeud
{
	int cle;
	char *info_supp;
	struct noeud *gauche;
	struct noeud *droit;	
}noeud;

typedef struct cellule{
	noeud *n;
	struct cellule *suiv;
} cellule;

typedef struct {
	cellule *tete;
	cellule *queue;
	int nb_elt;
}Liste;

void insertion_equilibrer(noeud *racine, noeud *new_elt);
void afficherArbre(noeud racine);

int main(int argc, char *argv[])
{
	//Racine : 10. Insérer dans l'ordre : 5, 13, 7, 15, 3, 9, 1
	noeud racine = {10, "Pas d'info supplémentaire", NULL, NULL};
	noeud n1 = {5, "Pas d'info supplémentaire", NULL, NULL};
	noeud n2 = {13, "Pas d'info supplémentaire", NULL, NULL};
	noeud n3 = {7, "Pas d'info supplémentaire", NULL, NULL};
	noeud n4 = {15, "Pas d'info supplémentaire", NULL, NULL};
	noeud n5 = {3, "Pas d'info supplémentaire", NULL, NULL};
	noeud n6 = {9, "Pas d'info supplémentaire", NULL, NULL};
	noeud n7 = {1, "Pas d'info supplémentaire", NULL, NULL};



	
	insertion_equilibrer(&racine, &n1);
	insertion_equilibrer(&racine, &n2);
	insertion_equilibrer(&racine, &n3);
	insertion_equilibrer(&racine, &n4);
	insertion_equilibrer(&racine, &n5);
	insertion_equilibrer(&racine, &n6);
	insertion_equilibrer(&racine, &n7);
	

	afficherArbre(racine);

	//TODO:
	//Affiche prefixe/infixe//suffixe
	//Libération mémoire (liste)

	return 0;

}



void insererFinListe(Liste *L, noeud *elt)
{	
	cellule *new = (cellule*)malloc(sizeof(cellule));
	new -> suiv = NULL;
	new -> n = elt; 
	if(L->queue)
	{	
		L -> queue -> suiv = new;
	}else{
		L -> tete = new;
	}
	L -> queue = new;
	L -> nb_elt++;
}

cellule* SupTeteListe(Liste *L)
{
	//Retire la tete de liste et la retourne
	cellule *tete = L -> tete;
	if(tete == L -> queue)
		L -> queue = NULL;

	L -> tete = L -> tete -> suiv;
	return tete;
}

void insertion_equilibrer(noeud *racine, noeud *new_elt)
{	
	Liste L;
	cellule *init = (cellule *)malloc(sizeof(cellule));
	init -> n = racine;
	init -> suiv = NULL;
	L.tete = init;
	L.queue = init;
	L.nb_elt = 1;

	//On parcours les noeuds niveau par niveau pour pouvoir inserer au bon endroit (etage par etage)
	/*Exemple
					0
				1		2
		    3	   4 5 		6
		ici
	*/

	/* 
	 * On va donc parcourir les noeuds à l'aide d'une liste.
	 * On y insere à chaque fois les noeuds dans l'ordre
	 * On récupere ensuite le premier noeuds de la liste qui n'a pas de fils gauche/droit
	*/ 

	//On commence par recuperer une liste avec tous les noeuds
	cellule *parcourir = L.tete;
	while(parcourir != NULL)
	{
		if(parcourir -> n -> gauche)
		{
			insererFinListe(&L, parcourir -> n -> gauche);
		}
		if(parcourir -> n -> droit)
		{
			insererFinListe(&L, parcourir -> n -> droit);
		}
		parcourir = parcourir -> suiv;
	}
	//On a recupere tous les noeuds dans l'ordre

	/* POUR LES NON TARéS REGARDER DIRECTEMENT EN BAS
	//Version pour taré qui veut se faire chier on peut ajouter ça avant:

	//On se positionne sur le bon niveau
	int niveau = log2(L.nb_elt);//Gere l'arrondi inferieur
	parcourir = L.tete;//Niveau 0
	int nb_elt_niveau = 1;
	int i = 0;
	while(i < niveau)
	{	
		//On change de niveau
		parcourir = parcourir -> suiv;
		nb_elt_niveau *= 2;//Chaque niveau a 2x plus d'elements que le precedent

		int j = 1;
		while(j < nb_elt_niveau)
		{
			j++
			parcourir = parcourir -> suiv;
		}
		i++;
	}
	*/
	
	//On insere maintenant sur le 1er noeud n'ayant pas ses deux fils non null
	
	parcourir = L.tete;//Version taré: mettre en commentaire cette ligne
	while( (parcourir -> n -> gauche != NULL) && (parcourir -> n -> droit != NULL))
	{
		parcourir = parcourir -> suiv;
	}
	if(parcourir -> n -> gauche == NULL)
		parcourir -> n -> gauche = new_elt;
	else
		parcourir -> n -> droit = new_elt;

	//Tout ça pour mettre un noeud dans un arbre putin
}


void afficherArbre(noeud racine)
{
	Liste L;
	cellule *init = (cellule *)malloc(sizeof(cellule));
	init -> n = &racine;
	init -> suiv = NULL;
	L.tete = init;
	L.queue = init;
	L.nb_elt = 1;
	//On commence par recuperer une liste avec tous les noeuds
	cellule *parcourir = L.tete;
	while(parcourir != NULL)
	{
		if(parcourir -> n -> gauche)
		{
			insererFinListe(&L, parcourir -> n -> gauche);
		}
		if(parcourir -> n -> droit)
		{
			insererFinListe(&L, parcourir -> n -> droit);
		}
		parcourir = parcourir -> suiv;
	}

	//Maintenant on affiche
	parcourir = L.tete;
	while(parcourir)
	{
		printf("clé: %d, info:%s\n", parcourir -> n -> cle, parcourir -> n -> info_supp);
		parcourir = parcourir -> suiv;
	}
}