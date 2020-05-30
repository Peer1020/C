#include <stdio.h>

typedef struct timenode {  
	unsigned int std;  
	unsigned int min;  
	unsigned int sec;  
	struct timenode * vzeiger;} timenode;

void insert(struct timenode * wurzel,
struct timenode * newnode,
int nach_element){
int akt_pos=1;
struct timenode * p= wurzel;
while(akt_pos<nach_element){
p=p->vzeiger;
akt_pos++;
if(p==0)break;
}
newnode->vzeiger=p->vzeiger;
p->vzeiger=newnode;
}

int main (){  
timenode b = { 9, 15, 30, 0  };
timenode a = { 8, 10,  0, &b };
timenode * wurzel = &a;  
timenode * p;  

timenode new1 = { 8, 12, 10, 0  };
insert(wurzel,&new1,1);
timenode new2 = { 9, 16, 50, 0  };
insert(wurzel,&new2,3);


p = wurzel;  
while (p != 0) {     
printf ("std = %i, min = %i, sec = %i\n", p->std, p->min, p->sec);    
p = p->vzeiger;  
}  
return 0;
}


