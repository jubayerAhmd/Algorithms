#include <iostream>

using namespace std;

int linearSearch(const int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int binarySearch(const int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int search(const int arr[], int size, int key, int (*searchFunction)(const int[], int, int)) {
    return searchFunction(arr, size, key);
}

int main() {
    const int arraySize = 8;
    int numbers[arraySize] = {2, 4, 6, 8, 10, 12, 14, 16};

    int searchKey;
    int choice;

    cout << "Choose a searching algorithm:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    int (*searchFunction)(const int[], int, int);

    switch (choice) {
        case 1:
            searchFunction = linearSearch;
            break;

        case 2:
            searchFunction = binarySearch;
            break;

        default:
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            return 1;
    }

    cout << "Enter the number to search: ";
    cin >> searchKey;

    int result = search(numbers, arraySize, searchKey, searchFunction);

    if (result != -1) {
        cout << "Element " << searchKey << " found at index " << result << endl;
    } else {
        cout << "Element " << searchKey << " not found in the array." << endl;
    }

    return 0;
}

