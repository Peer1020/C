#include <stdio.h>
#include <string.h>

int main (){

int a,b,c;

a=10; 
b = 7;
c=++a;
printf("c=++a [Ergebnis = c=%d\n]",c);

a=10; 
b = 7;
c=b-- *a;
printf("c=b-- *a; [Ergebnis = c=%d\n]",c);

a=10; 
b = 7;
c=--b *a;
printf("c=--b *a; [Ergebnis = c=%d\n]",c);

a=10; 
b = 7;
c=a % b *a;
printf("c=a % b *a; [Ergebnis = c=%d\n]",c);

a=10; 
b = 7;
c=a % (b *a);
printf("c=a % b *a; [Ergebnis = c=%d\n]",c);


}


