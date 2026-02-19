#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Function to print total bins used */
void printBins(int bin_rem[], int binsUsed) {
    printf("Total bins used: %d\n", binsUsed);
}

/* ---------------- FIRST FIT ---------------- */
void firstFit(int weight[], int n, int capacity) {
    int bin_rem[MAX];
    int binsUsed = 0;

    for (int i = 0; i < n; i++) {
        int placed = 0;

        for (int j = 0; j < binsUsed; j++) {
            if (bin_rem[j] >= weight[i]) {
                bin_rem[j] -= weight[i];
                placed = 1;
                break;
            }
        }

        if (!placed) {
            bin_rem[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }

    printf("\nFirst Fit:\n");
    printBins(bin_rem, binsUsed);
}

/* ---------------- FIRST FIT DECREASING ---------------- */

/* Comparator for sorting in descending order */
int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (y - x);   // descending order
}

void firstFitDecreasing(int weight[], int n, int capacity) {
    int sorted[MAX];

    for (int i = 0; i < n; i++) {
        sorted[i] = weight[i];
    }

    /* Sort in decreasing order */
    qsort(sorted, n, sizeof(int), compare);

    printf("\nFirst Fit Decreasing:\n");
    firstFit(sorted, n, capacity);
}

/* ---------------- BEST FIT ---------------- */
void bestFit(int weight[], int n, int capacity) {
    int bin_rem[MAX];
    int binsUsed = 0;

    for (int i = 0; i < n; i++) {
        int min_space = capacity + 1;
        int bestIndex = -1;

        for (int j = 0; j < binsUsed; j++) {
            if (bin_rem[j] >= weight[i] &&
                (bin_rem[j] - weight[i]) < min_space) {

                bestIndex = j;
                min_space = bin_rem[j] - weight[i];
            }
        }

        if (bestIndex != -1) {
            bin_rem[bestIndex] -= weight[i];
        } else {
            bin_rem[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }

    printf("\nBest Fit:\n");
    printBins(bin_rem, binsUsed);
}

/* ---------------- MAIN FUNCTION ---------------- */
int main() {
    int n, capacity;
    int weight[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    firstFit(weight, n, capacity);
    firstFitDecreasing(weight, n, capacity);
    bestFit(weight, n, capacity);

    return 0;
}
