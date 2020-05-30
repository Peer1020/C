#include <stdio.h>
#include <ctype.h>

int main(){
char text[] = "Ein kleiner Beispieltext";

char * pc = text;
printf("%s\n",text);

while ((*pc)) {
if (islower(*pc)){ // liefert !=0, wenn c ein Kleinbuchstabe ist
*pc=toupper(*pc); // liefert das ASCII-Zeichen für den Grossbuchstaben von c
}
pc++;
}
printf("%s\n",text);
return 0;
}
