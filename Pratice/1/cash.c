#include <stdio.h>

int main(void){
int total;



printf("Enter amoount" );
scanf("%d",&total);


int count=0;

while(total-25>=0){
    total=total-25;
    ++count;
}

while(total-10>=0){
    total=total-10;
    ++count;
}

while(total-5>=0){
    total=total-5;
    ++count;
}

while(total-1>=0){
    total=total-1;
    ++count;
}

printf("%d", count);
}