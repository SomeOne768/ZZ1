#include "mon_code.h"

int pgcd(int a, int b) {
	if(b>a){
      a = a + b;
      b = a - b;
      a = a - b;
   }
   int r = a%b;
   if(r == 0)
      return b;

   return pgcd(b, r);
}

void majuscules(char s[]) {
   int i = 0;

   while(s[i] != '\0' && i<255)
   {
      if(s[i] >= 'a' && s[i] <= 'z')
         s[i] -= 32;
      
      i++;
   }
}
