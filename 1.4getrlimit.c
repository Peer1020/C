#define _GNU_SOURCE
#define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main(){
          
struct rlimit old_limit,lim,new_Limit;

// get old limits

if(getrlimit(RLIMIT_NOFILE, &old_limit) == 0){
printf("Old limits --> soft limit =%ld \t" "Hard limit = %ld \t",old_limit.rlim_cur,old_limit.rlim_max);}
else {fprintf(stderr, "%s\n", strerror(errno));}


// set new limits
lim.rlim_cur=3;
lim.rlim_max=1024;


// ask for new limits

if(getrlimit(RLIMIT_NOFILE, &new_Limit) == 0){
printf("New limits --> soft limit =%ld \t" "Hard limit = %ld \t",new_Limit.rlim_cur,new_Limit.rlim_max);}
else {fprintf(stderr, "%s\n", strerror(errno));}


return 0;
}

