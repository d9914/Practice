#include <stdio.h>
#include <string.h>


//Incomplete but 90% done


int main(void){

char text[200];
printf("Text: ");
scanf("%s",&text);
int size = sizeof text / sizeof text[0];
int letters=0;

for(int i=0; i<size; ++i){
    if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')){
            ++letters;
    }
}

int words=1;
for(int i=0; i<size; ++i){
    if(text[i]=' '){
        ++words;
    }
}

int sentnece=0;
for(int i=0; i<size; ++i){
    if((text[i] = '.' )|| (text[i] = '!') || (text[i] = '?') ){
        ++sentnece;
         }
}

int L= 100*(letters/words);
int S= 100*(sentnece/words);

int index = (0.0588 * L) - (0.296 * S) - 15.8;

if(index>1 && index<16){
    printf("Grade:  %d", index);
}
else if(index>16){
    printf("Over grade 16");
}
else{
    printf("Below grade 1");
}

}
