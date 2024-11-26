#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function for Binary Search
int BinarySearch(vector<int> &numbers, int key) {
    int start = 0;
    int end = numbers.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // Avoid potential overflow
        if (numbers[mid] == key) {
            return mid; // Key found
        } else if (numbers[mid] < key) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }
    return -1; // Key not found
}

int main() {
    int n, key;

    // Get the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Check for valid size
    if (n <= 0) {
        cout << "Invalid size. The array must have at least one element." << endl;
        return 1;
    }

    // Get the elements from the user
    vector<int> numbers(n);
    cout << "Enter " << n << " elements (must be sorted): ";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Optional: Ensure the array is sorted
    if (!is_sorted(numbers.begin(), numbers.end())) {
        cout << "Error: The array is not sorted. Sorting it now..." << endl;
        sort(numbers.begin(), numbers.end());
        cout << "Sorted array: ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Get the key to search for
    cout << "Enter the number to search: ";
    cin >> key;

    // Perform Binary Search and output the result
    int binary_result = BinarySearch(numbers, key);
    if (binary_result != -1) {
        cout << "Number found at index: " << binary_result << endl;
    } else {
        cout << "Number not found" << endl;
    }

    return 0;
}
