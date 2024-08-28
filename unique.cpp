#include <iostream>
#include <algorithm>
#include <vector>

template <typename Iter>
void print_vec(Iter begin, Iter end) {
    Iter itr = begin;
    while (itr != end) {
        std::cout << *itr;
        itr++;
    }
}

int main() {
    std::vector<int> int_vec = {1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4};

    auto newEnd = unique(int_vec.begin(), int_vec.end());
   
    print_vec(int_vec.begin(), newEnd);
    
    std::cout << '\n';

    print_vec(int_vec.begin(), int_vec.end());
    
}
