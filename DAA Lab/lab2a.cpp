#include <iostream>
#include <vector>

using namespace std;

// Function to perform Linear Search
int LinearSearch(const vector<int>& numbers, int key) {
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == key) {
            return i; // key found at index i.
        }
    }
    return -1; // key not found.
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

    // Create a vector and get the elements from the user
    vector<int> numbers(n);
    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Get the key to search for
    cout << "Enter the number to search: ";
    cin >> key;

    // Perform Linear Search and output the result
    int result = LinearSearch(numbers, key);
    if (result != -1) {
        cout << "Number found at index: " << result << endl;
    } else {
        cout << "Number not found" << endl;
    }

    return 0;
}
