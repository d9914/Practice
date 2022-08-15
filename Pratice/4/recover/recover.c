#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512;
 
int inputError(){
pritnf("Usage: ./recover IMAGE\n");
    return 1;
}

int fileError(char fileName[]){
    printf("Unable to Open File: %s\n ", fileName);
    return 1;
}
bool isJpgHeader(uint8_t buffer[]){
    
    return 
    buffer[0] == 0xff
    && buffer[1]== 0xd8
    && buffer[2]== 0xff
    && (buffer[3]== 0xf0)== 0xe0;

}


int main(int argc, char *argv[])
{
 if(argc!=2){
    return inputError();
 }
 char *inputFile[]=argv[1];
 if(inputFile==NULL){
   return inputError();
 }
FILE* inputPtr= fopen(inputFile, "r");
if(inputPtr==NULL){
  return fileError(inputFile);
}

char filename [8];
FILE*outputPtr= NULL;
uint8_t buffer[512];
int jpgCoutner=0;

while(fread(buffer, sizeof(uint8_t), 512, inputPtr) || feof(inputPtr)==0)
{
    if(isJpgHeader (buffer)){
        if(outputPtr!= NULL){
            fclose(outputPtr);
        }
        sprintf(filename, "%03i.jpg", jpgCoutner);
        outputPtr= fopen(filename, "W");
        ++jpgCoutner;   
         }
    if(outputPtr!= NULL){
        fwrite(buffer, sizeof(buffer), 1, outputPtr);

    }
}

if(inputPtr!=NULL){
    fclose(inputPtr);
}
if(outputPtr!=NULL){
    fclose(outputPtr);
}
return 0;
}
