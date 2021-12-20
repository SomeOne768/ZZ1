#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


void deleteLine(char *tab, int taille)
{
   int i = 0;
   while(i<taille && tab[i] != '\n')
   {
      i++;
   }
   if(i != taille)
      tab[i] = '\0';
}
// un petit commentaire ?
void afficherDonnee(FILE * stream, donnee_t d) {
   // TO DO
   fprintf(stream, "%s : %s avec %d\n", d.jeu, d.alias, d.score);
}

// un petit commentaire ?
void saisirDonnee(FILE *file, donnee_t * p){
   // TO DO
   fscanf(file, "%s\n%s\n%d", p->jeu, p->alias, &p->score);
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
   fseek(f, 0, SEEK_SET);
   
   //Récupération des données jusqu'à TAILLE_MAX maximum
   int i = 0;
   while(!feof(f) && i<50)
   {
      //Tant qu'on a pas extrait toutes les données et que le nombre extrait est inférieur à 50:
      fscanf(f, "%s\n%s\n%d\n",
         tab[i].jeu,
         tab[i].alias,
         &tab[i].score);
      i++;

   }
   return i;

   //On a récupérer au maximum 50 éléments
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



/******** PARTIE LISTE *********/

Liste_Donnee creerListe()
{
   //Fonction utile même si liste vide
   //Permet de s'assurer que le pointeur sera NULL et non une ancienne valeur tampon
   Liste_Donnee L;
   L.debut = NULL; 
   return L;
}

donnee_t* creerElt(int score, char *jeu, char *alias)
{
   donnee_t *elt = (donnee_t *) malloc(sizeof(donnee_t));
   elt->score = score;
   strcpy(elt->alias, alias);
   strcpy(elt->jeu, jeu);
   elt->suivant = NULL;
   return elt;
}
void afficherListe(Liste_Donnee L)
{
   donnee_t *parcourir = L.debut;
   while(parcourir!=NULL)
   {
      afficherDonnee(stdout, (*parcourir));
      parcourir = parcourir->suivant;
   }
}

void insererListe(Liste_Donnee *L, donnee_t **e)
{
   //Inserer en tête de liste
   if(L->debut == NULL)
   {
      printf("Liste vide\n");
      //La liste est vide pas besoin de déplacer le reste
      L->debut = (*e);
   }else{
      //Ajouter au nouvel element l'ancien début de la liste
      (*e)->suivant = L->debut;
      L->debut = (*e);
   }
}

void libererListe(Liste_Donnee *L)
{
   if(L)
   {
      donnee_t *parcourir = L->debut;

      while(parcourir != NULL)
      {
         //tant qu'il existe un element dans L on avance parcourir, on free L debut et on lui réattribue la valeur parcourir
         donnee_t *eraser = parcourir;
         parcourir = parcourir->suivant;
         free(eraser);

         /*
         parcourir = parcourir->suivant;
         free(L->debut);
         (*L).debut = parcourir;
         */
      }
   }
}




void saveList(char *filename, Liste_Donnee L)
{
   //Ouverture d'un nouveau fichier en ecriture
   FILE *f = fopen(filename, "w");

   if(f == NULL)
   {
      perror("Problème ouverture fichier\n");
   }else{
      
      donnee_t *parcourir = L.debut;
      while(parcourir)
      {
         fprintf(f, "%s\n%s\n%d\n", parcourir->jeu, parcourir->alias, parcourir->score);
         parcourir = parcourir->suivant;
      }
      printf("Sauvegarde effectuée\n");
   }
   fclose(f);
}





void menu(Liste_Donnee *L)
{
   int continuer = 1;
   while(continuer)
   {
      printf("\nQue voulez-vous faire ?\n");
      printf("1- Afficher la liste\n");
      printf("2- Inserer un nouvel élément en tête de liste\n");
      printf("3- Quitter\n");
      printf("4- Editer/modifier un elt\n");
      printf("5- Sauvegarder la liste dans un fichier\n");
      
      int choix;
      scanf(" %d", &choix);
      printf("Votre choix: %d\n", choix);
      switch(choix)
      {
         case 1:
            afficherListe(*L);
            break;

         case 2:
            //TODO:
            printf("Saisissez le nom du jeu.\n");
            char jeu[100];
            scanf("%s", jeu);

            printf("Saisissez le nom du joueur.\n");
            char nom[40];
            scanf("%s", nom);

            printf("Saisissez le score.\n");
            int score;
            scanf("%d", &score);

            donnee_t *elt = creerElt(score, jeu, nom);
            insererListe(L, &elt);
            break;

         case 3:
            continuer = 0;
            break;

         case 4:
            //TODO
            //On effectue une recherche par nom
            printf("Quel element voulez-vous modifier ? \n");
            printf("J'ai la flemme on fait que en fonction du nom, donne le !\n");
            char name[40];
            scanf("%s", name);
            printf("Nouveau score ?.\n");
            int new_score;
            scanf(" %d", &new_score);

            donnee_t *parcourir = L->debut;
            while(parcourir != NULL && strcmp(parcourir->alias, name))
            {
               parcourir = parcourir->suivant;
            }
            if(parcourir)
            {
               parcourir->score = new_score;
            }else{
               printf("Ce nom n'existe pas, tu me casse les pieds\n");
            }
            break;

         break;

         case 5:
            //save file
            printf("Nom imposé.\n");
            char *filename= "JeNeDemandePas.txt";
            saveList(filename, *L);
            break;

         default:
            printf("Mauvaise valeur saisie, arrêtez d'être con Mr l'utilisateur.\n");
            break;
      }

   }
}