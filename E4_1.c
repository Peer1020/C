#include <stdio.h>

int main(){

printBin(4711);
printBin(-1);

return 0;
}


printBin(int value){

int result;
int anzBits = sizeof(value)*8;
unsigned int maske = 1 << (sizeof(value)*8)-1;


for (int i=0; i<anzBits;i++)
	{
	result=value &maske;
	if(result==0) 
		{printf("%c",'0');}
	else {printf("%c",'1');}
	maske =maske>>1;}
printf("\n");}
