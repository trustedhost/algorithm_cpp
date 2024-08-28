#include <iostream>
#include <algorithm>
#include <vector>

template <typename Iter>
void print_vec(Iter begin, Iter end) {
    Iter itr = begin;
    while (itr != end) {
        std::cout << *itr << '\n';
        itr++;
    }
}

bool compare(int a, int b) {
    return a < b;
}

int main() {
    std::vector<int> int_vec = {1, 4, 6, 22,33,5};

    print_vec(int_vec.begin(), int_vec.end());
    
    std::string str(20, '*');
    std::cout << "after sort" << '\n' << str <<  std::endl;
    sort(int_vec.begin(), int_vec.end());
    print_vec(int_vec.begin(), int_vec.end());

    std::cout << "after sort(reversed)" << '\n' << str <<  std::endl;
    sort(int_vec.rbegin(), int_vec.rend());
    print_vec(int_vec.begin(), int_vec.end());

    
    std::cout << "after sort(function)" << '\n' << str <<  std::endl;
    sort(int_vec.begin(), int_vec.end(), compare);
    print_vec(int_vec.begin(), int_vec.end());

}
