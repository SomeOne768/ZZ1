#ifndef tableau_h
#define tableau_h


#define COULEUR 6
#define TAILLE 12


/*

typedef struct Element{
    int x;
    int y;
    Element *suivant;
} Element;

struct Liste{
    Element *debut;
};

typedef struct Liste Liste;

Element* creerElt(int x, int y)
{
    Element *p = (Element*)malloc(sizeof(Element));
    p->x = x;
    p->y = y;
    p->suivant = NULL;
    return p;
}

int estVideListe(Liste l)
{
    return (l.debut == NULL);
}

Element* defiler(Liste *file)
{
    Element *retour = NULL;
    if(file->debut)
    {
        retour = file->debut;
        file->debut = file->debut->suivant;
    }
    return retour;
}
*/

void initialiser(int tab[TAILLE][TAILLE]);
void affichage(int tab[TAILLE][TAILLE]);
void remplir(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres, int i, int j);
int gagne(int grille[TAILLE][TAILLE]);

#endif