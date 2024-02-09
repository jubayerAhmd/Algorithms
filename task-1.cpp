#include <iostream>

int main() {
    int birthYear, currentYear;
    const int secondsInMinute = 60;
    const int minutesInHour = 60;
    const int hoursInDay = 24;
    const int daysInYear = 365;

    std::cout << "Enter your birth year: ";
    std::cin >> birthYear;

    std::cout << "Enter the current year: ";
    std::cin >> currentYear;

    int ageInYears = currentYear - birthYear;
    long long ageInSeconds = static_cast<long long>(ageInYears) * daysInYear * hoursInDay * minutesInHour * secondsInMinute;

    std::cout << "Your age in seconds is: " << ageInSeconds << " seconds" << std::endl;

    return 0;
}
