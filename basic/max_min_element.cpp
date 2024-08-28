#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> int_vec = {1, 2, 3, 4, 5};
    auto max_iter =  max_element(int_vec.begin(), int_vec.end());
    auto min_iter =  min_element(int_vec.begin(), int_vec.end());

    std::cout << "max : " << *max_iter << '\n';
    std::cout << "min : " << *min_iter << '\n';
    return 0;
}
