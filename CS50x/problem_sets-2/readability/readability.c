#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
// to count index and print text's grade
void calculator(int l, int w, int t);

int main(void)
{
    string text = get_string("Text: ");
    int l = count_letters(text);
    int w = count_words(text);
    int t = count_sentences(text);
    calculator(l, w, t);
}

int count_letters(string s)
{
    int letters = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char x = s[i];
        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string s)
{
    int words = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char x = s[i];
        if (x == ' ')
        {
            words++;
        }
    }
    words++;
    return words;
}

int count_sentences(string s)
{
    int sentences = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char x = s[i];
        if (x == '!' || x == '?' || x == '.')
        {
            sentences++;
        }
    }
    return sentences;
}

void calculator(int l, int w, int t)
{
    double L = ((float) l / w) * 100;
    double S = ((float) t / w) * 100;
    // "Coleman-Liau index" formula
    double index = 0.0588 * L - 0.296 * S - 15.8;
    // round up the index
    double grade = round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) grade);
    }
}







