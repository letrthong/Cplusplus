
#include <iostream>
using namespace std;
#include <fstream>
#include <filesystem>

namespace fs =  std::filesystem;
using std::filesystem::directory_iterator;


int main(){
    cout<< "hello world "<<endl;
    std::string path ="/opt";
    for(const auto &file: directory_iterator(path)){
        std::string file_path=  file.path();
        if(  fs::is_directory(file_path)  ){
            cout<<"dir ="<< file.path()<<endl;
        } else{
             cout<<"file="<< file.path()<<endl;
        }
    } 
    return 0;
}