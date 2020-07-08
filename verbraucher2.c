/*  Verbraucher2.C                                              */
/*                                                              */
/*  Beispiel fuer Pipe-Gebrauch                                 */
/*  Besteht aus den Dateien:                                    */
/*  - evpipe.c: erzeugt Pipe und Prozesse erzeuger/verbraucher  */
/*  - erzeuger.c: datenproduzierender Prozess                   */
/*  - verbraucher.c: datenkonsumierender Prozess                */
/*                                                              */
/*   *** LOESUNGSBEISPIEL FUER NAMED PIPES ***                  */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFLEN 30
#define eof 0
#define NSEKUNDEN 5

int main (int argc, char* argv[])
{
   char buffer [BUFLEN+1];
   int fd;
	
   buffer [BUFLEN] = 0; /*String abschliessen mit NULL-Char.*/
   printf("Kind 2 meldet sich.\n");

   /* Oeffne vorhandene Pipe zum Lesen */
   fd = open ("./pipe_ev", O_RDONLY);
   if (fd < 0) {
      printf("open pipe failed.\n");
      exit(-1);
   }
   /* Verbinde Pipeausgang mit stdin */
   dup2 (fd, 0);	
	
   while (read(0, buffer, BUFLEN) != eof)
   {
      printf("Verbraucher %d : %s \n",getpid(),buffer);
   }
	
   sleep(NSEKUNDEN);/* Prozess soll noch eine Weile existieren zur Beobachtung */
   printf("\nVerbraucher hat ganze Pipe geleert.\n");
   close(fd);
   unlink("./pipe_ev");
   printf("Verbraucher hat named pipe geloescht.\n");
   exit(0);
}
