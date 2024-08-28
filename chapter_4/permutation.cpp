#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print_vec(Iter start, Iter end) {
    Iter itr = start;
    while (itr != end) {
        std::cout << *itr << " ";
        itr++;
    }
}

int main() {
    std::vector<int> int_vec = {1, 2, 3, 4, 5};
    do {
        print_vec(int_vec.begin(), int_vec.end());
        std::cout << '\n';
    } while (next_permutation(int_vec.begin(), int_vec.end()));

    int_vec = {5, 4, 3, 2, 1};
    do {
        print_vec(int_vec.begin(), int_vec.end());
        std::cout << '\n';
    } while (prev_permutation(int_vec.begin(), int_vec.end()));

    
    print_vec(int_vec.begin(), int_vec.end());
    return 0;
}
