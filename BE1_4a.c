#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

      

#define errExit(msg) do { perror(msg); exit(EXIT_FAILURE); \
                               } while (0)

void print(int resource)
       {
	struct rlimit rl;	
        getrlimit(resource, &rl);

	printf("Harter Grenzwert ist:\n");
	if (rl.rlim_max == RLIM_INFINITY) 
		{printf("undendlich\n");
		}else{
		printf("%lu\n",(unsigned long)rl.rlim_max);
		}

         printf("Weicher Grenzwert ist:\n");
	if (rl.rlim_cur == RLIM_SAVED_MAX)
		{printf("gleich wie hartes Limit\n");
		}else if(rl.rlim_cur == RLIM_SAVED_CUR)
		{printf("nicht darstellbare Grösse\n");	
		}else{
		printf("%lu\n",(unsigned long)rl.rlim_cur);
		}
}


int main(){
printf("Heap Groesse\n");
print(RLIMIT_DATA);
printf("Datei Groesse\n");
print(RLIMIT_FSIZE);
printf("Stack Groesse\n");
print(RLIMIT_STACK);

}
