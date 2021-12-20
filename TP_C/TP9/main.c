#include <stdio.h>
#include <math.h>//Doit être compilé avec l'option -lm
#include <string.h>
#include <stdlib.h>


const char *OPER_NAMES[] = {"x", "sin(x)", "cos(x)", "log(x)", "exp(x)", NULL};
typedef enum ope {
  NONE = -1, ID , SIN, COS, LOG, EXP
} OP;


int identification(char* fonction);
double evalf(double x, int fonction);
void calcul(double borne_inf, double borne_sup, double delta, int expression, FILE *stream);

//1.2 Pincettes
//Pointeur de fonction à prendre : double (*PFn) (double)


double evalf2(double x, double (*fn)(double));
double identite(double x);
void calcul2(double borne_inf, double borne_sup, double delta, int expression, FILE *stream);


/*Pour enlever les warning [Pas nécessaire] */
//Les fonctions retournant des floats au lieu de double, on fait un "cast" 

double sinff(double x)
{
    return (double) sinf(x);
}
double cosff(double x)
{
    return (double) cosf(x);
}
double expff(double x)
{
    return (double) expf(x);
}
double logff(double x)
{
    return (double) logf(x);
}

/**/

double (*OPER_FN[])(double) = {identite, sinff, &cosff, &logff, &expff}; //"&" non obligatoire

void calcul4(double borne_inf, double borne_sup, double delta, char *saisie, FILE *stream);
int estCorrecte(char *saisie);



int main(int argc, char **argv)
{
    printf("Bonjour misérable humain !\n");
    printf("Quelle fonction voulez-vous utiliser ?\n");
    printf("Saisir: x ; sin(x); cos(x); log(x); exp(x).\n");
    // Version scanf 
    /*
    char saisie[20];
    scanf("%s", saisie);
    */

    // Version sscanf 
    
    char saisie[20];
    fgets(saisie, 20, stdin);

    /*
    int num_fonction = identification(saisie);
    if(num_fonction != -1)
    {
        printf("Veuillez donner un intervalle [a; b]\n");
        double a,b;
        scanf("%lf", &a);
        scanf("%lf", &b);

        printf("Veuillez donner un delta.\n");
        double delta;
        scanf("%lf", &delta);
        
        //calcul(a, b, delta, num_fonction, stdout);
        calcul2(a, b, delta, num_fonction, stdout);
        

        
    }
    */
    
    //Avec pointeur de fonction

    if(estCorrecte(saisie))
    {
        printf("Veuillez donner un intervalle [a; b]\n");
        double a,b;
        scanf("%lf", &a);
        scanf("%lf", &b);

        printf("Veuillez donner un delta.\n");
        double delta;
        scanf("%lf", &delta);
        calcul4(a, b, delta, saisie, stdout);
    }

    return 0;
    
}


int identification(char* fonction)
{
    int i = 0;
    while(OPER_NAMES[i] != NULL)
    {
        if(!strcmp(OPER_NAMES[i], fonction))
            return i;
        i++;
    }
    return -1;
}


double evalf(double x, int fonction)
{
    double retour;
    switch(fonction)
    {
        case 0:
            retour = x;
            break;

        case 1:
            retour = sinf(x);
            break;
        
        case 2:
            retour = cosf(x);
            break;
        
        case 3:
            retour = logf(x);
            break;
        
        case 4:
            retour = expf(x);
            break;
        
        default:
            retour = 0;
            break;
    }

    return retour;
}


void calcul(double borne_inf, double borne_sup, double delta, int expression, FILE *stream)
{
    //Delta supposé >0

    double x = borne_inf;
    while(x <= borne_sup)
    {
        double result = evalf(x, expression);
        fprintf(stream, "%lf \n", result);
        x += delta;
    }
 
}



double evalf2(double x, double (*fn)(double) )
{
   return fn(x);
}

double identite(double x)
{
    return x;
}

void calcul2(double borne_inf, double borne_sup, double delta, int expression, FILE *stream)
{
    double x = borne_inf;
    while(x <= borne_sup)
    {
        double result = evalf2(x, OPER_FN[expression]);
        fprintf(stream, "%f \n", result);
        x += delta;
    }
 
}



//PART 2
int estOP(char c)
{
    return (c == '*' || c == '/' || c == '+' || c == '-');
}


double plus(double a, double b)
{
    return a + b;
}

double moins(double a, double b)
{
    return a - b;
}

double fois(double a, double b)
{
    return a * b;
}

double division(double a, double b)
{
    return a / b;
}

double operation(double (*op)(double, double), double arg1, double arg2)
{
    return op(arg1, arg2);
}

void separationchaine(char *string, char**retour1, char **retour2, int indiceOp)
{
    /*
     * Fonction qui permet de separer la chaine en les stockant dans retour1 et retour2 
     */

    int taille = strlen(string);
    (*retour1) = (char *)malloc(sizeof(char) * (indiceOp-1));
    (*retour2) = (char *)malloc(sizeof(char) * (taille - indiceOp));
    strncpy(*retour1, string, indiceOp-1);
    int i = indiceOp +2;
    int j = 0;
    while(i<=taille && string[i] != '\0')
    {
        (*retour2)[j] = string[i];
        i++;
        j++;
    }
    (*retour2)[j] = '\0';
}


void calcul4(double borne_inf, double borne_sup, double delta, char *saisie, FILE *stream)
{
    char gauche[20], droite[20], op;

    //Récupération des fonctions et de l'opérateur
    sscanf(saisie, "%s %c %s", gauche, &op, droite);
    //fscanf(saisie, "%s %c %s", gauche, &op, droite); //Autre possibilité

    //Identification des fonctions (indice du tableau de fonction)
    int indice_fn1 = identification(gauche);
    int indice_fn2 = identification(droite);

    double (*pGauche)(double) = OPER_FN[indice_fn1];//Pointeur de fonction
    double (*pDroite)(double) = OPER_FN[indice_fn2];//Pointeur de fonction

    //Identification de l'opérateur
    double (*TypeOperation)(double, double); //Fonction + / - *
    switch(op)
    {
        case '+':
            TypeOperation = plus;
            break;
        
        case '-':
            TypeOperation = moins;
            break;
        
        case '*':
            TypeOperation = fois;
            break;
        
        case '/':
            TypeOperation = division;
            break;

        default:
            break;
    }


    double x = borne_inf;
    while(x <= borne_sup)
    {
        double result = operation(TypeOperation, pGauche(x), pDroite(x));
        fprintf(stream, "%f \n", result);
        x += delta;
    }
}


int estCorrecte(char *saisie)
{
    //N'inclus pas tout les cas
    int compteur_expression = 0;
    int i = 0, taille = strlen(saisie);
    while(i<taille && saisie[i] != '\0')
    {
        if(saisie[i] == ' ')//Le deuxieme sera compté s'il y a un opérateur
            compteur_expression++;
        i++;
    }
    return compteur_expression == 2;
}