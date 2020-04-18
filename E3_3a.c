#include <stdio.h>
#include <stdlib.h>

double mul(double x, double y) { return x*y; }
void printText(char * text) { printf("%s\n", text); }


int main(){

double x = 2.0;
double y = 3.0;
double z;
double(*ptr) (double, double);
ptr=mul;
z=(*ptr)(x,y);
printf("Das Resultat von mul() ist %.2f\n",z);


char text[]="Peer";
void(*pointer)(char*);
pointer=printText;
(pointer)(text);


return 0;
}

