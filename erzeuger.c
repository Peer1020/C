/*  Erzeuger.C                                                  */
/*                                                              */
/*  Beispiel fuer Pipe-Gebrauch                                 */
/*  Besteht aus den Dateien:                                    */
/*  - evpipe.c: erzeugt Pipe und Prozesse erzeuger/verbraucher  */
/*  - erzeuger.c: datenproduzierender Prozess                   */
/*  - verbraucher.c: datenkonsumierender Prozess                */
/*                                                              */
/*  Vorlagedatei fuer Uebung "Pipes unter Unix"                 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFLEN 80
#define NSEKUNDEN 3

int main (int argc, char* argv[])
{
   char* text;
   char buffer [BUFLEN];
   int anzsaetze = 25;
   int satznr;
   int anz;
   int fd;

/* öffne vorhandene Pipe zum lesen*/
   fd=open("./pipe_ev",O_WRONLY);
   if(fd<0){
   printf("open pipe failed");
   exit(-1);
	}

/* Verbinde Pipe Ausgang mit stdin*/	
   dup2(fd,1);



   // printf("Kind 1 meldet sich");  funktioniert nicht!
   text = "Kind 1 meldet sich.\n";
   write(1,text,18); 	// Text in Pipe schreiben

   for (satznr = 1; satznr <= anzsaetze; satznr++)
   {
      anz=sprintf(buffer, "==> Erzeuger %d Satznr. %6d ##",getpid(),satznr);
      write(1, buffer, anz);
   }

 //  write(1,"ENDE\0",5); // Wozu dient diese Zeile?

   sleep(NSEKUNDEN); // Prozess soll noch eine Weile existieren zur Beobachtung
   close(1);
   exit(0);
}
