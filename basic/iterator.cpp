#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& o, std::vector<int> vec) {
    std::vector<int>::iterator itr = vec.begin();
    while (itr != vec.end()) {
        o << *itr;
        itr++;
    }
    return o;
}

void print_vec(std::vector<int> vec) {
    auto itr = vec.begin();
    for (; itr != vec.end(); ++itr) {
        std::cout << *itr;
    }
}

template <typename Iter>
void print_vec(Iter begin, Iter end) {
    auto itr = begin;
    for(; itr != end; itr++) {
        std::cout << *itr;
    }
}
int main() {
    std::vector<int> int_vec = {1, 2, 3};

    print_vec(int_vec);

    std::cout << int_vec << std::endl;
    
    print_vec(int_vec.begin(), int_vec.end());
    print_vec(int_vec.rbegin(), int_vec.rend());
   
}
