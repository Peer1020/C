#include <stdio.h>


double mwstsatz=0.08;

calcMwst(double value){
return value*mwstsatz;
}

int main()
{
double wert = 40.00;
double mwst = calcMwst(wert);
printf("Die Mehrwertsteuer von %f ist %f\n", wert, mwst);
return 0;
}
