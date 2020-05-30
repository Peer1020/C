#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(){

int e =close(99);


// resourcen limit abfragen
if(e ==-1){
perror("Fehler Zahl unter o");
return 1;
} else{printf("Kein Fehler \n");
}


return 0;

}
