#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("how many times you want the cat to meow? ");

    for (int i = 0; i < n; i++)
    {
        printf("meow ");
    }

    printf("\n");
}
