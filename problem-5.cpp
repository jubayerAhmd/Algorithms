#include <iostream>

int main() {
    const int numItems = 5;
    const int numDays = 7;

    double salesUnitPrice, salesQuantity;
    double totalSales = 0.0;
    double averageSalesQuantity = 0.0;

    for (int day = 1; day <= numDays; ++day) {
        std::cout << "Day " << day << ":" << std::endl;

        for (int item = 1; item <= numItems; ++item) {

            do {
                std::cout << "Enter sales unit price for item " << item << ": ";
                std::cin >> salesUnitPrice;

                if (salesUnitPrice < 0 || salesUnitPrice > 1000) {
                    std::cout << "Invalid input. Please enter a value between 0 and 1000." << std::endl;
                }
            } while (salesUnitPrice < 0 || salesUnitPrice > 1000);

            do {
                std::cout << "Enter sales quantity for item " << item << ": ";
                std::cin >> salesQuantity;

                if (salesQuantity < 0 || salesQuantity > 1000) {
                    std::cout << "Invalid input. Please enter a value between 0 and 1000." << std::endl;
                }
            } while (salesQuantity < 0 || salesQuantity > 1000);

            totalSales += salesUnitPrice * salesQuantity;

            averageSalesQuantity += salesQuantity;
        }
    }


    averageSalesQuantity /= (numItems * numDays);

    std::cout << "\nTotal Sales for Seven Days: $" << totalSales << std::endl;
    std::cout << "Average Sales Quantity: " << averageSalesQuantity << " units" << std::endl;

    return 0;
}
