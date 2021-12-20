#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

#define NB_GUICHET 3


void fermeture(int *guichet_A, int *guichet_B, int *guichet_C);
void fermetureV2(int tab[], int taille);

int main()
{
    int guichet_A, guichet_B, guichet_C;
    fermeture(&guichet_A, &guichet_B, &guichet_C);
    printf("A:%d, B:%d , C:%d\n", guichet_A, guichet_B, guichet_C);
    
    int tab[NB_GUICHET];
    fermetureV2(tab, NB_GUICHET);
    for(int i=0; i<NB_GUICHET; i++)
    {
        if(tab[i])
        {
            printf("le guichet: %c est ouvert.\n", 'A'+i);
        }
    }

    /* Avec la methode du prof:
     * Pas opti puisque l'on doit toujours faire à la main au final ..
     *
     *
     * long int * tab[N];
     * tab[0] = &guichet_A;
     * tab[1] = &guichet_B;
     * tab[2] = &guichet_C;
     * for(int i=0; i<N; i++)
     *    tab[i] = 0;
     * srand( time(NULL) );
     * int r = rand()%N;
     * tab[r] = 1;
    */



}


void fermeture(int *guichet_A, int *guichet_B, int *guichet_C)
{
    
    (*guichet_A) = 0;
    (*guichet_B) = 0;
    (*guichet_C) = 0;

    //Choix aléatoire ouverture
    srand(time(NULL));
    int r = rand()%3;

    switch(r)
    {
        case 0:
            (*guichet_A) = 1;
            break;

        case 1:
            (*guichet_B) = 1;
            break;
        
        case 2:
            (*guichet_C) = 1;
            break;
        
        default:
            //Je ne peux pas passer ici
            break;
    }
}

void fermetureV2(int tab[], int taille)
{
    for(int i=0; i<taille; i++)
    {
        tab[i] = 0;
    }

    //Choix aléatoire ouverture
    srand(time(NULL));
    int r = rand()%NB_GUICHET;
    tab[r] = 1;
}