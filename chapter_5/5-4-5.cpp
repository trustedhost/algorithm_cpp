/* 행렬의 곱셈  */
/* programmers 12949 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<vector<int>> solution (vector<vector<int>> arr1, vector<vector<int>> arr2) {
    size_t arr1_row = arr1.size();
    size_t arr1_col = arr1[0].size();
    size_t arr2_row = arr2.size();
    size_t arr2_col = arr2[0].size();
    vector<vector<int>> answer(arr1_row, vector<int>(arr2_col));
    for (size_t i = 0; i < arr1_row; ++i) {
        for (size_t j = 0; j < arr2_col; ++j) {
            int val = 0;
            for (size_t k = 0; k < arr1_col; ++k) {
                val += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = val;
        }
    }
    
    return answer;
}

int main() {

    return 0;
}
