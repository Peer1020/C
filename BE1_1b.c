#include <stdio.h>
#include <stdlib.h>


int main(){
char *env;

putenv("EU=Europa");

env=getenv("Europa");
if(env==0)
printf("Umgebungsvariable nicht gefunden");
else
printf("%s\n",env);
exit (0);
}
