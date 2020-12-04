//
// Echo-Server, der einmalig auf eine Verbindungsaufnahme von einem Client wartet. Sobald dies
// stattfindet, sendet der Server den empfangenen Text zurück.
// Kann der Server den TCP-Port nicht öffnen, so bricht er vorzeitig mit einer Fehlermeldung ab.
//

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>


int main() {

   int sock, consock; // Socket-Dateideskriptoren
   struct sockaddr_in srv_addr; // Serveradresse
   struct sockaddr_in cln_addr; // Clientadresse
   socklen_t addrlen; // Clientadresslänge
   char buf[128]; // Puffer
   int nread; // Anzahl empfangener Byte

   sock = socket(AF_INET, SOCK_STREAM, 0); // Stream-Socket erzeugen

   srv_addr.sin_family = AF_INET; // Internet-Adressfamilie
   srv_addr.sin_addr.s_addr = INADDR_ANY; // Alle Netzw.schnittstellen
   srv_addr.sin_port = htons(3500); // TCP-Portnr. 3500
   if (bind(sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) != 0) {
      perror("Unable to open socket: ");
      exit(1);
   }

   listen(sock, 5); // Erlaube Verbindungsaufnahme

   // Auf eine Verbindungsaufnahme warten
   printf("Server wartet auf Verbindungsaufnahme.\n");

   addrlen = sizeof(cln_addr);
   consock = accept(sock, (struct sockaddr *)&cln_addr, &addrlen);

   nread = read(consock, buf, sizeof(buf));// Empfange einmal Daten
   write(consock, buf, nread); // Echoe empfangene Daten

   close(consock); // Verbindungsabbau
   close(sock); // Schliesse Server-Socket
   exit(0);
}

