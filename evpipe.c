/*  Evpipe2.C                                                   */
/*                                                              */
/*  Beispiel fuer Pipe-Gebrauch                                 */
/*  Besteht aus den Dateien:                                    */
/*  - evpipe2.c: erzeugt Pipe und Prozesse erzeuger/verbraucher  */
/*  - erzeuger2.c: datenproduzierender Prozess                   */
/*  - verbraucher2.c: datenkonsumierender Prozess                */
/*                                                              */
/*  *** LOESUNGSBEISPIEL FUER NAMED PIPES ***                   */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


int main (int argc, char* argv[])
{
   int status;

   if (mkfifo ("./pipe_ev", 0700) == 0) 
      printf("named pipe created successfully.\n");
   else {
      printf ("mkfifo failed\n");
      exit (-1);
   }

   if (fork() == 0)
   {
      printf("Kind 1 bei execlp.\n");
      execlp("./erzeuger2", "erzeuger", NULL);
   }
   else if (fork() == 0)
   {
      printf("Kind 2 bei execlp.\n");
      execlp("./verbraucher2", "verbraucher", NULL);
   }
   else
   {
      wait(&status);
      wait(&status);
      exit(0);
   }
}
