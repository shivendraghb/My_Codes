#include <stdio.h>

int main() {
    int a[100] = { [4] = 10, [89] = 50 };

    for (int i = 0; i < 100; i++)
        printf("%d ", a[i]);

    return 0;
}