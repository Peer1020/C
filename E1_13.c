#include <stdio.h>
int main(){
int zeilen =4;
for(int i=1; i <=zeilen; i++){
for(int u=1; u<=zeilen-i; u++){
	putchar(' ');
	}
	int anzahlsterne = 7 -2*(zeilen-i);
	for(int v=0; v<anzahlsterne; v++){
		putchar('*');
		}
	for(int w=1; w<=zeilen-i;w++){
		putchar(' ');
		}
putchar('\n');
}
return 0;
}
