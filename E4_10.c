#include <stdio.h>

int funkultaet(int x);


int main (){

int x=4;
int result=funkultaet(x);
printf("Das Ergebnis ist %i\n",result);
return 0;
}

int funkultaet(int x){
if(x==1) return 1;
return x * funkultaet(x-1);

}
