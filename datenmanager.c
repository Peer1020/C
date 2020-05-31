#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

void createfolder(char *filename){

struct stat st = {0};

if(stat(filename, &st) == -1){
	mkdir(filename,0777);
	printf("Directory created \n"); 
    } else {
	printf("Error, no directory created \n");
	}
}


void movefolder(char *path){

char oldname[]= "/home/peer/Desktop/C/newfolder";
int ret = rename(oldname, path);
}


void createdata(char *path, int value){

int ret;
ret= chdir(path);
int i =0;
char fname[value];

// definiere pointer für File
FILE * filePointer= NULL;
//definiere file und erstelle n files und schreibe text rein
	for(i;i<value;i++){
		sprintf(fname,"file-%d.txt",i);
		filePointer =fopen(fname,"w");
		fputs("This is a text",filePointer);
	//prüfe file
		if(filePointer==NULL){
			printf("Error in Creating a file \n");
			exit(EXIT_FAILURE);
			}
	fclose(filePointer);
	}
}

void movedata(char *path){

char b[] = "/home/peer/Desktop/deletefolder";
sleep(2);
int ret = rename(path,b);
if(ret==0){
	printf("Files succesfully moved \n");
	}	
	else{
		perror("Error \n");
	}
remove(path);
}

void deletedata(char *dpath){
int i=0;
char str1[10];
printf("Delete directory? \n");
fgets(str1,3,stdin);
char aName[]="yes";
if(strcmp(str1,aName)){
	system("rm file-*.txt");
	rmdir(dpath);}
	else {
		perror("Error in comparison \n");
	}
}




int main(){

char newfolder[]="newfolder";
char deletefolder[]="deletefolder";
char path[]="/home/peer/Desktop/newfolder";
int value = 100;
char deletepath[]="/home/peer/Desktop/deletefolder";
pid_t pid = fork();


createfolder(newfolder);
createfolder(deletefolder);
movefolder(path);

printf("Dateien verdoppeln?");
char str[10];
char aName[]="yes";
fgets(str,3,stdin);
if(strcmp(str,aName)){
	// fork um Dateien doppelt zu erstellen
	fork();
	value=200;
	createdata(path,value);
	printf("Fork ID ist %d \n",getpid());
	exit(0);
	}
	else {
	createdata(path,value);
}

sleep(2);
movedata(path);
deletedata(deletepath);

return(0);
}
