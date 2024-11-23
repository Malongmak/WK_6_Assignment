#include <stdio.h>
#include "calculate.h"

int main() {
    // Example dataset
    double data[] = {30.5, 29.0, 30.5, 28.0, 31.5, 30.5, 32.0};
    int size = sizeof(data) / sizeof(data[0]);

    double mode = calculate_mode(data, size);
    double median = calculate_median(data, size);
    double std_dev = calculate_std_dev(data, size);

    printf("Mode: %.2f\n", mode);
    printf("Median: %.2f\n", median);
    printf("Standard Deviation: %.2f\n", std_dev);

    return 0;
}

