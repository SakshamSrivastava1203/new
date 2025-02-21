#include <stdio.h>
#include <stdlib.h>

// Function prototypes for 1-D Array and Pattern problems
void butterflyPattern();
void reverseArray();
void findMinMax();
void sumAndAverage();
void sortArray();
void linearSearch();
void removeDuplicates();
void longestConsecutiveSubsequence();

// Function prototypes for 2-D Matrix problems
void matrixTranspose();
void matrixMultiplication();
void diagonalSum();
void maxRowSum();
void searchInSortedMatrix();
void boundaryElements();
void saddlePoint();

// Helper function for qsort (used in longestConsecutiveSubsequence)
int compare(const void *a, const void *b) { 
    return (*(int *)a - *(int *)b); 
}

int main() {
    int choice;
    while (1) {
        printf("\nPractice Assignment - Part 2\n");
        printf("1.  Butterfly Pattern\n");
        printf("2.  Array Reverse\n");
        printf("3.  Find Maximum and Minimum\n");
        printf("4.  Sum and Average of Array Elements\n");
        printf("5.  Sort an Array\n");
        printf("6.  Linear Search\n");
        printf("7.  Remove Duplicates\n");
        printf("8.  Longest Consecutive Subsequence\n");
        printf("9.  Matrix Transpose\n");
        printf("10. Matrix Multiplication\n");
        printf("11. Diagonal Sum of a Matrix\n");
        printf("12. Row with Maximum Sum in a Matrix\n");
        printf("13. Search in a Sorted Matrix\n");
        printf("14. Boundary Elements of a Matrix\n");
        printf("15. Find Saddle Point\n");
        printf("16. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:  butterflyPattern(); break;
            case 2:  reverseArray(); break;
            case 3:  findMinMax(); break;
            case 4:  sumAndAverage(); break;
            case 5:  sortArray(); break;
            case 6:  linearSearch(); break;
            case 7:  removeDuplicates(); break;
            case 8:  longestConsecutiveSubsequence(); break;
            case 9:  matrixTranspose(); break;
            case 10: matrixMultiplication(); break;
            case 11: diagonalSum(); break;
            case 12: maxRowSum(); break;
            case 13: searchInSortedMatrix(); break;
            case 14: boundaryElements(); break;
            case 15: saddlePoint(); break;
            case 16: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

/* 1. Butterfly Pattern */
void butterflyPattern() {
    int n;
    printf("Enter n for butterfly pattern: ");
    scanf("%d", &n);
    // Upper half of the butterfly
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("*");
        for (int j = 1; j <= 2 * (n - i); j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    // Lower half of the butterfly
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            printf("*");
        for (int j = 1; j <= 2 * (n - i); j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

/* 2. Reverse an Array */
void reverseArray() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Reversed Array: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* 3. Find Maximum and Minimum */
void findMinMax() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    printf("Minimum: %d, Maximum: %d\n", min, max);
}

/* 4. Sum and Average of Array Elements */
void sumAndAverage() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum: %d, Average: %.2f\n", sum, (float)sum / n);
}

/* 5. Sort an Array (Bubble Sort) */
void sortArray() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* 6. Linear Search */
void linearSearch() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter key to search: ");
    scanf("%d", &key);
    
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }
    
    if (found == -1)
        printf("Key not found.\n");
    else
        printf("Key found at index %d.\n", found);
}

/* 7. Remove Duplicates */
void removeDuplicates() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int temp[n], j = 0;
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            temp[j++] = arr[i];
        }
    }
    
    printf("Array after removing duplicates: ");
    for (int i = 0; i < j; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

/* 8. Longest Consecutive Subsequence */
void longestConsecutiveSubsequence() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare);
    
    int maxLen = 1, curLen = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1)
            curLen++;
        else if (arr[i] != arr[i - 1])
            curLen = 1;
        if (curLen > maxLen)
            maxLen = curLen;
    }
    printf("Length of longest consecutive subsequence: %d\n", maxLen);
}

