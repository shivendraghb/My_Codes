#include <stdio.h>

void printWordsOnNewLine(char* s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            putchar(s[i]);//can use printf also printf("%c",s[i]);
        }
        else
        {
            putchar('\n');
        }
    }
    putchar('\n');
}

int main()
{
    char s[] = "i love coding and problem solving";
    printWordsOnNewLine(s);
    return 0;
}
