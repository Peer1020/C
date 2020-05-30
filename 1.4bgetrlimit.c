#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>

void printlimits(int ressource){

//parameter definieren
struct rlimit rl;

// ressourcen limit abrufen
getrlimit(ressource,&rl);

// aufrufen harter und weicher Grenzwert
printf("Harter Grenzwert:");
if(rl.rlim_max == RLIM_INFINITY){
printf("unendlich\n");}
else{printf("%lu\n",(unsigned long) rl.rlim_max);}

printf("Weicher Grenzwert:");
if(rl.rlim_cur == RLIM_SAVED_MAX){
printf("unendlich\n");}
else if(rl.rlim_cur == RLIM_SAVED_CUR){
printf("nicht darstellbare Grösse\n");}
else{printf("%lu\n",(unsigned long) rl.rlim_cur);}


}




int main(){

printf("Heap:\n");
printlimits(RLIMIT_DATA);
printf("Stack:\n");
printlimits(RLIMIT_STACK);
printf("RLIMIT_FSIZE:\n");
printlimits(RLIMIT_FSIZE);
exit(0);

}
