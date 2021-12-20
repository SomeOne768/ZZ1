#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdarg.h>
#include <string.h>

void fonction1(int nombre, ...);
void fonction2(char* dirName, ...);


//Partie 2
struct binaryFile{
	char nom[100];
	char langage[50];
	int annee;
};


typedef struct binaryFile binaryFile;

binaryFile TAB[] = {
		 		{"Backus Jo,hn","FORTRAN", 1957},
				{"Goldfarb Charles",	"GML", 1969},
				{"Wirth Niklaus", "Pascal",	1970},
				{"Ritchie Dennis", "C",	1972},
				{"Kernighan Brian", "C",	1972},
				{"Sussman Gerald Jay", "Scheme",	1975},
				{"Steele Guy L",	"Scheme",	1975},
				{"Naughton Patrick",	"Java", 1983},
				{"Cox Brad",	"Objective C", 1983},
				{"", "", 0}
				};





int main()
{
	/*
	struct dirent * lecture;
	DIR *rep;
	rep = opendir("." );//Ouvrir le repertoire courant
	while ((lecture = readdir(rep))) {
		//recuperer un fichier du repertoire
	    printf("%s\n", lecture->d_name);//Afficher le nom d'un fichier du répertoire
	}
	closedir(rep);//Libération mémoire
	*/

	fonction1(3, "rep1", "rep2", "rep3");//Les noms et chemins doivent être valide
	fonction2("rep1", "rep2", "rep3", NULL);//Ne pas oublier de mettre NULL à la fin

	//Partie 2
	printf("\n\n\n\n");
	FILE *f = fopen("fichier_binaire", "wb");
	if(f)
	{
		int i = 0;
		while(TAB[i].annee != 0)
		{
			binaryFile b = TAB[i];
			fwrite(b.nom, sizeof(char), 100, f);
			fwrite(b.langage, sizeof(char), 50, f);
			fwrite(&b.annee, sizeof(int), 1, f);
			i++;
		}
	}
	fclose(f);

	f = fopen("fichier_binaire", "rb");
	if(f)
	{
		int i = 0;
		while(TAB[i].annee != 0)
		{
			//Nécessaire d'avoir une taille constante
			char lecture_nom[100], lecture_
			binaryFile b = TAB[i];
			fread(b.nom, sizeof(char), 100, f);
			fread(b.langage, sizeof(char), 50, f);
			fread(&b.annee, sizeof(int), 1, f);
			i++;
		}
	}
	fclose(f);



}

void AfficherRepertoire(DIR *rep)
{
	struct dirent * lecture;
	while( (lecture = readdir(rep)) )
	{
		printf("%s\n", lecture->d_name);
	}
	printf("\n");
}

//Fonction avec un nombre determiner d'arguments
void fonction1(int nombre, ...)
{
	//Fonction qui affiche les repartoires passés en parametre

	DIR *rep;
	va_list L;
	va_start(L, nombre);
	while(nombre--)
	{
		//Tant que nombre != O (correspond au noombre de parametre de la fonction)
		char *dirName = va_arg(L, char*);//Recuperation d'un repertoire
		rep = opendir(dirName);
		if(rep != NULL)
		{
			AfficherRepertoire(rep);
			closedir(rep);
		}
	}

	va_end(L);
}


//fonction2("tp1", "tp2", NULL);
void fonction2(char* dirName, ...)
{
	DIR *rep;

	va_list L;
	va_start(L, dirName);

	char *parcourir = va_arg(L, char*);
	while(parcourir != NULL)
	{
		rep = opendir(parcourir);

		AfficherRepertoire(rep);
		closedir(rep);
		parcourir = va_arg(L, char*);
	}

}



