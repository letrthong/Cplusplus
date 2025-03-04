// https://onecompiler.com/cpp
#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <chrono>

class MyClass {
public:
    MyClass() {
        hFile.open("/tmp/example.txt", std::ios::out | std::ios::app);
    }

    ~MyClass() {
        if (hFile.is_open()) {
            hFile.close();
        }
    }

    void writeText(const std::string& val) {
        if (hFile.is_open()) {
            hFile << val << std::endl;
        }
    }

    void printValue() const {
         std::ifstream inFile("/tmp/example.txt");
        std::string line;
        if (inFile.is_open()) {
            while (std::getline(inFile, line)) {
                std::cout << line << std::endl;
            }
            inFile.close();
        }
    }

private:
    std::ofstream hFile;
};

void testThread()
{
    MyClass obj;
    obj.writeText("12");
  
    // Create a thread that runs a lambda function capturing the object by reference
    std::thread t([&obj] {
        obj.printValue();
    });

    // Wait for the thread to finish
    t.detach();
}


int main() {
    
    testThread();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}
