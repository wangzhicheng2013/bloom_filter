#include <iostream>
#include "bloom_filter.hpp"
int main() {
    bloom_filter<>bf;
    bf.set("123abc");
    std::cout << bf.test("123abc") << std::endl;
    bf.set("123abaAAc");
    std::cout << bf.test("123abaAAc") << std::endl;
    std::cout << bf.test("1023abaAAc") << std::endl;
    
    return 0;
}