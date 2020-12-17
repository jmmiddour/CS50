#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each row in the image matrix
    for (int r = 0; r < height; r++)
    {
        // Iterate through each pixel in the row of the image matrix
        for (int c = 0; c < width; c++)
        {
            // Calculate the average of red, green, and blue values for each pixel
            float avgrgb = (image[r][c].rgbtRed + image[r][c].rgbtGreen + image[r][c].rgbtBlue) / 3.0;
            
            // Round the average value for each pixel
            int avg = round(avgrgb);
            
            // Change the value for each pixel to the average of all 3 colors
            image[r][c].rgbtRed = avg;
            image[r][c].rgbtGreen = avg;
            image[r][c].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each row in the image matrix
    for (int r = 0; r < height; r++)
    {
        // Iterate through each pixel in the row of the image matrix
        for (int c = 0; c < width; c++)
        {
            // Create variable for each color's original value
            float or_red = image[r][c].rgbtRed;
            float or_green = image[r][c].rgbtGreen;
            float or_blue = image[r][c].rgbtBlue;
            
            // Calculate the sepia for each color value in each pixel using provided sepia formula
            float sep_red = ((or_red * 0.393) + (or_green * 0.769) + (or_blue * 0.189));
            float sep_green = ((or_red * 0.349) + (or_green * 0.686) + (or_blue * 0.168));
            float sep_blue = ((or_red * 0.272) + (or_green * 0.534) + (or_blue * 0.131));
            
            // Round the average value for each sepia color
            int red_avg = round(sep_red);
            int green_avg = round(sep_green);
            int blue_avg = round(sep_blue);
            
            // Change the value for each pixel to the average of all 3 colors
            // Making sure that the value does not exceed 255
            image[r][c].rgbtRed = (red_avg > 255) ? 255 : red_avg;
            image[r][c].rgbtGreen = (green_avg > 255) ? 255 : green_avg;
            image[r][c].rgbtBlue = (blue_avg > 255) ? 255 : blue_avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each row in the image matrix
    for (int r = 0; r < height; r++)
    {
        // Iterate through each pixel in the row of the image matrix
        for (int c = 0; c < (width / 2); c++)
        {
            // Create variable for each color's original value to hold that value
            int or_red = image[r][c].rgbtRed;
            int or_green = image[r][c].rgbtGreen;
            int or_blue = image[r][c].rgbtBlue;
            
            // Move each pixel value in a single row to it's new location
            image[r][c].rgbtRed = image[r][width - c - 1].rgbtRed;
            image[r][c].rgbtGreen = image[r][width - c - 1].rgbtGreen;
            image[r][c].rgbtBlue = image[r][width - c - 1].rgbtBlue;
            
            // Change the value for each new pixel to the original value from above
            image[r][width - c - 1].rgbtRed = or_red;
            image[r][width - c - 1].rgbtGreen = or_green;
            image[r][width - c - 1].rgbtBlue = or_blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make copy of the image file
    RGBTRIPLE img_copy[height][width];
    
    // Iterate through each row in the image matrix
    for (int r = 0; r < height; r++)
    {
        // Iterate through each pixel in the column of the image matrix
        for (int c = 0; c < width; c++)
        {
            // Create a counter for each color
            int red_cnt = 0;
            int green_cnt = 0;
            int blue_cnt = 0;
            float count = 0;
            
            // Iterate through each row to check for neighbors
            for (int rn = -1; rn < 2; rn++)
            {
                // Iterate through each column to check for neighbors
                for (int cn = -1; cn < 2; cn++)
                {
                    // If there are no neighbors 
                    if (r + rn < 0 || r + rn > height - 1 || c + cn < 0 || c + cn > width - 1)
                    {
                        continue;
                    }                        
                    // Add the color values up for the neighbors
                    red_cnt += image[r + rn][c + cn].rgbtRed;
                    green_cnt += image[r + rn][c + cn].rgbtGreen;
                    blue_cnt += image[r + rn][c + cn].rgbtBlue;
                    
                    // Increase for each iteration to know how many neighbors
                    count++;
                }
            }
            // Apply the averages for each color on the copy of the image
            img_copy[r][c].rgbtRed = round(red_cnt / count);
            img_copy[r][c].rgbtGreen = round(green_cnt / count);
            img_copy[r][c].rgbtBlue = round(blue_cnt / count);
        }
    }
    // Iterate through each pixel in the row of the original image matrix
    for (int r = 0; r < height; r++)
    {
        // Iterate through each pixel in the column of the original image matrix
        for (int c = 0; c < width; c++)
        {
            // Apply the values from the copy to the original image
            image[r][c].rgbtRed = img_copy[r][c].rgbtRed;
            image[r][c].rgbtGreen = img_copy[r][c].rgbtGreen;
            image[r][c].rgbtBlue = img_copy[r][c].rgbtBlue;
        }
    }
    return;
}
