#include <iostream>
#include<conio.h>
using namespace std;

struct GroceryItem
{
    double weight;
    int cost;
    double costPerKg;
};

void swap(GroceryItem& a, GroceryItem& b)
{
    GroceryItem temp = a;
    a = b;
    b = temp;
}

int main()
{
    const int bagCapacity = 10;
    int numItems;

    cout << "Enter the number of grocery items: ";
    cin >> numItems;

    GroceryItem groceries[numItems];

    cout << "Enter the details of each item:" << endl;
    for (int i = 0; i < numItems; ++i)
        {
            cout << "Item " << i + 1 << ":" << endl;
            cout << "Weight (kg): ";
            cin >> groceries[i].weight;
            cout << "Cost (tk): ";
            cin >> groceries[i].cost;
            groceries[i].costPerKg = groceries[i].cost / groceries[i].weight;
    }

    for (int i = 0; i < numItems - 1; ++i)
        {
            int minIndex = i;
            for (int j = i + 1; j < numItems; ++j)
            {
                if (groceries[j].costPerKg < groceries[minIndex].costPerKg)
                {
                    minIndex = j;
                }
            }
            swap(groceries[i], groceries[minIndex]);
        }

    double totalWeight = 0;
    int totalCost = 0;
    int numNotes = 0;
    int notes[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int notes_count[sizeof(notes) / sizeof(notes[0])] = {0};

    cout << "Items bought: " << endl;

    for (int i = 0; i < numItems; ++i)
        {
            if (totalWeight + groceries[i].weight <= bagCapacity)
            {
                totalWeight += groceries[i].weight;
                totalCost += groceries[i].cost;
                numNotes += (groceries[i].cost / 1000);
                cout << groceries[i].weight << "kg - " << groceries[i].cost << "tk" << endl;
            }
        }

    int remaining_cost = totalCost;
    for (size_t i = 0; i < sizeof(notes) / sizeof(notes[0]); ++i)
        {
            notes_count[i] = remaining_cost / notes[i];
            remaining_cost %= notes[i];
        }

        cout << "Total cost: " << totalCost << "tk" << endl;
        int totalNotes = 0;
        for (size_t i = 0; i < sizeof(notes_count) / sizeof(notes_count[0]); ++i)
            {
                totalNotes += notes_count[i];
            }

        cout << "Total number of notes used: " << totalNotes << endl;

    getch();
}
