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


void movefolder(char *path, char *oldname){
int ret = rename(oldname, path);
}


void createdata(char *path, int value){

int ret;
ret= chdir(path);
int i =0;
char fname[value];

// define pointer for file
FILE * filePointer= NULL;
//define file, create and write text
	for(i;i<value;i++){
		sprintf(fname,"file-%d.txt",i);
		filePointer =fopen(fname,"w");
		fputs("This is a text",filePointer);
	//check file
		if(filePointer==NULL){
			printf("Error in Creating a file \n");
			exit(EXIT_FAILURE);
			}
	fclose(filePointer);
	}
}

void movedata(char *path){

char b[] = "/home/peer/Desktop/deletefolder";
int ret = rename(path,b);
if(ret==0){
	printf("Files succesfully moved \n");
	}	
	else{
		perror("Error in moving data \n");
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
char oldnameNew[]= "/home/peer/Desktop/C/newfolder";
char oldnameDelete[]= "/home/peer/Desktop/C/deletefolder";
char path[]="/home/peer/Desktop/newfolder";
int value = 2;
int status=0;
pid_t wpid;
char deletepath[]="/home/peer/Desktop/deletefolder";

createfolder(newfolder);
createfolder(deletefolder);
movefolder(path,oldnameNew);
movefolder(deletepath,oldnameDelete);

printf("Double files?");
char str[10];
char aName[]="yes";
fgets(str,3,stdin);
if(strcmp(str,aName)){
	// fork to double the files
		fork();
		int value1=value*2;
		createdata(path,value1);
		printf("Child process is %d  parent process ist %d \n",getpid(),getppid());
		}
		else {
		createdata(path,value);
		exit(0);
}

while ((wpid=wait(&status))>0)
{
printf("Exit status of %d was %d (%s) \n", (int)wpid, status,(status>0) ? "accept" : "reject");
}

movedata(path);
sleep(1);
deletedata(deletepath);

return(0);
}
