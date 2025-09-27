#include <stdio.h>

// Function to calculate GCD using Euclid's Algorithm
int gcd(int n1, int n2) {
    if (n2 == 0) {
        printf("gcd of these two numbers=%d\n",n1);
        return 0;
    }
    return gcd(n2, n1 % n2);
}

int main() {
    int t, n1, n2;
    scanf("%d", &t); // Number of test cases

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n1, &n2);
        int result = gcd(n1, n2);
    }

    return 0;
}
