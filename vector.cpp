#include <iostream>
#include <vector>
template <typename T>
void print_2_dim_vec(T vector, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << vector[i][j] << " " ;
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<int> int_vec(4, 3);
    int row_num = 4;
    int col_num = 5;
    std::vector<std::vector<int>> two_dim_int_vec(row_num, std::vector<int>(col_num, 0));
    
    std::vector<std::vector<int>> vec = { 
            { 1, 2, 3},
            {2, 3, 4}
        };
    print_2_dim_vec(two_dim_int_vec, row_num, col_num);
    print_2_dim_vec(vec, vec.size(), vec[0].size());
    
}
