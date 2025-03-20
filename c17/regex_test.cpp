//https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <regex>
#include <string>

bool isValidPhoneNumber(const std::string& phoneNumber) {
    // Define the regex pattern for a phone number
    std::regex pattern(R"(\+?\d{1,4}[-.\s]?\(?\d{1,4}\)?[-.\s]?\d{1,4}[-.\s]?\d{1,9})");

    // Check if the phone number matches the pattern
    return std::regex_match(phoneNumber, pattern);
}

int main() {
    std::string phoneNumber;

    std::cout << "Enter a phone number: ";
    std::getline(std::cin, phoneNumber);

    if (isValidPhoneNumber(phoneNumber)) {
        std::cout << "The phone number is valid." << std::endl;
    } else {
        std::cout << "The phone number is not valid." << std::endl;
    }

    return 0;
}
