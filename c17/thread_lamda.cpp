#include <iostream>
#include <thread>

class MyClass {
public:
    void setValue(int val) {
        value = val;
    }

    void printValue() const {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value = 0;
};

int main() {
    MyClass obj;
    obj.setValue(12);
    // Create a thread that runs a lambda function capturing the object by reference
    std::thread t([&obj] {
        obj.printValue();
        obj.setValue(42);
        obj.printValue();
    });

    // Wait for the thread to finish
    t.join();

    return 0;
}
