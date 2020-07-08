// Datei alarm.c
// =============
// Teil der Übung zu Signale unter Unix

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef linux
// Erzwinge klassisches Signalverhalten unter Linux
#define signal sysv_signal
#endif

void forward(int sigtype)
{
  write(STDOUT_FILENO, "Bin geweckt worden!\n", 21);
  signal(SIGALRM, forward);
}

int main ()
{
  int i;

  signal(SIGALRM, forward);
  for (i=1; i<10; i++)
  {
    printf("Haenge mich auf, stelle aber den Wecker!\n");
    alarm(3);
    pause();
    printf("Arbeite weiter...\n");
  }
  exit(0);
}

