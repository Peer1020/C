#include <stdio.h>

double mean(double array[], int length);

main(){
double vektor[6]={1.0,2.0,3.0,4.0,5.0,6.0};
double value = mean(vektor,6);
printf("Der Wert ist %.2f",value);
return 0;
}


double mean(double array[], int length){
double result;
for(int i=0;i<length;i++){
result+=array[i];
}
return(result/length);
}
