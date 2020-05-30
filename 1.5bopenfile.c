#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <fcntl.h>

int main(int argc,char * argv[]){

int fd=open(argv[1], O_RDONLY);

if (fd == -1){
printf("Datei kann nicht geöffnet werden\n");
return 1;}
else {printf("Datei gefunden und für lesen geöffnet \n");
close(fd);}

return 0;

}
