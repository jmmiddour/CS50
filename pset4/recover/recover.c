#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int jpg_block(unsigned char buffer[]);

int main(int argc, char *argv[])
{
    // Check for correct input in command line
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Make a copy of the .raw file to work with and open it
    FILE *file = fopen(argv[1], "r");

    // Make sure there is data in the file
    if (file == NULL)
    {
        fprintf(stderr, "Your file can not be opened.\n");
        return 1;
    }
    
    char new_file[8];  // Create new JPEG file
    uint8_t buffer[512];  // Create the buffer variable
    FILE* outptr = 0;  // Create an output pointer
    int found = 0;  // Block count for JPEG

    // Iterate through the raw file
    while (fread(buffer, sizeof(uint8_t), 512, file) != 0)
    {
        // If block is the start of a JPEG file
        if (jpg_block(buffer))
        {
            // If JPEG block is complete
            if (outptr != 0)
            {
                // Close file
                fclose(outptr);
            }

            // Name the new JPEG file
            sprintf(new_file, "%03i.jpg", found);

            // Open and write block to new file
            outptr = fopen(new_file, "w");
            found++;  // Increment counter by 1
        }

        // If JPEG is complete
        if (outptr != 0)
        {
            // Write to the new file
            fwrite(buffer, sizeof(buffer), 1, outptr);
        }
    }
    
    if (file == NULL)
    {
        // Close the files
        fclose(file);
    }
    
    if (outptr == 0)
    {
        // Close the files
        fclose(outptr);
    }
    
    return 0;
}


// Create a function to check if the block is part of a JPEG
int jpg_block (uint8_t buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
