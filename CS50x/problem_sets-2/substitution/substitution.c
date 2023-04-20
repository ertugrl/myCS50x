#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void error(void);

int main(int argc, string argv[])
{
    string key = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Key must only contain alphabetic characters\n");
                return 1;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (key[j] == key[i])
                {
                    printf("key must contain each letter exactly once\n");
                    return 1;
                }
            }
        }
    }
    string s = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        int asc = s[i];
        if (isupper(asc))
        {
            int p = asc - 65;
            printf("%c", toupper(key[p]));
        }
        else if (islower(asc))
        {
            int p = asc - 97;
            printf("%c", tolower(key[p]));
        }
        else
        {
            printf("%c", asc);
        }
    }
    printf("\n");
}
