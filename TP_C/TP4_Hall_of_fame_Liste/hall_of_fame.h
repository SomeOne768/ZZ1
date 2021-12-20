#ifndef hall_of_fame_h
#define hall_of_fame_h

#define TAILLE_MAX 50


/* DECLARATION DES TYPES PERSONNELS */

struct donnee{
   int score;
   char jeu[100];
   char alias[40];
   struct donnee *suivant;
};


// et de leur typedef si besoin
typedef struct donnee donnee_t;

/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
// mettre ici les autres declarations

int tableauFromFilename(char *filename, donnee_t tab[TAILLE_MAX]);


/* **************************************** */
/* Liste chainée */
//Choix tete de la liste: fictive (un pointeur d'une sctructure qui pointera sur la tête)
typedef struct Liste_Donnee
{
   donnee_t *debut;
}Liste_Donnee;

Liste_Donnee creerListe();

void afficherListe(Liste_Donnee L);
void insererListe(Liste_Donnee *L, donnee_t **e);
void libererListe(Liste_Donnee *L);
donnee_t* creerElt(int score, char *jeu, char *alias);
void menu(Liste_Donnee *L);
void saveList(char *filename, Liste_Donnee L);
#endif