#include <iostream>
//1차원 배열, 2차원 배열의 선언과 접근
int main() {
    int arr1[5] = {1, 2}; // {1, 2, 0, 0, 0}
    int arr2[5] = {}; // {0, 0, 0, 0, 0}

    int arr3[3][4] = {{1, 2, 3, 4,}, {5, 6, 7, 8}, {9, 10, 11, 12},};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr3[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
