#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    int m = n; // this variable 'm' is the clon of 'n'

    for (int i = 0; i < n; i++) // for rows
    {
        for (int j = 0; j < (m - 1); j++) // for left spaces
        {
            printf(" ");
        }

        m--; // decrease 'm' by 1 to reduce the number of left spaces

        for (int k = 0; k < (n - m); k++) // for the left hashes
        {
            printf("#");
        }

        printf("  "); //for the gaps

        for (int k = 0; k < (n - m); k++) //for the right hashes
        {
            printf("#");
        }

        printf("\n"); //to pass the bottom row
    }
}