#include <stdio.h>

extern char *HSR;
extern double inverse (double value);


int main(){

double x=4.0;
printf("%s\n", HSR);
printf("Der Kehrwert von %.2f\n ist %.2f\n", x,inverse(x));
return 0;
}