/* 9. Matrix Transpose */
void matrixTranspose() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int matrix[m][n], transpose[n][m];
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    
    // Compute transpose
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            transpose[j][i] = matrix[i][j];
    
    printf("Transposed Matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }
}

/* 10. Matrix Multiplication */
void matrixMultiplication() {
    int m1, n1, m2, n2;
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &m1, &n1);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &m2, &n2);
    
    if (n1 != m2) {
        printf("Matrix multiplication not possible (columns of A must equal rows of B).\n");
        return;
    }
    
    int A[m1][n1], B[m2][n2], product[m1][n2];
    
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            scanf("%d", &A[i][j]);
    
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            scanf("%d", &B[i][j]);
    
    // Initialize product matrix to 0
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n2; j++)
            product[i][j] = 0;
    
    // Multiply matrices
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n2; j++)
            for (int k = 0; k < n1; k++)
                product[i][j] += A[i][k] * B[k][j];
    
    printf("Product Matrix:\n");
    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n2; j++)
            printf("%d ", product[i][j]);
        printf("\n");
    }
}

/* 11. Diagonal Sum of a Matrix */
void diagonalSum() {
    int n;
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    
    int primarySum = 0, secondarySum = 0;
    for (int i = 0; i < n; i++) {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][n - i - 1];
    }
    printf("Primary Diagonal Sum: %d\n", primarySum);
    printf("Secondary Diagonal Sum: %d\n", secondarySum);
}

/* 12. Row with Maximum Sum in a Matrix */
void maxRowSum() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    
    int maxSum = -__INT_MAX__, rowIndex = -1;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            rowIndex = i;
        }
    }
    printf("Row %d has the maximum sum of %d.\n", rowIndex, maxSum);
}

/* 13. Search in a Sorted Matrix
   (Matrix is sorted row-wise and column-wise. Uses staircase search.) */
void searchInSortedMatrix() {
    int m, n, key;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    
    printf("Enter matrix elements (sorted row-wise and column-wise):\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    
    int i = 0, j = n - 1;
    int found = 0;
    while (i < m && j >= 0) {
        if (matrix[i][j] == key) {
            printf("Element found at position (%d, %d).\n", i, j);
            found = 1;
            break;
        }
        else if (matrix[i][j] > key)
            j--;
        else
            i++;
    }
    if (!found)
        printf("Element not found in the matrix.\n");
}

/* 14. Boundary Elements of a Matrix */
void boundaryElements() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    
    printf("Boundary Elements:\n");
    // Top row
    for (int j = 0; j < n; j++)
        printf("%d ", matrix[0][j]);
    // Right column (excluding top)
    for (int i = 1; i < m; i++)
        printf("%d ", matrix[i][n - 1]);
    // Bottom row (if m > 1)
    if (m > 1) {
        for (int j = n - 2; j >= 0; j--)
            printf("%d ", matrix[m - 1][j]);
    }
    // Left column (if n > 1, excluding top and bottom)
    if (n > 1) {
        for (int i = m - 2; i > 0; i--)
            printf("%d ", matrix[i][0]);
    }
    printf("\n");
}

/* 15. Find Saddle Point
   (Element that is minimum in its row and maximum in its column) */
void saddlePoint() {
    int m, n;
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    
    int saddleFound = 0;
    for (int i = 0; i < m; i++) {
        // Assume first element of row is the saddle candidate
        int candidate = matrix[i][0];
        int colIndex = 0;
        // Find minimum in the row
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < candidate) {
                candidate = matrix[i][j];
                colIndex = j;
            }
        }
        // Check if candidate is maximum in its column
        int k;
        for (k = 0; k < m; k++) {
            if (matrix[k][colIndex] > candidate)
                break;
        }
        if (k == m) {
            printf("Saddle point is %d at position (%d, %d).\n", candidate, i, colIndex);
            saddleFound = 1;
            // If only one saddle point is needed, you can return here.
            // return;
        }
    }
    if (!saddleFound)
        printf("No saddle point found in the matrix.\n");
}
