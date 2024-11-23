#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements (200 < n <= 2000): ");
    scanf("%d", &n);
    if (n <= 200 || n > 2000) {
        printf("Invalid value for n.\n");
        return 1;
    }

    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += numbers[i];
    }

    printf("Grand Total (Single-threaded): %d\n", total_sum);

    free(numbers);
    return 0;
}
