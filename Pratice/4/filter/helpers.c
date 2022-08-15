#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            avg=(image[i][j].rgbtBlue+image[i][j].rgbtRed+image[i][j].rgbtGreen);
            avg=round(avg/3);
            image[i][j].rgbtBlue=avg;
            image[i][j].rgbtRed=avg;
            image[i][j].rgbtGreen=avg;
        }
         }
        return;
}


int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaBlue;
    float sepiaRed;
    float sepiaGreen;
    
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            sepiaBlue = limit(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            sepiaRed = limit(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }

    return;
}
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            image[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
