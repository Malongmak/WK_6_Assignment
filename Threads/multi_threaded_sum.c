#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 20

int *numbers;
int results[MAX_THREADS];
int n, thread_count;

void *partial_sum(void *arg) {
    int index = *(int *)arg;
    int start = index * 100;
    int end = start + 100;
    int sum = 0;

    for (int i = start; i < end && i < n; i++) {
        sum += numbers[i];
    }
    results[index] = sum;

    free(arg);
    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of elements (200 < n <= 2000): ");
    scanf("%d", &n);
    if (n <= 200 || n > 2000) {
        printf("Invalid value for n.\n");
        return 1;
    }

    numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    thread_count = n / 100 + (n % 100 != 0); 
    pthread_t threads[thread_count];

    for (int i = 0; i < thread_count; i++) {
        int *index = (int *)malloc(sizeof(int));
        *index = i;
        if (pthread_create(&threads[i], NULL, partial_sum, index) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_sum = 0;
    for (int i = 0; i < thread_count; i++) {
        total_sum += results[i];
    }

    printf("Grand Total (Multi-threaded): %d\n", total_sum);

    free(numbers);
    return 0;
}
