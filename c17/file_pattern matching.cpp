/**
In this example:

glob("*.txt", GLOB_TILDE, nullptr, &glob_result); searches for all .txt files in the current directory.
glob_result.gl_pathc gives the count of matched paths.
glob_result.gl_pathv is an array of matched path strings.
globfree(&glob_result); frees the memory allocated by glob.
Feel free to ask if you need more details or have any other questions!
**/


/******************************************************************************
* C++ 17
* https://www.onlinegdb.com/online_c++_compiler#
*******************************************************************************/

#include <iostream>
#include <glob.h>

int main() {
    glob_t glob_result;

     // searches for all .txt files in the current directory.
    glob("*.txt", GLOB_TILDE, nullptr, &glob_result);

    for (size_t i = 0; i < glob_result.gl_pathc; ++i) {
        std::cout << glob_result.gl_pathv[i] << std::endl;
    }

    globfree(&glob_result);
    return 0;
}
