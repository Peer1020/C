// Datei sigsincro.c
// =================


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void sincro()
{
  signal(SIGUSR2, sincro);
}

int main()
{
  int kind;

  kind = fork();
  if (kind == 0)
  {
    execlp("./kindjob", "kindjob", NULL);
  }
  else
  {
    signal(SIGUSR2, sincro);
    while(1)
    {
      printf("Elternteil erledigt seine Arbeit.\n");
      sleep(3);	// Simuliert Arbeit
      printf("Wecke Kindprozess mit PID=%d und warte, bis Job erledigt.\n",kind);
      kill(kind,SIGUSR1);
      pause();
    }
  }
}

