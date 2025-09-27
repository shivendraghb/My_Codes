#include <stdio.h>
void printWordsOnNewLine(char* s)
{
    char word[100];
    int index = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            word[index++] = s[i];
        }
        else
        {
            word[index] = '\0';
            printf("%s\n", word);
            index = 0;
        }
    }

    if (index > 0)
    {
        word[index] = '\0';
        printf("%s\n", word);
    }
}
int main()
{
    char s[] = "hello guys this is a test";
    printWordsOnNewLine(s);
    return 0;
}
