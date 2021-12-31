#include <stdio.h>
#include "tableau.h"
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char r;
    char g;
    char b;
    char a; //Transparence
} couleur;




void affichageSDL(int grille[TAILLE][TAILLE], SDL_Renderer **renderer,int largeur);
int recupererCouleur(int grille[TAILLE][TAILLE], int posI, int posJ);
void changerCouleur(int grille[TAILLE][TAILLE], int couleur_apres);

int jeu[TAILLE][TAILLE];

int main()
{
    //Initialisation SDL
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        return EXIT_FAILURE; 
    }

    //Initialisation de la fenetre (interface graphique)
    SDL_Window * window;

    window = SDL_CreateWindow("SDL2 FloodIT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                900, 900, 
                SDL_WINDOW_RESIZABLE); 
        
    if (window == 0) 
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        /* on peut aussi utiliser SLD_Log() */
    }

    // Moteur graphique (meilleur rendu + rapidité calcul)
    SDL_Renderer *renderer;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); /*  SDL_RENDERER_SOFTWARE */
    if (renderer == 0) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        /* faire ce qu'il faut pour quitter proprement */
        return EXIT_FAILURE;
    }

    //Création d'une forme
    SDL_Rect rect;

    /* couleur de fond */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    
    int largeur = 70;
    int largeur_max = (largeur+1)*TAILLE;
    rect.w = rect.h = largeur;

    //Initialisation du jeu et 1er affichage
    initialiser(jeu);
    affichageSDL(jeu, &renderer, largeur);
    int nb_coup = 0;
    

    
    SDL_Event event;
    int width, height;
    int running = 1;
    int coordI, coordJ;
    while (running) {

        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                    coordI =  event.button.x/(largeur+1);
                    coordJ =  event.button.y/(largeur+1);
                    if(coordJ <largeur_max && coordI < largeur_max && nb_coup<23)
                    {   
                        nb_coup++;
                        int color = recupererCouleur(jeu, coordI, coordJ);
                        changerCouleur(jeu, color);
                        affichageSDL(jeu, &renderer, largeur);

                        if(gagne(jeu))
                        {
                            printf("Vous avez gagné.\n");
                            running = 0;
                        }

                    }else if(nb_coup>22){
                        printf("Vous avez perdu.\n");
                        affichageSDL(jeu, &renderer, largeur);
                        SDL_Delay(2000);
                        running = 0;
                    }

                    break;

                case SDL_QUIT : 
                    printf("on quitte\n");    
                    running = 0;
                    break;
            }
            SDL_Delay(10); //  delai minimal
        }	
        
    }
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


int recupererCouleur(int grille[TAILLE][TAILLE], int posI, int posJ){
    /* Verifier les coordonnées avant d'utiliser la fonction (Elles peuvent être horsde la grille car resizable)*/
    return grille[posI][posJ];
}


void changerCouleur(int grille[TAILLE][TAILLE], int couleur_apres)
{
    remplir(grille, grille[0][0], couleur_apres, 0, 0);
}

couleur N0 = {255, 255, 255, 0};//blanc
couleur N1 = {11, 144, 202, 0};//bleu
couleur N2 = {255, 215, 0, 0};//jaune
couleur N3 = {202, 11, 23, 0};//rouge 
couleur N4 = {11, 202, 46, 0};//vert
couleur N5 = {196, 11, 202, 0};//violet

void affichageSDL(int grille[TAILLE][TAILLE], SDL_Renderer **renderer, int largeur)
{
    
    /*Dessin de tous les rectangles */
    SDL_Rect rect;
    rect.w = rect.h = largeur;
    
    

    for(int i=0; i<TAILLE; i++)
    {
        for(int j=0; j<TAILLE; j++)
        {
            //Positionnement du rectangle (i,j)
            
            rect.x = i*(largeur+1);//+1 pour voir les séparations des blocs à l'écran
            rect.y = j*(largeur+1);

            //Definition de la couleur
            switch(grille[i][j]){
                case 0:
                    SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 0);//blanc
                    break;
                
                case 1:
                    SDL_SetRenderDrawColor(*renderer, 11, 144, 202, 0);//bleu
                    break;

                case 2:
                    SDL_SetRenderDrawColor(*renderer, 255, 215, 0, 0);//jaune
                    break;
                
                case 3:
                    SDL_SetRenderDrawColor(*renderer, 202, 11, 23, 0);//rouge 
                    break;
                
                case 4:
                    SDL_SetRenderDrawColor(*renderer, 11, 202, 46, 0);//vert
                    break;
                
                default://Cas couleur = 5
                    SDL_SetRenderDrawColor(*renderer, 196, 11, 202, 0);//violet
                    break;
            }
            //Màj Buffer          
            SDL_RenderFillRect(*renderer, &rect);
        }
    }

    /* afficher à l'ecran */
    SDL_RenderPresent(*renderer);
    //SDL_Delay(10);
}