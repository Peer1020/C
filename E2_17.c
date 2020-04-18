#include <stdio.h>
#include <string.h>

typedef struct {
	double zahl1;
	double zahl2;
} t_complex;

typedef union{
	double value[2];
	t_complex;
} myunion;

int main(){


myunion a;
myunion b;
a.value[0]=2.0;
a.value[1]=3.0;
printf("Der Realteil ist %2f, der Imaginärteil ist %2f\n",a.value[0],a.value[1]);


return 0;
}
