#include "code.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char devinette[255] = "JEDETESTELEC";


void majuscules(char * s) {
   int delta = 'A' - 'a';
   int i = 0;
   while(s[i] != '\0')
   {
      if(s[i] >= 'a' && s[i] <= 'z')
         s[i] += delta;
      i++;
   }
}

int numero_correspondant(char a, int *nb)
{

   //On a une lettre entrée
   //On veut recuperer la touche qui correspond à cette lettre
   int num; //Valeur minimale

   if(a >= 'A' && a <= 'C')
   {
      num = 2;
      (*nb) = a - 'A';
   }else if( a >= 'D' && a <= 'F')
   {
      num = 3;
      (*nb) = a - 'D';
   }else if( a >= 'G' && a <= 'I')
   {
      num = 4;
      (*nb) = a - 'G';
   }else if( a >= 'J' && a <= 'L')
   {
      num = 5;
      (*nb) = a - 'J';
   }else if( a >= 'M' && a <= 'O')
   {
      num = 6;
      (*nb) = a - 'M';
   }else if( a >= 'P' && a <= 'S')
   {
      num = 7;
      (*nb) = a - 'P';
   }else if( a >= 'T' && a <= 'V')
   {
      num = 8;
      (*nb) = a - 'T';
   }else{
      num = 9;
      (*nb) = a - 'W';
   }
   
   (*nb)++;

   return num;
}


void multitap1(char * s, char * d) {

   majuscules(d);
   //Prends une chaine d et donne le code multitap dans la sortie s

   int i = 0;
   int j = 0;

   while(d[i] != '\0')
   {

      int nb; //Nb d'appuie sur la touche nécessaire
      int num = numero_correspondant(d[i], &nb);

      char chiffre = num + '0';

      while(nb--)
      {
         s[j] = chiffre;
         j++;
      }

      i++;
      if(d[i] != '\0')
      {
         s[j] = ' ';
         j++;
      }

   }
   s[j] = '\0';
}


void multitap2(char * s) {

   majuscules(s);
   //Prends une chaine d et donne le code multitap dans la sortie s

   int i = 0;
   int j = 0;
   char tab[50];

   while(s[i] != '\0')
   {

      int nb; //Nb d'appuie sur la touche nécessaire
      int num = numero_correspondant(s[i], &nb);

      if(nb>1)
      {
         tab[j] = '0' + nb;
         tab[j+1] = '*';
         tab[j+2] = '0' + num;
         j+= 3;

      }else{
         tab[j] = '0' + num;
         j++;

      }

      //On avance dans nos deux tableaux
      i++;


   }
   tab[j] = '\0';
   strcpy(s, tab);
}


char lettre_correspondante(char num)
{
   char lettre;
   switch(num)
   {
      case '2':
         lettre = 'A';
         break;

      case '3':
         lettre = 'D';
         break;

      case '4':
         lettre = 'G';
         break;

      case '5':
         lettre = 'J';
         break;
      case '6':
         lettre = 'M';
         break;

      case '7':
         lettre = 'P';
         break;

      case '8':
         lettre = 'T';
         break;
      default:
         lettre = 'W';
         break;
   }

   return lettre;
}


void antitap1(char *s, char * d) {

   int i = 0;
   int j = 0;
   while(d[i] != '\0')
   {
      s[j] = lettre_correspondante(d[i]);
      i++;
      while(d[i] != '\0' && d[i] != ' ')
      {
         s[j] ++;
         i++;
      }
      j++;

      if(d[i] != '\0')
         i++;

   }
   s[j] = '\0';
}

void antitap2(char * s) {

   //Recuperer un char
   //Regarder le prochain, si c'est une étoile recuperer celui d'encore après et augmenter la valeur de notre char de cette valeur -1
   
   int i = 0;
   char sauv[50];
   int j = 0;
   while(s[i] !=  '\0')
   {
      char lettre = lettre_correspondante(s[i]);
      if(s[i+1] == '*')
      {
         //Lettre correspond en fait a un nombre d'appuie sur une touche
         int decalage = s[i] - '0' - 1;
         lettre = lettre_correspondante(s[i+2]);
         lettre += decalage;
         i += 2;
      }
      
      sauv[j] = lettre;
      i++;
      j++;

   }
   sauv[j] = '\0';
   strcpy(s, sauv);

}

char * sms(char * filename) {
   FILE *f = fopen(filename, "w");

   char *codage; 

   if(f)
   {  
      codage = (char *)malloc(sizeof(char) * 1024);
      codage[0] = '\0';
      //On recuperer mot à mot et on transforme le tout
      char tmp[50];
      while(!feof(f))
      {
         //Je recupere un mot => vive fscanf
         fscanf(f, "%s", tmp);

         //On le code à l'aide d'une des deux méthode
         //avec la methode multitap1

         char temp2[50];
         multitap1(temp2, tmp);
         printf("%s\n", temp2);
         strcat(codage, temp2);

      }
   }

   if( (codage != NULL) && (codage[0] == '\0'))
   {
      //Si le pointeur n'est pas null et que le fichier était vide, on libere la mémoire et on retourne le pointeur null
      free(codage);
   }


   return codage;
}


