#include <stdio.h>
#include "tableau.h"
#include <SDL2/SDL.h>


int jeu[TAILLE][TAILLE];


int main()
{
    /* Jouer une partie:
     * -initialiser la grille
     * -afficher la grille
     * -boucle qui recupere:
     * -i)Un nombre qui correspond à une couleur ou 999 pour sortir du jeu
     * -ii)Lance la propagation avec remplir
     * -iii)Arrete le jeu si on a fait 22 coup
    */

    initialiser(jeu);
    affichage(jeu);
    int nb_coup = 0;
    while(nb_coup <= 22)
    {
        nb_coup++;
        //On récupere la couleur
        printf("Veuillez saisir une couleur entre 0 et %d\n", COULEUR-1);
        int couleur;
        scanf("%d", &couleur);

        //On vérifie la valeur saisie
        if(couleur>=0 && couleur<COULEUR && (couleur!=jeu[0][0]))
        {
            //On effectue la propagation à partir de la case 0
            remplir(jeu, jeu[0][0], couleur, 0, 0);
        }else{
            if(couleur == 999)
                break;
            else
                printf("Mauvaise couleur saisie. 999 pour quitter le jeu\n");
        }

        //Enfin on affiche notre jeu
        affichage(jeu);           
    }

    return 0;
}