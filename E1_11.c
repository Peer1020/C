#include <stdio.h>
int main(){
{
int x=10;int y=5;
int u= y + x--;
int v= y + ++x;
printf(" u = %i,v= %t \n");
}
{
int x=10;int y=5;
int u= y + x;
int v= --u;
printf(" u = %i,v= %t \n");
}
return 0;
}
