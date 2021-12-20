#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> //Doit être compilé avec l'option -lm




const char * OPER_NAMES[] = { "x", "sin(x)", "cos(x)", "log(x)", "exp(x)", NULL };

enum fonction{
	None = -1, ID, SIN, COS, LOG, EXP, FIN
};


int identification(char *chaine);
double evalf(double x, int indice_fonction);
void calcul(double a, double b, double delta, int id_fn, FILE *stream);

int main()
{

	double x = 3.45;
	enum fonction f = SIN;

	double resulat = evalf(x, f);
	printf("%lf\n", resulat);	

	f = COS;
	resulat = evalf(x, f);
	printf("%lf\n", resulat);	

	f = ID;
	resulat = evalf(x, f);
	printf("%lf\n", resulat);	

	f = LOG;	
	resulat = evalf(x, f);
	printf("%lf\n", resulat);	

	f = EXP;	
	resulat = evalf(x, f);
	printf("%lf\n", resulat);


	printf("Utilisation de calcul:\n");

	calcul(2, 34, 12, 1, stdout);	

	return 0;
}



int identification(char *chaine)
{
	enum fonction i = ID;

	while(i<FIN)
	{
		if(strcmp(chaine, OPER_NAMES[i]) == 0)
		{
			return i;
		}
		i++;
	}

	return i;
}



double evalf(double x, int indice_fonction)
{
	double retour;

	switch(indice_fonction)
	{
		case ID:
			retour = x;
			break;

		case SIN:
			retour = (double)sinf(x);//Les fonctions retournent normalement un float. le "(double)" permet de convertir les types
			break;

		case COS:
			retour = (double)cosf(x);
			break;

		case LOG:
			retour = (double)logf(x);
			break;

		case EXP:
			retour = (double)expf(x);
			break;

		default:
			retour = 0;
			break;

	}

	return retour;
}


void calcul(double a, double b, double delta, int id_fn, FILE *stream)
{ 
	/*
	reçoit en entrée un intervalle [a, b], 
	un pas de progression delta dans cet intervalle,
	un identificateur d'expression (indice ou énumération) 
	et un fichier dans lequel écrire.
	Cette fonction évalue l'expression "identifiée" pour toutes les valeurs entre a et b
	par pas de delta et écrit dans le fichier précisé (par exemple, la sortie standard)
	chaque résultat d'évaluation.
	*/

	double x = a;

	while(x<b)
	{
		printf("%lf\n", evalf(x, id_fn));
		x += delta;
	}

}