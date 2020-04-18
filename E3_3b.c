#include <stdio.h>
#include <stdlib.h>

void addFunction(void (*ptr) (void));

void printRed();
void printOrange();
void printGreen();
int nextIndex=0;
void* fPointer[10];

int main (){

void (*ptr1) (void);
ptr1 = printRed;
addFunction(ptr1);

void (*ptr2) (void);
ptr1 = printOrange;
addFunction(ptr2);

void (*ptr3) (void);
ptr1 = printGreen;
addFunction(ptr3);

addFunction(ptr2);
addFunction(ptr1);

execute();

return 0;

}

void addFunction(void (*ptr) (void)){
fPointer[nextIndex++]=ptr;
}


void execute(){
int i=0;
for(i;i<nextIndex;i++){
void(*ptr)(void);
ptr=fPointer[i];
(*ptr)(),
sleep(1);
}
}

void printRed() { printf("Ampel ist rot.\n"); }
void printOrange() { printf("Ampel ist orange.\n"); }
void printGreen() { printf("Ampel ist grün.\n"); }

