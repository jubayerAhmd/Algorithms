#include <iostream>

using namespace std;

int main()
{
    const int arraySize = 3;
    int numbers[arraySize];

    cout << "_____ENTER " << arraySize << " NUMBERS_____" << endl;

    for (int i = 0; i < arraySize; ++i)
        {
            cout<< "Enter Number " << i + 1 << ": ";
            cin>> numbers[i];
        }

    int sumOdd = 0, sumEven = 0;

    for (int i = 0; i < arraySize; ++i)
        {
            if (numbers[i] % 2 == 0)
                {
                    cout << numbers[i] << " is even." << endl;
                    sumEven += numbers[i];
                }

            else
                {
                    cout << numbers[i] << " is odd." << endl;
                    sumOdd += numbers[i];
                }
    }

    cout << "Sum of odd numbers: " << sumOdd << endl;
    cout << "Sum of even numbers: " << sumEven << endl;

    return 0;
}


