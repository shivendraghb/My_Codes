#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for positive integer
    int n;
    do
    {
        n =  get_int("size: "); //here int isn't used because of"scope"of int function
    }
    while (n < 1);

    // print an n-by-n grid of bricks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
     }
}

