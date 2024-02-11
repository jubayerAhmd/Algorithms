#include <iostream>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int startYear, endYear;

    std::cout << "Enter the starting year: ";
    std::cin >> startYear;

    std::cout << "Enter the ending year: ";
    std::cin >> endYear;

    bool leapYearFound = false;

    std::cout << "Leap years between " << startYear << " and " << endYear << ": ";

    for (int year = startYear; year <= endYear; ++year) {
        if (isLeapYear(year)) {
            std::cout << year << " ";
            leapYearFound = true;
        }
    }

    if (!leapYearFound) {
        std::cout << "No leap years found.";
    }

    std::cout << std::endl;

    return 0;
}

