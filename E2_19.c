#include <stdio.h>
#include <string.h>

typedef double real;
typedef	double *pReal;

int main() {


real zahl1 = 55.5;
pReal zahl2 =&zahl1;

zahl1 = 22.2;

printf("Hier sind die Informationen %.2f\n",zahl1);
printf("Hier sind die Informationen %.2f\n",*zahl2);
return 0;
}
