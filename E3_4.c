#include <stdio.h>

void increment(int * x) { *x = *x + 1; }
int main() {
int a=23;
increment(&a);
printf("Die Zahl lautet: %d\n", a);
}
