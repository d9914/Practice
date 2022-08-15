// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;
typedef int16_t SAMPLE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

BYTE buffer[HEADER_SIZE];

fread(buffer, sizeof(BYTE), HEADER_SIZE, input);

fwrite(buffer, sizeof(BYTE),HEADER_SIZE, output);

SAMPLE bufferr;



while(fread(&bufferr, sizeof(SAMPLE), 1, input)==1){
    bufferr= bufferr * factor;
    fwrite(&bufferr, sizeof(SAMPLE), 1, output);
}

    fclose(input);
    fclose(output);
}
