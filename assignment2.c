#include <stdio.h>
#include <math.h>

void increaseMarks(int marks[], int n) {
    for (int i = 0; i < n; i++) marks[i] += 5;
    for (int i = 0; i < n; i++) printf("%d ", marks[i]);
}

void printGrades(int marks[], int n) {
    for (int i = 0; i < n; i++) {
        if (marks[i] >= 75) printf("A ");
        else if (marks[i] >= 60) printf("B ");
        else if (marks[i] >= 40) printf("C ");
        else printf("D ");
    }
}

void findFirst99(int marks[], int n) {
    for (int i = 0; i < n; i++) {
        if (marks[i] == 99) {
            printf("First 99 at index %d\n", i);
            return;
        }
    }
    printf("No 99 found\n");
}

void findAll99(int marks[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (marks[i] == 99) {
            printf("Index %d\n", i);
            count++;
        }
    }
    printf("Total: %d\n", count);
}

void sumScores(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += marks[i];
    printf("Sum: %d\n", sum);
}

void averageScore(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += marks[i];
    printf("Average: %.2f\n", sum / (float)n);
}

void evenOrOdd(int marks[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d is %s\n", marks[i], marks[i] % 2 == 0 ? "Even" : "Odd");
}

void findMaxMin(int marks[], int n) {
    int max = marks[0], min = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > max) max = marks[i];
        if (marks[i] < min) min = marks[i];
    }
    printf("Max: %d, Min: %d\n", max, min);
}

void findPeak(int marks[], int n) {
    for (int i = 1; i < n - 1; i++) {
        if (marks[i] >= marks[i - 1] && marks[i] >= marks[i + 1]) {
            printf("Peak: %d\n", marks[i]);
            return;
        }
    }
    printf("No peak element found\n");
}

void countPrimes(int marks[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (marks[i] < 2) continue;
        int isPrime = 1;
        for (int j = 2; j * j <= marks[i]; j++) {
            if (marks[i] % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) count++;
    }
    printf("Prime count: %d\n", count);
}

void insertInArray(int marks[], int *n) {
    int pos, val;
    printf("Enter position and value to insert: ");
    scanf("%d %d", &pos, &val);
    for (int i = *n; i > pos; i--) marks[i] = marks[i - 1];
    marks[pos] = val;
    (*n)++;
    for (int i = 0; i < *n; i++) printf("%d ", marks[i]);
}

void deleteFromArray(int marks[], int *n) {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    for (int i = pos; i < *n - 1; i++) marks[i] = marks[i + 1];
    (*n)--;
    for (int i = 0; i < *n; i++) printf("%d ", marks[i]);
}

void rotateArray(int marks[], int n) {
    int last = marks[n - 1];
    for (int i = n - 1; i > 0; i--) marks[i] = marks[i - 1];
    marks[0] = last;
    for (int i = 0; i < n; i++) printf("%d ", marks[i]);
}

void findDuplicates(int marks[], int n) {
    int freq[101] = {0}, hasDuplicates = 0;
    for (int i = 0; i < n; i++) freq[marks[i]]++;
    for (int i = 0; i <= 100; i++) {
        if (freq[i] > 1) {
            printf("%d ", i);
            hasDuplicates = 1;
        }
    }
    if (!hasDuplicates) printf("-1");
}

int main() {
    int n, choice, marks[100];
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter marks: ");
    for (int i = 0; i < n; i++) scanf("%d", &marks[i]);

    printf("Choose an option:\n");
    printf("1. Increase Marks by 5\n2. Print Grades\n3. Find First 99\n4. Find All 99\n5. Sum Scores\n");
    printf("6. Average Score\n7. Even or Odd\n8. Max and Min\n9. Peak Element\n10. Count Primes\n");
    printf("11. Insert in Array\n12. Delete from Array\n13. Rotate Array\n14. Find Duplicates\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: increaseMarks(marks, n); break;
        case 2: printGrades(marks, n); break;
        case 3: findFirst99(marks, n); break;
        case 4: findAll99(marks, n); break;
        case 5: sumScores(marks, n); break;
        case 6: averageScore(marks, n); break;
        case 7: evenOrOdd(marks, n); break;
        case 8: findMaxMin(marks, n); break;
        case 9: findPeak(marks, n); break;
        case 10: countPrimes(marks, n); break;
        case 11: insertInArray(marks, &n); break;
        case 12: deleteFromArray(marks, &n); break;
        case 13: rotateArray(marks, n); break;
        case 14: findDuplicates(marks, n); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
