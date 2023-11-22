#include <iostream>
#include "keycheck.hpp"

int main()
{
    system("clear");
    
    std::string key = "RQ7siQh4U6h0";

    std::cout << "Your key: " << key << "\n\n";
    
    kc_log::KeyCheck kc; kc.checkKey(key);

    std::cout << std::endl;
    return 0;
}