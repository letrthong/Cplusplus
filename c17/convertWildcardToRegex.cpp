#include <iostream>
#include <regex>
#include <string>

std::regex convertWildcardToRegex(const std::string& wildcard) {
    // Escape special regex characters and replace wildcard '*' with '.*'
    std::string regexPattern = std::regex_replace(wildcard, std::regex(R"(\*)"), R"(.*)");
    return std::regex(regexPattern);
}

int main() {
    std::string wildcardPattern = "*abc";
    std::regex regexPattern = convertWildcardToRegex(wildcardPattern);

    std::string testString = "123abc";
    if (std::regex_match(testString, regexPattern)) {
        std::cout << "The string matches the pattern." << std::endl;
    } else {
        std::cout << "The string does not match the pattern." << std::endl;
    }
    
    testString = "1bc";
    if (std::regex_match(testString, regexPattern)) {
        std::cout << "The string matches the pattern." << std::endl;
    } else {
        std::cout << "The string does not match the pattern." << std::endl;
    }

    return 0;
}
