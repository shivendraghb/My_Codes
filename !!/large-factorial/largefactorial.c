#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void extralongfactorials(int n) {
    int *result = malloc(2000 * sizeof(int));
    result[0] = 1;
    int res_size = 1;

    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < res_size; j++) {
            int prod = result[j] * i + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            result[res_size] = carry % 10;
            carry /= 10;
            res_size++;
        }
    }

    for (int i = res_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");

}

int main() {
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    extralongfactorials(n);
    return 0;
}
