//
// Echo client, der eine wählbare Anzahl an Anforderungen an den Echo Server sendt.
// Die Anzahl der Anforderungen kann beim Aufruf auf der Kommandizeile angegeben werden,
// wobei diese Anforderungen alle innerhalb einer Sekunde an den Server übermittelt werden.
// Das Programm bricht mit einer Fehlermeldung ab, wenn die Verbindungsaufnahme mit dem Server 
// nicht klappt.
//
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

void * thread_func(void * arg);


int main(int argc, char *argv[]) {
   int n = 1;
   if (argc > 1) n = atoi(argv[1]);
   printf("loop count = %d\n", n);

   int t = 1000000 / n; // Bestimme Pausengrösse in microsec
   printf("pause time = %d\n", t);
   for (int i=0; i<n; i++) {
      pthread_t tid;
      pthread_create(&tid, NULL, thread_func, (void *)i);
      pthread_detach(tid);
   }
   exit(0);
}


void * thread_func(void * arg)
{
   int cnt = (int)arg;
   int sock; // Socket-Dateideskriptor
   struct sockaddr_in srv_addr; // Serveradresse
   char buf1[128]; // Sendepuffer
   char buf2[128]; // Empfangspuffer

   srv_addr.sin_family = AF_INET; // Internet-Adressfamilie
   srv_addr.sin_port = htons(3500); // Port 3500
   srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP-Adresse

   sock = socket(AF_INET, SOCK_STREAM, 0); // Stream-Socket erzeugen
   if (connect(sock, (struct sockaddr*)&srv_addr, sizeof(srv_addr)) != 0) {
      perror("Conection failure: ");
      printf("connection number = %d\n", cnt);
      exit(1);
   }
   sprintf(buf1, "Hallo Welt! code=%d\n", cnt);
   write (sock, buf1, strlen(buf1)+1); // Sende Text
   read(sock, buf2, sizeof(buf2)); // Warte auf Echo
   close(sock);
}

