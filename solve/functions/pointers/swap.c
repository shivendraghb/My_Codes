#include <stdio.h>
void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    printf("after swapping a=%d and b=%d\n", *a, *b);
}
int main()
{
    int a, b;
    printf("enter the value of and b: ");
    scanf("%d %d", &a, &b);
    printf("before swapping a=%d and b=%d\n", a, b);
    swap(&a, &b);
    return 0;
}
