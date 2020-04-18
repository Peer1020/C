#include <stdio.h>
#include<string.h>


typedef struct {
int artikelNummer;
int anzahl;
float preis;
char bezeichnung[50];
} t_artikel;

void printArtikel(t_artikel artikel);

int main() {
t_artikel artikel = {1234,40,40.56,"Peer"};
printArtikel(artikel);
return 0;
}


void printArtikel(t_artikel artikel){
printf("Artikelnummer: %i\n",artikel.artikelNummer);
printf("Anzahl: %i\n", artikel.anzahl);
printf("Preis: %2.f\n", artikel.preis);
printf("Bezeichnung: %s\n", artikel.bezeichnung);
}
