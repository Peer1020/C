#include <stdio.h>

int convert(char *input, int *pyear);
void print(int i);

int main() {
	int year;
	char * input="2050";
	if (convert(input,&year)){
	print(year);
	}
	return 0;
}

void print(int year){
	printf("Die aktuell Jahreszahl ist %d\n" ,year);
}



int convert(char * input, int * pyear){
sscanf(input,"%d", pyear);
if(*pyear>2100) return 1;
if(*pyear<1900) return 1;
return 0;
}

