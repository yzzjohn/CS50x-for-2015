/**
 * resize.c
 *
 * HarvardX: CS50x3 Introduction to Computer Science
 * Problem Set 4
 *
 * John YZ Zhu
 * yzzjohn@gmail.com
 *
 * resize a BMP according to the given factor between 1 to 100
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // remember the factor and check if valid
    int factor = atoi(argv[1]);
    if (factor < 1 || factor > 100)
    {
        printf("Error! n must be an integer between 1 to 100\n");
        return 2;
    }

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // calculate the new height and width
    int pHeight = bi.biHeight;
    int pWidth = bi.biWidth;
    bi.biHeight = bi.biHeight * factor;
    bi.biWidth = bi.biWidth * factor;


    // calculate the new padding
    int ppadding =  (4 - (pWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // calculate the new size
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + bf.bfOffBits;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // calculate the previous length
    int plength = pWidth * sizeof(RGBTRIPLE) + ppadding;

    // iterate over infile's scanlines
    for (int i = 0; i < abs(pHeight); i++)
    {
        for (int l = 0; l < factor; l++)
        {
            // move back the pointer
            fseek(inptr, (bf.bfOffBits + plength * i), SEEK_SET);

            // iterate over pixels in scanline
            for (int j = 0; j < pWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int m = 0; m < factor; m++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
       }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
