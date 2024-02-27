#include <iostream>
#include<conio.h>
using namespace std;

int main() {
    int first = 1, second = 2, next, n = 20;

    cout << "First 20 house numbers in the area:" << endl;
    cout << first << " " << second << " ";

    for (int i = 2; i < n; ++i) {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }

    cout << "\n\nThe 18th house number in the area is: " << next << endl;

    getch();
}
