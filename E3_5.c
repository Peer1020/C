#include <stdio.h>

void myfunction(){
static int counter=1;
printf("Diese Funktion wurde %d aufgerufen\n",counter);
counter++;
}

int main() {

int i=0;
for (i; i<5; i++){
myfunction();
}
return 0;
}
