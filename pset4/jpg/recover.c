/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// the block's size is 512B
#define BUFFERLEN 512

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
    // open the input
    FILE* raw = fopen("card.raw", "r");

    // check the raw file is opened currectly
    if (raw == NULL)
    {
        printf("Sorry, but we cannot open the card.raw file!\n");
        return 1;
    }

    // create an empty file for output
    FILE* outptr = NULL;

    // counter for the images
    int number = 0;

    // create an string for file names
    char filename[8];

    // initialize a 512B buffer for efficiency's sake
    BYTE buffer[BUFFERLEN] = {0};

    while(!feof(raw))
    {
        // when meet the start of a jpeg file
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // close the previous image
            if (outptr != NULL)
                fclose(outptr);

            // output a file with the correct name
            sprintf(filename, "%03d.jpg", number);
            outptr = fopen(filename, "w");
            number++;

            if (outptr == NULL)
            {
                printf("Sorry, but the image couldn't be written\n");
                return 2;
            }

            fwrite(buffer, BUFFERLEN, 1, outptr);
        }

        else
        {
            // start writing when the first jpeg has been found
            if (number > 0)
                fwrite(buffer, BUFFERLEN, 1, outptr);
        }

        // copy the raw into buffer 512 by 512
        fread(buffer, BUFFERLEN, 1, raw);
    }

    fclose(outptr);
    fclose(raw);

    return 0;
}
