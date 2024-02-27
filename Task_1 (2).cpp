#include <iostream>
#include<conio.h>
using namespace std;

int main() {
    int amount;
    cout << "Enter the amount to be paid: ";
    cin >> amount;

    int notes[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2};
    int count = 0;

    for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++)
        {
            if (amount >= notes[i])
            {
                int numNotes = amount / notes[i];
                count += numNotes;
                amount -= numNotes * notes[i];
            }
        }

    cout << "Minimum number of notes required: " << count << endl;

    getch();
}
