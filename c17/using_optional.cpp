
// https://www.programiz.com/cpp-programming/online-compiler/
// Using C++17 std::optional
// https://www.cppstories.com/2018/05/using-optional/
#include <iostream>

#include <vector>
#include <algorithm>  
#include <string>
#include <optional>

using namespace std;

class  MaxMin{
 public:
       void setMax(double value){
           mMax= value;
       }
       
       void setMin(double value){
           mMin= value;
       }
       
       std::optional<double> isValidNumber(double number){
          std::optional<double> ret = std::nullopt;
           if(mMax && mMin){
               if(number <= mMax && number >= mMin ){
                    ret = number;
               }
           }
           return ret;
       }
       
 private: 
         std::optional<double> mMin = std::nullopt;
        std::optional<double> mMax = std::nullopt;
};


int main() {
     MaxMin maxMix;
     maxMix.setMin(4);
     maxMix.setMax(10);
     
     std::optional<double> number =  maxMix.isValidNumber(5);
     if(number){
         std::cout<<   std::to_string(*number) ;
     }
  
    return 0;
}
