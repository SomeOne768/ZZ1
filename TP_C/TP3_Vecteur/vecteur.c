#include "vecteur.h"
#include<stdlib.h>

// definition des fonctions declarees dans vecteur.h

/* Il est recommande d'utiliser fgets au lieu de fscanf,
   j'ai la flemme de tout remplace mais voici les fonctions necessaires:
*/
/*
void supprimerRetourLigne(char tab[], int taille)
{
	//Version avec un tableau statique
	int i=0;
	while(i<taille && tab[i] != '\n')
	{
		i++;
	}

	//On verifie la presence du \n
	if(i!=taille)
	{
		ligne[i] = '\0';
	}
}

void supprimerRetourLigne(char *ligne)
{
	//Version avec un pointeur
	if(ligne)
	{
		//Pointeur non null
		int i = 0;
		while(ligne[i] != '\0' && ligne[i] != '\n')
		{
			//Tant qu'on est pas en fin de chaine et qu'on a pas croise le retour a la ligne
			i++;
		}

		//On verifie la presence du \n
		if(ligne[i] == '\n')
		{
			ligne[i] = '\0';
		}
	}
}

//utilisation dans la fonction:
fgets(votre_tableau_Char, sa_taille, le_pointeur_de_fichier);
*/


void vecteurToFile(FILE *f, float *vector, unsigned int taille)
{
	//test de validite des parametres fichier
	if(f == NULL || vector == NULL)
	{
		printf("Mauvaise entrée.\n");
	}else{

		fseek(f, 0, SEEK_SET);//Positionnement du pointeur au debut du fichier
		//1ere ligne = taille du vecteur
		fprintf(f, "%d\n", taille);
		for(unsigned int i=0; i<taille; i++)
		{
			//Composante i du vecteur
			fprintf(f, "%f\n", vector[i]);
		}
		

		/*Pour correspondre au format du test:
		fprintf(f, "[ ");
		for(unsigned int i=0; i<taille; i++)
		{
			//Composante i du vecteur
			fprintf(f, "%.3f ", vector[i]);
		}
		fprintf(f, "]");
		*/
	}
}

float * vecteurFromFileByName(char *name, unsigned int *taille) 
{
	float * retour = NULL;

	//Ouverture du fichier en mode lecture
	FILE *f = fopen(name, "r");
	if(f == NULL)
	{
		printf("Erreur fichier.\n");
		exit(-1);
	}

	//Mise au debut du pointeur de fichier
	fseek(f, 0, SEEK_SET);
	
	//Recuperation de la taille
	fscanf(f, "%d\n", taille);

	//Attribution du bon nombre de case mémoire au vecteur
	retour = (float*) malloc(sizeof(float) * (*taille));
	if(retour == NULL)
	{
		printf("Problème d'attribution de mémoire.\n");
	}else{
		
		//Récuparation du vecteur
		for(unsigned int i=0; i<(*taille); i++)
		{
			//Recupere le float d'une ligne a chaque fois, /!\ necessaire que le fichier respecte le format
			fscanf(f, "%f\n", &retour[i]);
		}
	}

	fclose(f);
	return retour;
}



float produitScalaire(float *v1, float *v2, unsigned int taille) 
{	
	float retour =0;
	for(unsigned int i=0; i<taille; i++)
	{
		retour += v1[i] * v2[i];
	}

    return retour;
} 


/*

void AffichageA(FILE *f, float **vector, unsigned int taille)
{
	for(unsigned int i=0; i<taille; i++)
	{
		printf("%f\n", (*vector[i]));
	}
}*/