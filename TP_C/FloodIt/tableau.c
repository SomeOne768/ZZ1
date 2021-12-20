#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tableau.h"



void initialiser(int tab[TAILLE][TAILLE])
{
    /* initialisation du tableau avec des couleurs aléatoires */
    srand(time(NULL));
    int r;
    for(int i = 0; i<TAILLE; i++)
    {
        for(int j=0; j<TAILLE; j++)
        {
            r = rand()%COULEUR;
            tab[i][j] = r;
        }
    }
}

void affichage(int tab[TAILLE][TAILLE])
{
    /* Affichage de chacune des cases de notre tableau de jeu */
    int i,j;
    for(i=0; i<TAILLE; i++)
    {   
        printf("|");
        for(j=0; j<TAILLE; j++)
        {
            printf(" %d |", tab[i][j]);
        }
        printf(" \n");
    }
}

int fin(int tab[TAILLE][TAILLE])
{
    /* Détermine si le jeu est terminé (toute les cases sont de la même couleur) */
    /* Retourne 1 si toutes les cases sont de même couleur, 0 sinon */
    int i, j;
    int couleur = tab[0][0];
    for(i=0; i<TAILLE; i++)
    {   
        for(j=0; j<TAILLE; j++)
        {
            if(tab[i][j] != couleur)
            {
                return 0;
            }
        }
    }
    return 1;
}





//Méthode recursive:

void remplir(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres, int i, int j)
{
    //Fonction a appelé avec les coordonnées 0,0 pour faire la propagation de manière correcte.
    //Vérification des coordonnées:
    if(i<0 || i>=TAILLE || j<0 || j>=TAILLE)
    {
        printf("Erreur coordonnées\n");
    }else{
        //On regarde TOUTES les cellules adjacentes dans les 4 directions.
        //Même si recursif, on ne passera jamais 2* dans la même case puisqu'elle aura changer de couleur
        tab[i][j] = couleur_apres;

        if(j+1<TAILLE)
        {
            //On regarde la couleur à droite
            if(tab[i][j+1] == couleur_avant)
            {
                //On propage à droite
                remplir(tab, couleur_avant, couleur_apres, i, j+1);
            }
        }

        if(j-1>=0)
        {
            //On regarde la couleur à gauche
            if(tab[i][j-1] == couleur_avant)
            {
                //On propage à gauche
                remplir(tab, couleur_avant, couleur_apres, i, j-1);
            }
        }

        if(i+1<TAILLE)
        {
            //On regarde la couleur en bas
            if(tab[i+1][j] == couleur_avant)
            {
                //On propage en bas
                remplir(tab, couleur_avant, couleur_apres, i+1, j);
            }
        }

        if(i-1>=0)
        {
            //On regarde la couleur en haut
            if(tab[i-1][j] == couleur_avant)
            {
                //On propage en haut
                remplir(tab, couleur_avant, couleur_apres, i-1, j);
            }
        }
    }
}





//Fonction utilitaire pour la version non recursive
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

Element* depiler(Liste *pile)
{
    //Enleve le dernier element ajouté/tête de liste et le retourne
    Element *retour = NULL;
    if(pile->debut)
    {
        retour = pile->debut;
        pile->debut = pile->debut->suivant;
    }
    return retour;
}

void ajoutTete(Liste *L, Element *e)
{
    //ajout en tete de liste
    e->suivant = L->debut;
    L->debut = e;
}


//Version non recursive
void remplir_Non_Rec(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres)
{
    /* 
     *  Fonction qui permet la propagation de la nouvelle couleur.
     *  On part de la case 0, si une case adjacente est de même couleur que la case 0 on propage le changement de couleur.
     *  On propage tant que la couleur est identique et que les cases sont adjacentes
     *  Afin d'éviter des nouvelles recherche on peut utiliser une liste nous permettant de garder les cases deja adjacente
     *  et ajouter seulement les nouvelles à chaque fois puis changer les couleurs des coordonnées appartenant à notre liste.
    */

   Liste pile;
   pile.debut = creerElt(0, 0);
   tab[0][0] = couleur_apres;

   while(!estVideListe(pile))
   {
        //On recupere les coordonnees de notre tete de liste et on lui change sa couleur
        int x,y;
        x = pile.debut->x;
        y = pile.debut->y;
        

        //On n'oublie pas de le retirer de la liste + de liberer la case mémoire
        Element *e = depiler(&pile);
        free(e);

        //On recupere les cases adjacente ayant la bonne couleur
        if( (y+1)<TAILLE && tab[x][y+1] == couleur_avant)
        {
            //On commence par regarder celui qui est à droite
            Element *droite = creerElt(x, y+1);
            ajoutTete(&pile, droite);
            //On effectue le changement ici pour ne pas creer de doublons dans la liste
            tab[x][y+1] = couleur_apres;
        }

        if( (y-1)>=0 && tab[x][y-1] == couleur_avant)
        {
            //A gauche
            Element *gauche = creerElt(x, y-1);
            ajoutTete(&pile, gauche);
            tab[x][y+1] = couleur_apres;
        }

        if( (x-1)>=0 && tab[x-1][y] == couleur_avant)
        {
            //En haut
            Element *haut = creerElt(x-1, y);
            ajoutTete(&pile, haut);
            tab[x-1][y] = couleur_apres;
        }

        if( (x+1)<TAILLE && tab[x+1][y] == couleur_avant)
        {
            //En bas
            Element *bas = creerElt(x+1, y);
            ajoutTete(&pile, bas);
            tab[x+1][y] = couleur_apres;
        }
   }

   //A la sortie, la liste est vide, pas besoin de free
}