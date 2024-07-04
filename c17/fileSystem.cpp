// https://www.programiz.com/cpp-programming/online-compiler/
#include <fstream> 
#include <iostream> 
#include <string> 
#include <sstream> 
#include <fstream> 
 
using namespace std; 
  
int main() 
{   
    
    int countryCode = 10;
    int networkCode = 20;
    ofstream   ofs;
    ofs.open("/tmp/abc.txt");
    ofs << countryCode << "   "  <<  networkCode ;
    ofs.close();
            
            
    // Open the file "abc.txt" for reading 
    int a = 0;
    int b = 0;
    
    ifstream ifs("/tmp/abc.txt"); 
    cout<<"read file"  << endl; 
    
     ifs >> a  >> b;
   
    ifs.close(); 
    
    
    cout<<"a=" <<  a  << endl; 
    cout<<"b=" << b << endl; 
    return 0; 
}
