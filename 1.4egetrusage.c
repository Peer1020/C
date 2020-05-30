#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(){


// ressourcen limit abrufen
struct rusage usage;


// resourcen limit abfragen
if(getrlimit(RUSAGE_SELF,&usage) ==-1){
perror("Fehler bei getrusage();");
exit(-1);
}

printf("/* user CPU time used */: %lu \n",
(unsigned long) usage.ru_utime.tv_usec);
printf("* system CPU time used */ %lu \n",
(unsigned long) usage.ru_stime.tv_usec);



}
