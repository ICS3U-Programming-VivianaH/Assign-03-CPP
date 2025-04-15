// Copyright 2025 Viviana Hurtado
// Created by: Viviana Hurtado
// Date: March 7, 2025
// This program calculates the bonus based on the experience

#include <cmath>
#include <iostream>
#include <string>

int main() {
    // Welcome message
    std::cout << "Welcome!\nWe will help you calculate your bonus."
              << std::endl;

    // Asking for salary and years
    std::string salary_input, years_input;
    double salary = 0.0;
    int years = 0;

    std::cout << "Enter your salary: ";
    std::cin >> salary_input;
    std::cout << "How many years have you been working?: ";
    std::cin >> years_input;

    // Input TryCatch
    try {
        salary = std::stod(salary_input);  // Accepts decimals
        years = std::stoi(years_input);
    } catch (...) {
        std::cout << "Invalid input. Please enter numbers for salary and years."
                  << std::endl;
    }

    // TryCatch salary and years
    if (salary <= 0 || years < 0) {
        std::cout << "Salary must be more than 0";
        std::cout << "and years must not be negative."
                  << std::endl;
    }

    // Asking for performance
    std::string performance_input;
    int performance = 0;
    std::cout << "How would you rate your performance from 1 to 3,\n"
              << "1 meaning low and 3 meaning high?: ";
    std::cin >> performance_input;

    // TryCatch input
    try {
        performance = std::stoi(performance_input);
        if (performance < 1 || performance > 3) {
            throw std::invalid_argument("Invalid performance value");
        }
    } catch (...) {
        std::cout << "Please enter 1, 2, or 3 for performance rating."
                  << std::endl;
    }

    // Bonus Calculation
    if (years < 5) {
        // Less than 5 years
        int wait_years = 5 - years;
        std::cout << "You need to wait " << wait_years
                  << " more year(s) to get a bonus." << std::endl;
        std::cout << "Thanks for starting to work with us!" << std::endl;
    } else {
        // Calculate base bonus
        double bonus = 0.0;
        if (years < 10) {
            bonus = salary * 0.05;  // Between 5-9 years: 5% bonus
            std::cout << "You're becoming a valued team member!" << std::endl;
        } else {
            bonus = salary * 0.10;  // 10 years or more: 10% bonus
            std::cout << "You're a senior employee. Thank you for your loyalty!"
                      << std::endl;
        }

        // Performance bonus
        switch (performance) {
            case 3:
                bonus *= 1.2;
                break;
            case 2:
                bonus *= 0.8;
                break;
            case 1:
                std::cout << "You do not get a performance bonus" << std::endl;
                break;
        }

        // Round to 2 decimal places
        bonus = std::round(bonus * 100) / 100;
        std::cout << "Your bonus is: $" << bonus << std::endl;
    }

    // End message
    std::cout << "Thanks for being part of our company." << std::endl;
}
