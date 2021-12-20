#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


// un petit commentaire ?
void afficherDonnee(FILE * stream, donnee_t d) {
   // TO DO
   fprintf(stream, "%s : %s avec %d\n", d.jeu, d.alias, d.score);
}

// un petit commentaire ?
void saisirDonnee(FILE *file, donnee_t * p){
   // TO DO
   fscanf(file, "%s\n%s\n%d", p->jeu, p->alias, &p->score);
   //Il est preferable d'utiliser fgets voir fichier TP3_Vecteur/vecteur.c
}

void useless()
{
   struct donnee essaie;
   essaie.score = 0;
   strcpy(essaie.jeu, "NO PAIN NO GAME");
   strcpy(essaie.alias, "SOMEONE");

   printf("score: %d\nJeu: %s\nAlias: %s", essaie.score, essaie.jeu, essaie.alias);

   donnee_t essai;
   essai.score = 0;
   strcpy(essai.jeu, "NO PAIN NO GAME");
   strcpy(essai.alias, "SOMEONE");

   printf("score: %d\nJeu: %s\nAlias: %s", essai.score, essai.jeu, essai.alias);
   
}

int tableauFromFilename(char *filename, donnee_t tab[TAILLE_MAX])
{
   //Permet de lire les données à partir d'un fichier texte
   /* Ordre:
      -ligne 1 : nom du jeu
      -ligne 2: nom du joueur
      -ligne 3: score
   */

   //Ouverture du ficher
   FILE *f = fopen(filename, "r");
   if(f == NULL)
   {
      perror("Erreur d'ouverture fichier pour la récupération des données.\n");
      return 0;
   }

   //Positionnement du pointeur en debut de fichier
   fseek(f, 0, SEEK_SET);
   
   //Récupération des données jusqu'à TAILLE_MAX maximum
   int i = 0;
   while(!feof(f) && i<50)
   {
      //feof(f) permet de verifier que f n'est pas en fin de fichier
      //Tant qu'on a pas extrait toutes les données et que le nombre extrait est inférieur à 50:
      fscanf(f, "%s\n%s\n%d\n",
         tab[i].jeu,
         tab[i].alias,
         &tab[i].score);
      i++;

   }
   fclose(f);
   return i;

   //On a recupere au maximum 50 éléments
}

void dataToFile(FILE *stream, donnee_t *tab, unsigned int taille)
{
   if(stream == NULL)
   {
      perror("Impossible de sauvegarder le tableau, le pointeur est NULL");
   }else{
      unsigned int i;
      for(i=0; i<taille; i++)
      {
         fprintf(stream, "%s\n%s\n%d\n", tab[i].jeu, tab[i].alias, tab[i].score);
      }
   }
}