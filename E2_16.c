#include <stdio.h>
#include <string.h>

int main(){
char * textA = "Peer";
char * textB = "Eisele";
char buffer[40];

printf("Text A: %s\nText B: %s\n", textA, textB);
buffer[0]='\0';
//haenge Zeichenkette textB an textA an
strcat(buffer, textA);
strcat(buffer, textB);

printf("Text : %s\n", buffer);
return 0;
}
