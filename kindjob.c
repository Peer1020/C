// Datei kindjob.c
// ===============

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void dojob()
{
  write(STDOUT_FILENO, "Kindprozess erledigt Auftrag.\n", 31);
  signal(SIGUSR1, dojob);
}

int main (int argc, char* argv[])
{
  int i,i2;

  printf("Kindprozess mit PID=%d meldet sich und wartet, bis Auftragsanforderung kommt.\n", getpid());
  signal(SIGUSR1, dojob);
  while(1)
  {
    pause();
    for (i=1; i<5; i++)
    {
      i2 = i*i;
      printf("%i im Quadrat ergibt %i\n",i,i2);
    }
    kill(getppid(),SIGUSR2);
  }
}

