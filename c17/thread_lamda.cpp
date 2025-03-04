#include <iostream>
#include <thread>
#include <chrono>

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
    //t.join();
    
    /*
    *In C++, the detach function is used with threads to allow the thread to run independently
    * from the thread that created it. When you detach a thread, it continues to execute even
    * after the main thread has finished, and it becomes a "detached thread." This means that 
    * the thread is no longer joinable, and you cannot wait for it to finish using join.
    */
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    
    
    

    return 0;
}
