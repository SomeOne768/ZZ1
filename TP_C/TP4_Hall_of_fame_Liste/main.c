#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"



int  main()
{
    Liste_Donnee L = creerListe();

    /* PARTIE 1
    //ajout d'un element en début de liste
    donnee_t e1 = {10000, "No Game", "Someone", NULL};
    L.debut = &e1;

    //ajout d'un element en fin de liste
    donnee_t e2 = {10000, "No Pain", "one", NULL};
    L.debut->suivant = &e2;

    //Ajout d'un element en tete de liste
    donnee_t e3 = {1545640, "No Game", "Some", NULL};
    e3.suivant = L.debut;
    L.debut = &e3;

    afficherListe(L);
    */

    
    /*
    donnee_t e1 = {10000, "No Game", "Someone", NULL};
    donnee_t e2 = {10000, "No Pain", "one", NULL};
    donnee_t e3 = {1545640, "No Game", "Some", NULL};
    */

    donnee_t *e1 = creerElt(10000, "No Game", "Someone");
    donnee_t *e2 = creerElt(10000, "No Pain", "one");
    donnee_t *e3 = creerElt(1545640, "No Game", "Some");
    insererListe( &L, &e3);
    insererListe( &L, &e2);
    insererListe( &L, &e1);
    afficherListe(L);
    //libererListe(&L); Ici les elements ont ete ajoutes a partir de donnees statique => pas de free

    //Partie 3.2
    Liste_Donnee L2 = creerListe();
    menu(&L2);

    return 0;
}