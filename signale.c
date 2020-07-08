// Datei signale.c
// ===============

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void catcher(int sigtype)
{
  write(STDOUT_FILENO, "Habe das Signal erhalten!\n", 27);
  signal(SIGINT, catcher);
}

int main ()
{
  int i;

  signal(SIGINT, catcher);
  for (i=1; i<100; i++)
    {
    printf("Am Arbeiten...\n");
    sleep(1);
  }
  exit(0);
}

