#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Check Armstrong Number\n");
    printf("2. Find HCF\n");
    printf("3. Subtract using Bitwise Operators\n");
    printf("4. Swap Numbers (4 Methods)\n");
    printf("5. Check Perfect Number\n");
    printf("6. Find Quadrant of Coordinate\n");
    printf("7. Binary to Decimal or Decimal to Binary\n");
    printf("8. Print Pattern\n");
    printf("9. Print Pyramid\n");
    printf("10. Print Pascal's Triangle\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int num, sum = 0, temp, digit;
        printf("Enter a number: ");
        scanf("%d", &num);
        temp = num;
        while (temp != 0) {
            digit = temp % 10;
            sum += digit * digit * digit;
            temp /= 10;
        }
        if (sum == num) printf("Armstrong\n"); else printf("Not Armstrong\n");
    } else if (choice == 2) {
        int a, b, hcf;
        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);
        for (hcf = (a < b ? a : b); hcf > 0; hcf--)
            if (a % hcf == 0 && b % hcf == 0) break;
        printf("HCF: %d\n", hcf);
    } else if (choice == 3) {
        int x, y;
        printf("Enter two numbers: ");
        scanf("%d %d", &x, &y);
        printf("Subtraction: %d\n", x + (~y + 1));
    } else if (choice == 4) {
        int x, y, temp;
        printf("Enter two numbers: ");
        scanf("%d %d", &x, &y);
        temp = x, x = y, y = temp;
        printf("Swapped: %d %d\n", x, y);
    } else if (choice == 5) {
        int num, sum = 0, i;
        printf("Enter a number: ");
        scanf("%d", &num);
        for (i = 1; i < num; i++)
            if (num % i == 0) sum += i;
        if (sum == num) printf("Perfect\n"); else printf("Not Perfect\n");
    } else if (choice == 6) {
        int x, y;
        printf("Enter coordinates: ");
        scanf("%d %d", &x, &y);
        if (x > 0 && y > 0) printf("First Quadrant\n");
        else if (x < 0 && y > 0) printf("Second Quadrant\n");
        else if (x < 0 && y < 0) printf("Third Quadrant\n");
        else if (x > 0 && y < 0) printf("Fourth Quadrant\n");
        else printf("On an Axis\n");
    } else if (choice == 7) {
        int num, base;
        printf("Enter 1 for Binary to Decimal, 2 for Decimal to Binary: ");
        scanf("%d", &base);
        if (base == 1) {
            int bin, dec = 0, power = 0;
            printf("Enter Binary: ");
            scanf("%d", &bin);
            while (bin > 0) {
                dec += (bin % 10) * pow(2, power++);
                bin /= 10;
            }
            printf("Decimal: %d\n", dec);
        } else {
            int dec, bin = 0, place = 1;
            printf("Enter Decimal: ");
            scanf("%d", &dec);
            while (dec > 0) {
                bin += (dec % 2) * place;
                dec /= 2;
                place *= 10;
            }
            printf("Binary: %d\n", bin);
        }
    } else if (choice == 8) {
        int rows, i, j;
        printf("Enter rows: ");
        scanf("%d", &rows);
        for (i = 1; i <= rows; i++) {
            for (j = 1; j <= i; j++)
                printf("%d", (i + j) % 2);
            printf("\n");
        }
    } else if (choice == 9) {
        int rows, i, j, space;
        printf("Enter rows: ");
        scanf("%d", &rows);
        for (i = 1; i <= rows; i++) {
            for (space = 1; space <= rows - i; space++) printf(" ");
            for (j = 1; j <= i; j++) printf("%d", j % 2);
            printf("\n");
        }
    } else if (choice == 10) {
        int rows, i, j, num;
        printf("Enter rows: ");
        scanf("%d", &rows);
        for (i = 0; i < rows; i++) {
            num = 1;
            for (j = 0; j <= i; j++) {
                printf("%d ", num);
                num = num * (i - j) / (j + 1);
            }
            printf("\n");
        }
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
