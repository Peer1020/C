#include <stdio.h>
#include <math.h>

#define BUF_SIZE 100 

int main(){

double Winkel[BUF_SIZE];
double Sinuswert[BUF_SIZE];

for(int i=0;i<BUF_SIZE; i++){
	Winkel[i]= i * (M_PI/(BUF_SIZE-1));
	Sinuswert[i]=sin(Winkel[i]);
}

for (int i=0;i<BUF_SIZE;i++){
	printf("Der Sinus von %.3f ist %.3f\n",Winkel[i],Sinuswert[i]);	
	}

return 0;
}
