#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int word_count(string text);
int sentence_count(string text);
int average_number_of_letters_per_word(string text);
int index_of(int avg_char_count_per_word, int word_count, string text);


int main(void)
{
    string text = get_string("Add text here to evaluate grade level: ");
    int avg_char_count_per_word = average_number_of_letters_per_word(text);
    int index = index_of(avg_char_count_per_word, word_count(text), text);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}


int sentence_count(string text)
{
    int count = 0;
    size_t len = strlen(text);
    for (size_t i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}


int word_count(string text)
{
    int count = 0;
    bool in_word = false;
    size_t len = strlen(text);

    for (size_t i = 0; i < len; i++)
    {
        if (isspace(text[i]) || text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            if (in_word)
            {
                count++;
                in_word = false;
            }
        }
        else
        {
            in_word = true;
        }
    }
    if (in_word)
    {
        count++;
    }
    return count;
}


int average_number_of_letters_per_word(string text)
{
    int letter_count = 0;
    size_t len = strlen(text);
    for (size_t i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

//coleman-liau index
int index_of(int letter_count, int word_count, string text)
{
    float L = (float)letter_count * 100.0 / word_count;
    float S = (float)(sentence_count(text) * 100) / word_count;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //debug output
    printf("Letters: %d\n", letter_count);
    printf("Words: %d\n", word_count);
    printf("Sentences: %d\n", sentence_count(text));
    printf("L: %f\n", L);
    printf("S: %f\n", S);
    printf("Index: %f\n", index);
    return (int)round(index);
}
