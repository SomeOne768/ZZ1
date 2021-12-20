// on appelle cette constante symbolique un gardien, cela permet de s'assurer que ce fichier
// ne sera pas inclus de maniere recursive
#ifndef C3__VECTEUR_H
#define C3__VECTEUR_H

#include <stdio.h>

// prototypes incomplets des fonctions a coder
// void    vecteurToFile();
void vecteurToFile(FILE *f, float *vector, unsigned int taille);
// float * vecteurFromFileByName();
float * vecteurFromFileByName(char *name, unsigned int *taille) ;

// float   produitfScalaire();
float produitScalaire(float *v1, float *v2, unsigned int taille) ;

void AffichageA(FILE *f, float **vector, unsigned int taille);

#endif