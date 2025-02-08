#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to find the next prime number
int nextPrime(int n) {
    while (!isPrime(++n));
    return n;
}

// Function to find factors of a number
void findFactors(int n) {
    cout << "Factors of " << n << ": ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cout << i << " ";
    }
    cout << endl;
}

// Function to reverse an array
void reverseArray(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
    cout << "Reversed Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// Function to find second largest and second smallest elements
void secondLargestSmallest(vector<int> arr) {
    sort(arr.begin(), arr.end());
    cout << "Second Smallest: " << arr[1] << "\nSecond Largest: " << arr[arr.size() - 2] << endl;
}

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    string filtered = "";
    for (char ch : str) if (isalnum(ch)) filtered += tolower(ch);
    string reversedStr = filtered;
    reverse(reversedStr.begin(), reversedStr.end());
    return filtered == reversedStr;
}

// Function to count character frequency
void countFrequency(string str) {
    map<char, int> freq;
    for (char ch : str) if (isalpha(ch)) freq[tolower(ch)]++;
    cout << "Character Frequencies:\n";
    for (auto p : freq) cout << p.first << ": " << p.second << endl;
}

// Function to replace vowels
string replaceVowels(string str, char replacement) {
    for (char& ch : str) if (string("aeiouAEIOU").find(ch) != string::npos) ch = replacement;
    return str;
}

// Function to generate a spiral matrix
void generateSpiral(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int num = 1, top = 0, left = 0, bottom = n - 1, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) matrix[top][i] = num++;
        top++;
        for (int i = top; i <= bottom; i++) matrix[i][right] = num++;
        right--;
        for (int i = right; i >= left; i--) matrix[bottom][i] = num++;
        bottom--;
        for (int i = bottom; i >= top; i--) matrix[i][left] = num++;
        left++;
    }
    for (auto row : matrix) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }
}

// Function to rotate a matrix 90 degrees clockwise
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
    for (auto row : matrix) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Check if a number is prime and find the next prime\n";
        cout << "2. Find factors of a number\n";
        cout << "3. Reverse an array\n";
        cout << "4. Find second largest and second smallest elements in an array\n";
        cout << "5. Check if a string is a palindrome\n";
        cout << "6. Count character frequency in a string\n";
        cout << "7. Replace vowels in a string\n";
        cout << "8. Generate a spiral matrix\n";
        cout << "9. Rotate a matrix 90 degrees clockwise\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                if (isPrime(n)) cout << n << " is a prime number. Next prime: " << nextPrime(n) << endl;
                else cout << n << " is not a prime number.\n";
                break;
            }
            case 2: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                findFactors(n);
                break;
            }
            case 3: {
                int size;
                cout << "Enter array size: ";
                cin >> size;
                vector<int> arr(size);
                cout << "Enter array elements: ";
                for (int& num : arr) cin >> num;
                reverseArray(arr);
                break;
            }
            case 4: {
                int size;
                cout << "Enter array size: ";
                cin >> size;
                vector<int> arr(size);
                cout << "Enter array elements: ";
                for (int& num : arr) cin >> num;
                secondLargestSmallest(arr);
                break;
            }
            case 5: {
                string str;
                cout << "Enter a string: ";
                cin.ignore();
                getline(cin, str);
                cout << "Palindrome: " << (isPalindrome(str) ? "Yes" : "No") << endl;
                break;
            }
            case 6: {
                string str;
                cout << "Enter a string: ";
                cin.ignore();
                getline(cin, str);
                countFrequency(str);
                break;
            }
            case 7: {
                string str;
                char replacement;
                cout << "Enter a string: ";
                cin.ignore();
                getline(cin, str);
                cout << "Enter a replacement character: ";
                cin >> replacement;
                cout << "String with vowels replaced: " << replaceVowels(str, replacement) << endl;
                break;
            }
            case 8: {
                int n;
                cout << "Enter matrix size: ";
                cin >> n;
                cout << "Spiral Pattern:\n";
                generateSpiral(n);
                break;
            }
            case 9: {
                int n;
                cout << "Enter matrix size: ";
                cin >> n;
                vector<vector<int>> matrix(n, vector<int>(n));
                cout << "Enter matrix elements:\n";
                for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> matrix[i][j];
                cout << "Rotated Matrix:\n";
                rotateMatrix(matrix);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}