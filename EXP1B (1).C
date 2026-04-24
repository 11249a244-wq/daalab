#include <stdio.h>

int main() {
    int n, i, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n >= 1) printf("Fibonacci Series: %d, ", t1);
    if (n >= 2) printf("%d, ", t2);

    nextTerm = t1 + t2;
    for (i = 3; i <= n; ++i) {
        printf("%d, ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    printf("\n");

    return 0;
}
