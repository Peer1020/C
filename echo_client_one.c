//
// Echo client, der einmalig "Hallo Welt!" an den Echo Server sendet.
//


#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
   int sock; // Socket-Dateideskriptor
   struct sockaddr_in srv_addr; // Serveradresse
   char *pbuf1 = "Hallo Welt!\n"; // Sendedaten
   char buf2[128]; // Empfangspuffer

   sock = socket(AF_INET, SOCK_STREAM, 0); // Stream-Socket erzeugen
   srv_addr.sin_family = AF_INET; // Internet-Adressfamilie
   srv_addr.sin_port = htons(3500); // Port 3500
   srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP-Adresse (localhost)
   connect(sock, (struct sockaddr*)&srv_addr, sizeof(srv_addr));
   write (sock, pbuf1, strlen(pbuf1)+1); // Sende Text
   read(sock, buf2, sizeof(buf2)); // Warte auf Echo
   printf("Echo: %s\n", buf2);
   close(sock);
   exit(0);
}

