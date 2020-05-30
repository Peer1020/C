/* Nach: An Introductory 4.3BSD IPC Tutorial, S. Sechrest */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
  pid_t k, pid;
  int status;

  k=fork();
  if (k == 0) {
    printf("(C) Child executing \"/bin/date\"\n");
    printf("(C) Child PID = %d\n", getpid());
    execl("/bin/date", "date", NULL);
    printf("(C) This should not happen!\n");
    exit(-1);
    //exit(-1);
  }
  else if (k < 0) {
    exit(-1);
  }
  else {
    printf("(P) Parent waiting for child's death...\n");
    printf("(P) Parent PID = %d\n", getpid());
    pid = wait(&status);
    printf("(P) Child status written by wait function: %i\n", status);
    printf("(P) WIFEXITED(status): %i\n", WIFEXITED(status)); // WIFEXITED(status) returns true if child terminated normally
    printf("(P) WEXITSTATUS(status): %i\n", WEXITSTATUS(status)); // WEXISTATUS(status) returns the exit status of the child
    printf("(P) Process ID of the terminated child: %i\n", pid);

    if (WEXITSTATUS(status) == -1) {
      printf("(P) Error while executing child.");
      exit(-1);
    }
    else {
      printf("(P) Child succesfully executed.\n");
      exit(0);
    }
  }
}
