#include <stdio.h>
#include <math.h>
#include "calculate.h"

// Function to calculate the mode
double calculate_mode(double data[], int size) {
    int maxCount = 0;
    double mode = data[0];

    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (data[j] == data[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = data[i];
        }
    }

    return mode;
}

// Function to calculate the median
double calculate_median(double data[], int size) {
    // Sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (data[i] > data[j]) {
                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    } else {
        return data[size / 2];
    }
}

// Function to calculate the standard deviation
double calculate_std_dev(double data[], int size) {
    double mean = 0.0, sum = 0.0, variance = 0.0;

    for (int i = 0; i < size; i++) {
        mean += data[i];
    }
    mean /= size;

    for (int i = 0; i < size; i++) {
        sum += pow(data[i] - mean, 2);
    }

    variance = sum / size;
    return sqrt(variance);
}
