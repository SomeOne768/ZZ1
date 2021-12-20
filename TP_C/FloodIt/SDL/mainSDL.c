#include <stdio.h>
//#include "tableau.h"
#include <SDL2/SDL.h>

int main()
{
    //Initialisation SDL
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        return EXIT_FAILURE; 
    }

    //Initialisation de la fenetre (interface graphique)
    SDL_Window   * window;

    window = SDL_CreateWindow("SDL2 FloodIT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                1200, 1200, 
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

    /* dessiner en blanc */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    rect.x = rect.y = 0;
    rect.w = rect.h = 600;
    SDL_RenderFillRect(renderer, &rect );

    /* afficher à l'ecran */
    SDL_RenderPresent(renderer);

/*

    while (running) {

        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_WINDOWEVENT:
                    printf("window event\n");
                    switch (event.window.event)  
                    {
                        case SDL_WINDOWEVENT_CLOSE:  
                            printf("appui sur la croix\n");	
                            break;
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            width = event.window.data1;
                            height = event.window.data2;
                            printf("Size : %d%d\n", width, height);
                        default:
                            afficherEcran();
                    }   
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    printf("Appui :%d %d\n", event.button.x, event.button.y);
                    // afficherEcran() ?
                    break;
                case SDL_QUIT : 
                    printf("on quitte\n");    
                    running = 0;
            }
        }	
        SDL_Delay(1); //  delai minimal
    }
*/











    SDL_Delay(5000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
