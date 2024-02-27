#include <iostream>
#include<conio.h>
using namespace std;


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
}


void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
}

int main()
{
    int n;
    cout << "Enter The Number of Elements In The Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " Elements:" << endl;
    for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

    cout << "Original Array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    getch();
}
