#ifndef hall_of_fame_h
#define hall_of_fame_h

#define TAILLE_MAX 50


/* DECLARATION DES TYPES PERSONNELS */

/* /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ */

//ICI LES NOMS DES CHAMPS DE LA STRUCTURE SONT DIFFERENTS DE CEUX DANS LES TESTS INITIAUX

struct donnee{
   int score;
   char jeu[100];
   char alias[40];
};


// et de leur typedef si besoin
typedef struct donnee donnee_t;

/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
// mettre ici les autres declarations

int tableauFromFilename(char *filename, donnee_t tab[TAILLE_MAX]);

#endif