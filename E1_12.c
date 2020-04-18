#include <stdio.h>
int main(){
int a=4; int b=3; int c=2; int d=0;
d=a || b&&c;
printf("d =%i\n",d);
d=a<=b;
printf("d =%i\n",d);
d=a--*b;
printf("d =%i\n",d);
d=a/b%1;
printf("d =%i\n",d);
return 0;
}

