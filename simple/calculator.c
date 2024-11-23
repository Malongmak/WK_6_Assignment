#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {
    int choice, num1, num2, result;

    while (1) {
        printf("Simple Calculator\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %d\n", result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is undefined.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %d\n", result);
                }
                break;
        }
    }

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}
