#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tableau.h"



void initialiser(int tab[TAILLE][TAILLE])
{
    /* initialisation du tableau avec des couleurs aléatoire */
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


/*
void remplir(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres, unsigned int i, unsigned int j)
{*/
    /* 
     *  Fonction qui permet la propagation de la nouvelle couleur.
     *  On part de la case 0, si une case adjacente est de même couleur que la case 0 on propage le changement de couleur.
     *  On propage tant que la couleur est identique et que les cases sont adjacentes
     *  Afin d'éviter des nouvelles recherche on peut utiliser une liste nous permettant de garder les cases deja adjacente
     *  et ajouter seulement les nouvelles à chaque fois puis changer les couleurs des coordonnées appartenant à notre liste.
    */
/*
   Liste adjacent;
   adjacent.debut = creerElt(0, 0);
   Liste file;
   file.debut = creerElt(0, 0);
   while(!estVideListe(file))
   {
       //On recupere les cases adjacente ayant la bonne couleur des elements de notre file
       int x,y;
       x = file.debut->x;
       y = file.debut->y;
       if(tab[x][y+1] == couleur_avant)
       {
           //On commence par regarder celui qui est à droite
           
       }
   }
}*/


//Méthode recursive:

void remplir(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres, int i, int j)
{
    //Fonction a appelé avec les coordonnées 0,0 pour faire la propagation de manière correcte.
    //Vérification des coordonnées:
    if( !(i<0 || i>=TAILLE || j<0 || j>=TAILLE) && tab[i][j] == couleur_avant)
    {
        tab[i][j] = couleur_apres;
        remplir(tab, couleur_avant, couleur_apres, i+1, j);
        remplir(tab, couleur_avant, couleur_apres, i, j+1);
        remplir(tab, couleur_avant, couleur_apres, i-1, j);
        remplir(tab, couleur_avant, couleur_apres, i, j-1);
    }
}

void remplir2(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres, int i, int j)
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


int gagne(int grille[TAILLE][TAILLE])
{
    int i,j,couleur = grille[0][0];
    for(i=0; i<TAILLE; i++)
    {
        for(j=0; j<TAILLE; j++)
        {
            if(couleur != grille[i][j])
                return 0;
        }
    }

    return 1;
}