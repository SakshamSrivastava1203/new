#include <iostream>
#include <string>
#include <cstdarg>  
#include <cmath>      
#include <cstdlib>
using namespace std;

// ==================== Basic Function Questions ====================

// 1. Return the larger of two numbers.
int maxNumber(int a, int b) {
    return (a > b) ? a : b;
}

// 2. Factorial (iterative version)
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// 3. Reverse a number.
int reverseNumber(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

// 4. Sum of digits of a number.
int sumOfDigits(int n) {
    int sum = 0;
    n = abs(n); // handle negative numbers
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// 5. Check if a number is a palindrome.
bool isPalindrome(int n) {
    return n == reverseNumber(n);
}

// 6. Find the nth Fibonacci number (iterative version).
int fibonacci(int n) {
    if(n <= 0) return 0;
    if(n == 1) return 1;
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 7. Greatest Common Divisor (iterative version).
int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ==================== Polymorphism - Function Overloading ====================

// 8. Overloaded print() functions.
void print(const string &s) {
    cout << "String: " << s << endl;
}
void print(int x) {
    cout << "Integer: " << x << endl;
}
void print(const string &s, int x) {
    cout << "String and Integer: " << s << ", " << x << endl;
}

// 9. Class Calculator with overloaded sum() functions.
class Calculator {
public:
    int sum(int a, int b) {
        return a + b;
    }
    double sum(double a, double b, double c) {
        return a + b + c;
    }
    float sum(int a, float b) {
        return a + b;
    }
};

// 10. Overloaded multiply() functions.
int multiply(int a, int b) {
    return a * b;
}
double multiply(int a, double b) {
    return a * b;
}
float multiply(float a, float b, float c) {
    return a * b * c;
}

// 11. Overloaded greet() functions.
void greet() {
    cout << "Hello!" << endl;
}
void greet(const string &name) {
    cout << "Hello, " << name << "!" << endl;
}
void greet(const string &name, int age) {
    cout << "Hello, " << name << "! You are " << age << " years old." << endl;
}

// 12. Overloaded area() functions.
int area(int side) { // square
    return side * side;
}
int area(int length, int width) { // rectangle
    return length * width;
}
double area(double radius) { // circle
    return M_PI * radius * radius;
}

// 13. Overloaded concat() functions.
string concat(const string &s1, const string &s2) {
    return s1 + s2;
}
string concat(int num, const string &s) {
    return to_string(num) + s;
}

// 14. Overloaded power() functions.
int power(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++)
        result *= base;
    return result;
}
double power(double base, int exp) {
    double result = 1.0;
    for(int i = 0; i < exp; i++)
        result *= base;
    return result;
}

// 15. Variable-length argument: Sum of integers.
int sumVar(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count);
    for(int i = 0; i < count; i++)
        total += va_arg(args, int);
    va_end(args);
    return total;
}

// 16. Variable-length argument: Find largest integer.
int findLargest(int count, ...) {
    va_list args;
    va_start(args, count);
    int largest = va_arg(args, int);
    for(int i = 1; i < count; i++){
        int val = va_arg(args, int);
        if(val > largest)
            largest = val;
    }
    va_end(args);
    return largest;
}

// 17. Variable-length argument: Concatenate strings.
// Here we assume the strings are passed as const char*.
string concatStrings(int count, ...) {
    string result;
    va_list args;
    va_start(args, count);
    for(int i = 0; i < count; i++){
        const char* s = va_arg(args, const char*);
        result += s;
    }
    va_end(args);
    return result;
}

// ==================== Recursive Functions ====================

// 18. Recursive GCD.
int gcdRecursive(int a, int b) {
    a = abs(a); b = abs(b);
    if(b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

// 19. Recursive factorial.
int factorialRecursive(int n) {
    if(n <= 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

// 20. Recursive Fibonacci.
int fibonacciRecursive(int n) {
    if(n <= 0) return 0;
    if(n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// 21. Recursive reverseString.
string reverseString(const string &str) {
    if(str.empty())
        return "";
    return reverseString(str.substr(1)) + str[0];
}

// 22. Recursive sum of natural numbers.
int sumOfNaturalNumbers(int n) {
    if(n <= 1)
        return n;
    return n + sumOfNaturalNumbers(n - 1);
}

// 23. Recursive power.
int powerRecursive(int base, int exp) {
    if(exp == 0)
        return 1;
    return base * powerRecursive(base, exp - 1);
}

// ==================== Passing Array & Reference to Functions ====================

// 24. Swap two numbers (pass-by-reference).
void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 25. Sum of all elements in an array.
int sumArray(int arr[], int size) {
    int total = 0;
    for(int i = 0; i < size; i++)
        total += arr[i];
    return total;
}

// 26. Find maximum element in an array.
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for(int i = 1; i < size; i++)
        if(arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

// 27. Find the second largest element in an array.
int findSecondLargest(int arr[], int size) {
    if(size < 2)
        return -1; // or error value
    int first = arr[0] > arr[1] ? arr[0] : arr[1];
    int second = arr[0] > arr[1] ? arr[1] : arr[0];
    for(int i = 2; i < size; i++){
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    return second;
}

// 28. Generate an array of n Fibonacci numbers using dynamic memory allocation.
int* generateFibonacci(int n) {
    if(n <= 0) return nullptr;
    int* fibArr = new int[n];
    fibArr[0] = 0;
    if(n > 1) {
        fibArr[1] = 1;
        for(int i = 2; i < n; i++)
            fibArr[i] = fibArr[i-1] + fibArr[i-2];
    }
    return fibArr;
}

// 29. Structure Student and display function.
struct Student {
    string name;
    int marks;
};

void displayStudents(const Student arr[], int size) {
    for(int i = 0; i < size; i++){
        cout << "Student " << i+1 << ": " << arr[i].name 
             << ", Marks: " << arr[i].marks << endl;
    }
}

// 30. Modify all elements of an array by multiplying them by 2 (using pass-by-reference for fixed-size array).
void doubleArray(int (&arr)[6]) {
    for (int &x : arr)
        x *= 2;
}

// ==================== Main Menu to Demonstrate All Functions ====================
void displayMenu() {
    cout << "\n==== Practice Assignment - Part 3 ====" << endl;
    cout << "1.  maxNumber" << endl;
    cout << "2.  factorial (iterative)" << endl;
    cout << "3.  reverseNumber" << endl;
    cout << "4.  sumOfDigits" << endl;
    cout << "5.  isPalindrome" << endl;
    cout << "6.  Fibonacci (iterative)" << endl;
    cout << "7.  gcd (iterative)" << endl;
    cout << "8.  Overloaded print()" << endl;
    cout << "9.  Calculator::sum()" << endl;
    cout << "10. Overloaded multiply()" << endl;
    cout << "11. Overloaded greet()" << endl;
    cout << "12. Overloaded area()" << endl;
    cout << "13. Overloaded concat()" << endl;
    cout << "14. Overloaded power()" << endl;
    cout << "15. Variable-length sum" << endl;
    cout << "16. Variable-length findLargest" << endl;
    cout << "17. Variable-length concatStrings" << endl;
    cout << "18. gcdRecursive" << endl;
    cout << "19. factorialRecursive" << endl;
    cout << "20. fibonacciRecursive" << endl;
    cout << "21. reverseString (recursive)" << endl;
    cout << "22. sumOfNaturalNumbers (recursive)" << endl;
    cout << "23. powerRecursive" << endl;
    cout << "24. swapNumbers" << endl;
    cout << "25. sumArray" << endl;
    cout << "26. findMax" << endl;
    cout << "27. findSecondLargest" << endl;
    cout << "28. generateFibonacci" << endl;
    cout << "29. displayStudents" << endl;
    cout << "30. doubleArray" << endl;
    cout << "31. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if(choice == 31) break;
        switch(choice) {
            case 1: {
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                cout << "Max is " << maxNumber(a, b) << endl;
                break;
            }
            case 2: {
                int n;
                cout << "Enter n for factorial: ";
                cin >> n;
                cout << "Factorial (iterative): " << factorial(n) << endl;
                break;
            }
            case 3: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Reversed number: " << reverseNumber(n) << endl;
                break;
            }
            case 4: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Sum of digits: " << sumOfDigits(n) << endl;
                break;
            }
            case 5: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << n << (isPalindrome(n) ? " is " : " is not ") << "a palindrome." << endl;
                break;
            }
            case 6: {
                int n;
                cout << "Enter n for Fibonacci: ";
                cin >> n;
                cout << "nth Fibonacci number: " << fibonacci(n) << endl;
                break;
            }
            case 7: {
                int a, b;
                cout << "Enter two numbers for gcd: ";
                cin >> a >> b;
                cout << "GCD: " << gcd(a, b) << endl;
                break;
            }
            case 8: {
                print("Hello, Overload!");
                print(12345);
                print("Answer is", 42);
                break;
            }
            case 9: {
                Calculator calc;
                cout << "Sum of 2 and 3: " << calc.sum(2, 3) << endl;
                cout << "Sum of 1.1, 2.2, 3.3: " << calc.sum(1.1, 2.2, 3.3) << endl;
                cout << "Sum of 5 and 2.5: " << calc.sum(5, 2.5f) << endl;
                break;
            }
            case 10: {
                cout << "multiply(3, 4) = " << multiply(3, 4) << endl;
                cout << "multiply(3, 2.5) = " << multiply(3, 2.5) << endl;
                cout << "multiply(1.1, 2.2, 3.3) = " << multiply(1.1f, 2.2f, 3.3f) << endl;
                break;
            }
            case 11: {
                greet();
                greet("Alice");
                greet("Bob", 30);
                break;
            }
            case 12: {
                cout << "Area of square (side 4): " << area(4) << endl;
                cout << "Area of rectangle (4 x 5): " << area(4,5) << endl;
                cout << "Area of circle (radius 3): " << area(3.0) << endl;
                break;
            }
            case 13: {
                cout << "Concat(\"Hello, \", \"World!\") = " << concat("Hello, ", "World!") << endl;
                cout << "Concat(123, \" apples\") = " << concat(123, " apples") << endl;
                break;
            }
            case 14: {
                cout << "power(2, 3) = " << power(2,3) << endl;
                cout << "power(2.5, 3) = " << power(2.5,3) << endl;
                break;
            }
            case 15: {
                cout << "Variable-length sum of (1,2,3,4,5): " << sumVar(5, 1,2,3,4,5) << endl;
                break;
            }
            case 16: {
                cout << "Largest of (10, 20, 5, 40, 15): " << findLargest(5, 10,20,5,40,15) << endl;
                break;
            }
            case 17: {
                cout << "Concatenated strings: " << concatStrings(3, "Hello, ", "variable ", "arguments!") << endl;
                break;
            }
            case 18: {
                int a, b;
                cout << "Enter two numbers for recursive gcd: ";
                cin >> a >> b;
                cout << "gcdRecursive: " << gcdRecursive(a, b) << endl;
                break;
            }
            case 19: {
                int n;
                cout << "Enter n for recursive factorial: ";
                cin >> n;
                cout << "factorialRecursive: " << factorialRecursive(n) << endl;
                break;
            }
            case 20: {
                int n;
                cout << "Enter n for recursive Fibonacci: ";
                cin >> n;
                cout << "fibonacciRecursive: " << fibonacciRecursive(n) << endl;
                break;
            }
            case 21: {
                string s;
                cout << "Enter a string to reverse: ";
                cin >> s;
                cout << "Reversed string: " << reverseString(s) << endl;
                break;
            }
            case 22: {
                int n;
                cout << "Enter n for sum of natural numbers: ";
                cin >> n;
                cout << "Sum of first " << n << " natural numbers: " << sumOfNaturalNumbers(n) << endl;
                break;
            }
            case 23: {
                int base, exp;
                cout << "Enter base and exponent for recursive power: ";
                cin >> base >> exp;
                cout << "powerRecursive: " << powerRecursive(base, exp) << endl;
                break;
            }
            case 24: {
                int x, y;
                cout << "Enter two numbers to swap: ";
                cin >> x >> y;
                swapNumbers(x, y);
                cout << "After swap: x = " << x << ", y = " << y << endl;
                break;
            }
            case 25: {
                int n;
                cout << "Enter size of array: ";
                cin >> n;
                int* arr = new int[n];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++)
                    cin >> arr[i];
                cout << "Sum of array elements: " << sumArray(arr, n) << endl;
                delete[] arr;
                break;
            }
            case 26: {
                int n;
                cout << "Enter size of array: ";
                cin >> n;
                int* arr = new int[n];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++)
                    cin >> arr[i];
                cout << "Maximum element: " << findMax(arr, n) << endl;
                delete[] arr;
                break;
            }
            case 27: {
                int n;
                cout << "Enter size of array: ";
                cin >> n;
                int* arr = new int[n];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++)
                    cin >> arr[i];
                cout << "Second largest element: " << findSecondLargest(arr, n) << endl;
                delete[] arr;
                break;
            }
            case 28: {
                int n;
                cout << "Enter n to generate Fibonacci series: ";
                cin >> n;
                int* fibArr = generateFibonacci(n);
                cout << "Fibonacci series: ";
                for (int i = 0; i < n; i++)
                    cout << fibArr[i] << " ";
                cout << endl;
                delete[] fibArr;
                break;
            }
            case 29: {
                int n;
                cout << "Enter number of students: ";
                cin >> n;
                Student* students = new Student[n];
                for (int i = 0; i < n; i++) {
                    cout << "Enter name and marks for student " << i+1 << ": ";
                    cin >> students[i].name >> students[i].marks;
                }
                displayStudents(students, n);
                delete[] students;
                break;
            }
            case 30: {
                int arr[6];
                cout << "Enter 6 integers: ";
                for (int i = 0; i < 6; i++)
                    cin >> arr[i];
                doubleArray(arr);
                cout << "Array after doubling: ";
                for (int i = 0; i < 6; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;
            }
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    cout << "Exiting program." << endl;
    return 0;
}
