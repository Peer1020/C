//
// Echo-Server, der wiederholt auf eine Verbindungsaufnahme von einem Client wartet.
// Für jede angenommene Verbindung wird ein Thread zur Auftragsverarbeitung gestartet
//
// Kann der Server den TCP-Port nicht öffnen, so bricht er vorzeitig mit einer Fehlermeldung ab.
//

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>


void service(int consock, int cnt);
void * thread_func(void * arg);

struct request {
   int consock;
   int cnt;
};


int main() {

   int sock, consock; // Socket-Dateideskriptoren
   struct sockaddr_in srv_addr; // Serveradresse
   struct sockaddr_in cln_addr; // Clientadresse
   socklen_t addrlen; // Clientadresslänge

   sock = socket(AF_INET, SOCK_STREAM, 0); // Stream-Socket erzeugen

   srv_addr.sin_family = AF_INET; // Internet-Adressfamilie
   srv_addr.sin_addr.s_addr = INADDR_ANY; // Alle Netzw.schnittstellen
   srv_addr.sin_port = htons(3500); // TCP-Portnr. 3500
   bind(sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

   listen(sock, 5); // Erlaube Verbindungsaufnahme

   // Auf eine Verbindungsaufnahme warten
   printf("Server wartet auf Verbindungsaufnahme.\n");

   int cnt = 0;
   while (1) {
      addrlen = sizeof(cln_addr);
      consock = accept(sock, (struct sockaddr *)&cln_addr, &addrlen);
      struct request * prequest = malloc(sizeof(struct request));
      prequest->consock = consock;
      prequest->cnt = cnt++;
      pthread_t tid;
      pthread_create(&tid, NULL, thread_func, prequest);
      pthread_detach(tid);
   }

   close(sock); // Schliesse Server-Socket
   exit(0);
}



void service(int consock, int cnt)
{
   char buf[128]; // Puffer
   int nread; // Anzahl empfangener Byte

   char * sq = "code=";
   nread = read(consock, buf, sizeof(buf));// Lese soviel wie eingetroffen
   char * s = strstr(buf, sq);
   if (s!=NULL) {
      int code = atoi(s+strlen(sq));
      sprintf(&buf[nread-1],"code = %d", code);
   }
   int n = strlen(buf);
   write(consock, buf, n+1); // Echoe empfangene Daten
}


void * thread_func(void * arg)
{
   struct request * prequest = arg;
   service(prequest->consock, prequest->cnt);
   close(prequest->consock); // Verbindungsabbau
   free(arg);
   pthread_exit(NULL); // Auftrag erledigt
}

