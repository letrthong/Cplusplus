#include <iostream>
#include <memory>
#include <vector>

 
int main() {
    auto ptr1 = std::make_unique<int>(10);

// OK: Chuyển quyền sở hữu từ ptr1 sang ptr2
   auto ptr2 = std::move(ptr1);
   
      // Cách kiểm tra an toàn:
    if (ptr1) {
        // Không bao giờ chạy vào đây
    } else {
        std::cout << "ptr1 da rong! \n"; 
    }
    
    if(ptr2){
        std::cout << "Gia tri la: " << *ptr2 << "\n";
        
        ptr2.reset(); 
        if(ptr2){
          std::cout << "Gia tri la: " << *ptr2 << "\n";
        }
    }
    return 0;
}
