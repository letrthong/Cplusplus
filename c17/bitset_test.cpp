// https://www.programiz.com/cpp-programming/online-compiler/
// https://www.geeksforgeeks.org/cpp-bitset-and-its-application/
#include <bitset>
#include <iostream>
#include <string> 
using namespace std;
 
int main()
{
    // declaring an uninitialized bitset object
    bitset<8> uninitializedBitset;
 
    // initialization with decimal number
    bitset<8> decimalBitset(15);
 
    // initialization with binary string
    bitset<8> stringBitset(string("1111"));
 
    cout << "Uninitialized bitset: " << uninitializedBitset<< endl;
    cout << "Initialized with decimal: " << decimalBitset<< endl;
    cout << "Initialized with string: " << stringBitset<< endl;
   
    cout << " bitset test() " << decimalBitset.test(1) << endl;
    cout << " bitset test() " << decimalBitset.test(4) << endl;
    return 0;
}
