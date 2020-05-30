#include <stdio.h>
#define square(x) (x)*(x)


int main() {
double y = 3.0;
printf("Das Quadrat von %.2f ist %.2f\n", y, square(y));
printf("Das Quadrat von %.2f ist %.2f\n", y+1, square(y+1));
return 0;
}
