#include <iostream>
#include <string>

int main() {
    std::string str("Hello World!");
    str.replace(7, 4, "XXX");
    std::cout << str << std::endl;
}
