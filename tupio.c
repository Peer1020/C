// Datei tupio.c
// =============
// Teil der Übung zu Signale unter Unix

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


int c;

void timeup(int sigtype)
{
  write(STDOUT_FILENO, "Tut mir leid, Schnellentscheider sind gefragt.\n", 48);
  write(STDOUT_FILENO, "Versuchen Sie naechstes Mal schneller zu sein!!\n", 49);
  c = 1;
}

int main ()
{
#ifdef __FreeBSD__
  siginterrupt(SIGALRM, 1);   // Konfiguriert FreeBSD signal() fuer klassisches Verhalten (ohne SA_RESTART)
#endif
  signal(SIGALRM, timeup);
  while(1)
  {
    printf("Bitte waehlen Sie aus:\n");
    printf("0 = Quit, 1 = Begruessung, 2 = Joke\n");
    alarm(3);
    scanf("%d", &c);
    alarm(0);
    switch (c)
    {
      case 0:  exit(1);
      case 1:  printf("Hallo\n");
               break;
      case 2:  printf("Warum sind viele Frauen von London enttaeuscht?\n");
               printf("Sie merken, dass Big Ben nur ein Glockenturm ist.\n");
               break;
      default: printf("Ungueltige Eingabe. Waehlbar sind 0..2\n");
               break;
     }
   }
}
