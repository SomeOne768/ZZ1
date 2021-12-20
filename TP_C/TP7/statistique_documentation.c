#include <stdio.h>
#include <stdlib.h>

/*** Objectif
 * Lire un fichier puis
 * recuperer les commentaires
 * les #
 * les prototypes de fonctions
*/

//Pour des raisons de flemmingite aigue, on considere que l'on repere une fonction seulement via les accolades
void lectureFichier(char *filename)
{
	FILE *f = fopen(filename, "r");
	if(f == NULL)
	{
		perror("Erreur ouverture fichier.\n");
	}
	FILE *f2 = fopen("Doc.txt", "w"); //Fichier de récupération
	fseek(f, 0, SEEK_SET);
	int accolade = 0; //permet de savoir si nous somme dans une fonction
	char *ligne;
	int taille;
	while(!feof(f))
	{
		long pos = ftell(f);
		//Recherche de # ou // ou /* ou {}
		while(!feof(f))
		{
			char c = fgetc(f);
			if((c == '#') || (c == '{') || (c == '/'))
			{
				//Si l'on est sur un # on recupere la ligne entiere
				if(c == "#"){
					getline(&ligne, &taille, f);
				}else if(c == '{' && accolade == 0){
					accolade++;
				}
				fprintf(f2, "%c%s",c, ligne);


			}
		}
	}
}

