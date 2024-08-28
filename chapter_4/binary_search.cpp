#include <iostream>
#include <algorithm>
#include <vector>

//target must be already sorted before binray_search.
int main() {
    std::vector<int> int_vec = {1, 2, 3, 4, 5};

    std::cout << binary_search(int_vec.begin(), int_vec.end(), 3) << '\n'; // 1
    std::cout << binary_search(int_vec.begin(), int_vec.end(), 7) << '\n'; // 0

    return 0;
}
