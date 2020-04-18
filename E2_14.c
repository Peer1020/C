#include <stdio.h>
#include<string.h>

void convertYear(int year, char * buffer);


int main() {
	int year = 2017;
	char buffer[5];
	convertYear(year, buffer);
	printf("Die aktuell Jahreszahl ist %s\n" ,buffer);
	return 0;
}


void convertYear(int year, char * buffer){
sprintf(buffer,"%d",year);
}



