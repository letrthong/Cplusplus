#include <iostream>
#include <memory>
#include <vector>

class User {
public:
    std::string name;
    User(std::string n) : name(n) { std::cout << "User Created: " << name << "\n"; }
    ~User() { std::cout << "User Destroyed: " << name << "\n"; }
};

int main() {
    // 1. Create a simple unique_ptr (Preferred)
    auto userPtr = std::make_unique<User>("Alice");

    // 2. Create a unique_ptr to an array of 5 integers
    auto arrPtr = std::make_unique<int[]>(5); 
    arrPtr[0] = 10; // Use it like a normal array

    // 3. Move ownership to a vector
    std::vector<std::unique_ptr<User>> users;
    users.push_back(std::move(userPtr)); // userPtr is now empty (nullptr)

    return 0;
}
