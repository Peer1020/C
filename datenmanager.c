#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>

void *createfolder(void *filename){

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

int status=0;
pid_t wpid;
char str[10];
char aName[]="yes";
fgets(str,3,stdin);
int ret;
ret= chdir(path);
int i =0;
char fname[value];
int duplicate =2;
// define pointer for file
FILE * filePointer= NULL;

printf("Duplicate files?");
fgets(str,3,stdin);
if(strcmp(str,aName))
{
	// fork to double the files
	
	if(fork()==0){
	printf("Child process is %d  parent process ist %d \n",getpid(),getppid());
	int value2 = value*duplicate;
	}
	else if(fork()>0){
	wait(NULL);
	printf("No duplication");
	printf("Exit status of %d was %d (%s) \n", (int)wpid, status,(status>0) ? "accept" : "reject");
	}
}

//define file, create and write text
for(i;i<value;i++)
{
	sprintf(fname,"file-%d.txt",i);
	filePointer =fopen(fname,"w");
	fputs("This is a text",filePointer);
		//check file
		if(filePointer==NULL)
		{
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
int value = 1000;
char deletepath[]="/home/peer/Desktop/deletefolder";
pthread_t thread_id;

//createfolder as threads
pthread_create(&thread_id,NULL,createfolder,newfolder);
pthread_join(thread_id,NULL);
pthread_create(&thread_id,NULL,createfolder,deletefolder);
pthread_join(thread_id,NULL);
printf("Thread ID is %lu \n", (unsigned long) thread_id);

movefolder(path,oldnameNew);
movefolder(deletepath,oldnameDelete);
createdata(path,value);
movedata(path);
sleep(5);
deletedata(deletepath);

return(0);
}
