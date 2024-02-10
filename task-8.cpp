#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int arraySize = 6;
    int numbers[arraySize] = {12, 11, 13, 5, 6, 7};

    cout << "Original Array: ";
    displayArray(numbers, arraySize);

    insertionSort(numbers, arraySize);

    cout << "Sorted Array: ";
    displayArray(numbers, arraySize);

    return 0;
}

