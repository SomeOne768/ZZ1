#include <stdio.h>
#include <stdlib.h>

#define N 1
#define HORIZ 0
#define VERT 1

int verif[N][N]; //Grille donné dans l'exercice


int initialiser(int grille[N][N]);
void afficher(int grille[N][N]);

void saisir(int grille[N][N], int *remplissage);


int verifierLigneColonne(int grille[N][N], int num, int sens);
void grille_test(int tab[N][N]);
int verifierRegion(int grille[N][N], int k, int l);
int verifGrille(int grille[N][N]);
int generer(int grille[N][N]);





int main()
{

    printf("SUDOKU\nLancement du jeu...\n");
    

    int grille[N][N];
    int remplissage = 0, jouer = 1;

    initialiser(grille);
    afficher(grille);

    while(jouer)
    {

        saisir(grille, &remplissage);
        afficher(grille);
        if(remplissage == (N * N))
        {
            if(verifGrille(grille))
            {
                printf("Félicitation, vous avez réussi.\n");
                jouer = 0;
            }else{
                printf("T'es nul, casse-toi de ce jeu !\n");
                break;
            }
        }
        //On peut rajouter une condition pour sortir du jeu quand l'utilisateur en a marre
        /*
        printf("Voulez-vous continuer de jouer ? 99 pour quitter\n");
        int continuer;
        scanf("%d", &continuer);
        if(continuer == 99)
        {
            jouer = 0;
        }
        */
    }

    printf("Sortie du jeu..\n");
   
    return 0;

}

void grille_test(int tab[N][N])
{
    int i, j;

    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        tab[j][i] = (i + j*3 +j /3) %9 +1 ; 
    }
}

int initialiser(int grille[N][N])
{
    int i,j;
    for(i=0; i<N; i++)
    {
        //Parcours des lignes
        for(j=0; j<N; j++)
        {
            //Parcours des colonnes de la ligne i
            grille[i][j] = 0;
        }
    }

    return 0;
}


void afficher(int grille[N][N])
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf(" %.1d|", grille[i][j]);
        }
        printf("\n");
    }
}

int generer(int grille[N][N])
{
    //Fonction du prof permettant d'initialiser notre grille avec une grille valide
    //Servira pour les tests

    int i, j;

    for(j=1;j<9; ++j) 
    {
        //On enleve volontairement la 1ere ligne pour que la grille ne soit pas complete
        for(i=0; i<9; ++i)
        {
            grille[j][i] = (i + j*3 +j /3) %9 +1 ; 
        }
    }

    //On compte egalement le nombre de cases non vide pour le reste du programme
    //int compteur = 9 (il n'y a que la 1ere ligne)
    int compteur = 0;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(grille[i][j] != 0)
                compteur++;
        }
    }

    return compteur;
}

void saisir(int grille[N][N], int *remplissage)
{
    printf("Récupération des indices ainsi que de la valeur à placer\n");

    int i,j,v; 
    // i,j indice du tableau et v valeur à insérer

    printf("Veuillez saisir un numéro de ligne\n");
    scanf("%d", &i);

    if(i<1 || i>N){
        printf("Mauvaise valeur\n");
    }else{
        printf("Veuillez saisir un numéro de colonne\n");
        scanf("%d", &j);

        if(j<1 || j>N){
            printf("Mauvaise valeur\n");
        }else{
            printf("Valeur à insérer ?\n");
            scanf("%d", &v);

            if(v<1 || v>N){
                printf("Mauvaise valeur\n");
            }else{
                //Normalement valeur doit etre inseree seulement si la case est vide => = 0
                //Ici on laisse la modification possible
                if(grille[i-1][j-1] == 0)
                {
                    //Remplissage augmente seulement si aucune valeur etait presente dans la case
                    (*remplissage)++;
                }
                grille[i-1][j-1] = v;
            }
        }
    }
}


int verifierLigneColonne(int grille[N][N], int num, int sens)
{
    //On utilise un tableau qui nous permet de savoir combien de fois on a croisé une valeur.
    //Si il existe un i t.q: verif[i] != 1 à la fin => la valeur a été croisé 0 ou plusieurs fois => Ligne/colonne invalide  
    int verif[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    if(num<1 || num>9)
    {
        printf("Mauvaise numéro de ligne/colonne. \n");
        return 0;
    }
    
    if(sens == HORIZ)
    {
        //On souhaite vérifier une ligne
        for(int j=0; j<N; j++)
        {

            if(grille[num][j] == 0)
            {
                //S'il y a un 0 la ligne ne peut pas être juste (pas de valeur insérer)
                printf("case (%d, %d) incorrect.\n", num, j);
                return 0;
            }

            //Si on passe ici les cases sont forcément remplies avec un entier >0 et <10
            //On compte donc le nb de fois que l'on a croise une valeur
            //nb d'apparence de v corespond à verif[v-1]
            verif[ grille[num][j] ]++;//grille[num][j] = v est une valeur [|1; 9|]
        }

    }else if(sens == VERT){

        //On effectue la même chose mais sur une colonne
        for(int i=0; i<N; i++)
        {
            if(grille[i][num] == 0)
            {
                printf("case (%d, %d) incorrect.\n", i, num);
                return 0;
            }

            verif[ grille[i][num] ]++;
        }
    }

    //On peut reverifie que tout est apparu 1 seule et unique fois mais pas necessaire
    for(int i =0; i<N; i++)
    {
        if(verif[i] != 1)
        {
            //On a une valeur qui est apparu 0 fois (ou plusieurs fois => une autre est apparue 0 fois)
            printf("valeur %d saisie %d fois.\n", i+1, verif[i]);
            printf("La grille est donc incorrect.\n");
            return 0;
        }
    }

    //Si l'on arrive là alors tout s'est bien déroulé, la ligne ou la colonne est donc juste
    return 1;    
}

int verifierRegion(int grille[N][N], int k, int l)
{
    //Retourne 1 si région correct 0 sinon
    //Région défini par (k,l) => vérifie ligne k et colonne l

    return verifierLigneColonne(grille, k, HORIZ) && verifierLigneColonne(grille, l, VERT);

}

int verifGrille(int grille[N][N])
{
    int i;
    for(i=0; i<N; i++)
    {
        //On a besoin de verifier que la diagonale
        if(!verifierRegion(grille, i, i))
        {
            printf("Grille incorrect.\n");
            return 0;
        }
    }

    return 1;
}