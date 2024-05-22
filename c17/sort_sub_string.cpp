// Online C++ compiler to run C++ program online
#include <iostream>

#include <vector>
#include <algorithm>  
#include <string>
using namespace std;


std::string solution(std::string &S) {
    // Implement your solution here
    std::vector<int> v;
 
    for(int i = 0 ; i < S.length(); i++){
        v.push_back( int(S[i] - 48) );
    }
 
    std::sort(v.begin(), v.end());
    std::string result = "";
     if( S.length() == 0 || S.length() == 1 ){
         return result;
     }
   
    result = std::to_string(  v[v.size() -1 ]);
    std::string sub = "";
 
   
    for(int i = v.size() -2  ; i > 1; i= i - 2){
       if(v[i] == v[i-1] && v[i] !=0){
           sub = std::to_string(  v[i]);
           break;
       }
    }
    result = sub + result + sub;
    return result;
}

int main() {
    // Write C++ code here
    std::string input ="98738";
    std::string data = solution(input);
    std::cout << data;
 
    return 0;
}

// https://www.programiz.com/cpp-programming/online-compiler/
