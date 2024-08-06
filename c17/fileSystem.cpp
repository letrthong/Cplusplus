#include <fstream> 
#include <iostream> 
#include <string> 
#include <sstream> 
#include <fstream> 
 
using namespace std; 
  
int main() 
{   
    
    int x = 10;
    int y = 20;
    bool status = true;
    ofstream   ofs;
    ofs.open("/tmp/abc.txt");
    ofs << x << "   "  <<  y << " " << status ;
    ofs.close();
            
            
    // Open the file "abc.txt" for reading 
    int a = 0;
    int b = 0;
    bool c;
    ifstream ifs("/tmp/abc.txt"); 
    cout<<"read file"  << endl; 
    
     ifs >> a  >> b >>  c;
   
    ifs.close(); 
    
    
    cout<<"a=" <<  a  << endl; 
    cout<<"b=" << b << endl; 
    cout<<"c=" << c << endl; 
    
    if( c== true) {
        cout<<" C= true";
    }
    return 0; 
}
