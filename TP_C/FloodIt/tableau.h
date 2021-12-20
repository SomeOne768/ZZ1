#ifndef tableau_h
#define tableau_h


#define COULEUR 6
#define TAILLE 12



typedef struct Element{
    int x;
    int y;
    struct Element *suivant;
} Element;

struct Liste{
    Element *debut;
};

typedef struct Liste Liste;

void initialiser(int tab[TAILLE][TAILLE]);
void affichage(int tab[TAILLE][TAILLE]);
//Version recursive:
void remplir(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres, int i, int j);

//Version non recursive:
void remplir_Non_Rec(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres);


#endif