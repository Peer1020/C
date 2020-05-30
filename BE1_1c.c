
// Vorlagedatei str_cat.c zu Aufgabe E1.3
// NB: dieser Code kann nicht fehölerfrei compiliert werden, da noch CVodelemenet fehlen.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
   int  size;
   char * buf;
};


int stringcat(char * s1, char * s2, struct string *s) {
int size1 =strlen(s1);
int size2 =strlen(s2);
if(size1+1 > s->size   | size2+1 > s->size){
return 1;
}else{
for (int i=0;i<size1;i++){
s->buf[i]=s1[i];
}
for(int i=0;i<size2;i++){
s->buf[i]=s2[i];
}
s->buf[size1+size2]=0;
return 0;  
}
}


int main()
{
   struct string s;
   s.size = 100;        // Grösse string buffer
   s.buf = malloc(100); // string buffer
   if (stringcat("Hallo ", "Welt!",    &s      ) == 0) {
      printf(s.buf);
      printf("\n");
   } else {
      printf("Fehler: string buffer overrun.\n");
   }
   return 0;
}

