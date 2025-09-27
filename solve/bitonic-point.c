#include <stdio.h>

int main() {
    int a[] = {2, 4, 7, 9, 12, 8, 6, 23, 12, 11};
    int n = sizeof(a) / sizeof(a[0]);

    int maxnumber = a[0];
    int maxposition = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] > a[i - 1]) && (a[i] > a[i + 1])) {
            if (a[i] > maxnumber) {
                maxnumber = a[i];
                maxposition = i;
            }
        }
    }

    printf("The bitonic point %d at position %d\n",maxnumber,maxposition);

    return 0;
}
