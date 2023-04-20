#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check whether number of the argument is 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //open file to read
    FILE *input_file = fopen(argv[1], "r");

    //check whether input_file is valid
    if (input_file == NULL)
    {
        printf("cannot open the file");
        return 1;
    }

    //store blocks of 512 bites in an array
    unsigned char buffer[512];

    //store the number of images generated
    int count_image = 0;

    //the number of images
    FILE *output_file = NULL;

    //generate allocated memory
    char *filename = malloc(8 * sizeof(char));

    //examine the blocks (512 bytes)
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //check if bytes indicate start of JPEG
        //"(buffer[3] & 0xf0) == 0xe0" is very important point in this part!!!
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) 
        {
            //just closing the opened file of the previous loop
            if (count_image > 0)
            {
                fclose(output_file);
            }

            //print out the JPEG filenames
            sprintf(filename, "%03i.jpg", count_image);

            //open output_file to write
            output_file = fopen(filename, "w");

            //increase the number of images that are found
            count_image++;
        }
        //check whether output is used for valid input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    //free the allocated memory
    free(filename);
    //this fclose is used to close the last opened file !!!
    fclose(output_file);
    fclose(input_file);
}