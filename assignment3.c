#include <stdio.h>
#include <math.h>
float add(float a, float b) {
    return a + b;
}
float subtract(float a, float b) {
    return a - b;
}
float multiply(float a, float b) {
    return a * b;
}
float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}
double logarithm(float a) {
    if (a <= 0) {
        printf("Error: Logarithm of non-positive number\n");
        return 0;
    }
    return log(a);
}
double squareRoot(float a) {
    if (a < 0) {
        printf("Error: Square root of negative number\n");
        return 0;
    }
    return sqrt(a);
}
int main() {
    int choice;
    float num1, num2;
    printf("Simple Calculator:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Logarithmic Value\n");
    printf("6. Square Root\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", add(num1, num2));
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", subtract(num1, num2));
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", multiply(num1, num2));
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", divide(num1, num2));
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%f", &num1);
            printf("Result: %.2lf\n", logarithm(num1));
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%f", &num1);
            printf("Result: %.2lf\n", squareRoot(num1));
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
