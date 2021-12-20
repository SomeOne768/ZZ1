#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"

//Découper en plusieurs parties, dcommenter /* ET */ pour tester les parties 1 à 1

int main(int argc, char **argv)
{
	/**** BUT:
	 * lire des chaines au claver et les inserer en fin de liste
	 * afficher le resultat
	 * ###fin### => fin de saisie
	*/

	//Début du programme
	printf("Boujour je suis Loic ! ;;;;;;;;)\n");



	/***** PARTIE 1 ****/
	/*
	//Initialisation
	liste L = creerListe();

	//signature fgets: char *fgets(char *s, int size, FILE *stream);
	int arret = 0;
	char saisie[TAILLE];
	while(!arret)
	{
		printf("Veuillez saisir une ligne\n");

		if(fgets(saisie, TAILLE, stdin))
		{
			//Lecture réussie
			if(!strcmp("###fin###\n", saisie)){
				//strcmp renvoie 0 si les chaines sont identiques
				arret = 1;
			}
			else{
				insertionFin(&L, saisie);
			}
		}else{
			perror("Problème récupération saisie.\n");
		}
	}
	afficherListe(L);
	libererListe(&L);
	*/




	/***** PARTIE 1.2 ****/
	//Avec lecture de fichier (nom passé en argument)
	/*
	liste L = creerListe();
	if(argc>1)
	{
		FILE *f = fopen(argv[1], "r");
		if(f == NULL)
		{
			fprintf(stdout, "Erreur ouverture fichier\n");
			exit(1);//Permet de stopper le programme
		}

		//Positionnement en dbut de fichier
		fseek(f, 0, SEEK_SET);
		char saisie[TAILLE];
		while(!feof(f))
		{
			//Tant qu'on est pas en fin de fichier
			fgets(saisie, TAILLE, f);
			insertionFin(&L, saisie);
		}
	}


	afficherListe(L);
	libererListe(&L);
	*/



	/***** PARTIE 1.3 ****/
	/*
	liste2 L2 = creerListe2();
	if(argc>1)
	{
		FILE *f = fopen(argv[1], "r");
		if(f == NULL)
		{
			fprintf(stdout, "Erreur ouverture fichier\n");
			exit(1);//Permet de stopper le programme
		}

		//Positionnement en dbut de fichier
		fseek(f, 0, SEEK_SET);
		char saisie[1048];
		while(!feof(f))
		{
			//Tant qu'on est pas en fin de fichier
			fgets(saisie, TAILLE, f);
			insertionFin2(&L2, saisie);
		}
	}
	afficherListe2(L2);
	libererListe2(&L2);
	*/


	//Partie 2
	/*** Objectif:
	 * lire un .c ou un .h passé en argument
	 * Afficher seulement lignes:
	 * -#
	 * -prototype fonction
	 * -Commentaire => // & /* -> */

	return 0;
}