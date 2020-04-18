#include <stdio.h>

extern char *HSR;
extern double inverse (double value);
extern char *text;
extern int meineZahl(int wert);


int main(){

double x=4.0;
printf("%s\n", HSR);
printf("Der Kehrwert von %.2f\n ist %.2f\n", x,inverse(x));

int y=5;
printf("%s\n", text);
printf("Der doppelte Wert von %i\n ist %i\n", y,meineZahl(y));


return 0;
}
