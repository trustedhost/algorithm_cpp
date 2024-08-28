#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

std::vector<int> solution(std::vector<int> arr) {
    std::vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());
    return sorted;
}

void bubble_sort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}
template <typename Iter>
void print_vec(Iter begin, Iter end) {
    Iter itr = begin;
    while (itr != end) {
        std::cout << *itr << ' ';
        itr++;
    }
}
int main() {
    std::vector<int> vec(30000);
    for (int i = 0; i < 30000; ++i) {
        vec[i] = i + 1;
    }
    
    clock_t startStdSort = clock();
    //using sort - O(NlogN)
    std::vector<int> answer = solution(vec);
    //print_vec(answer.begin(), answer.end());
    clock_t endStdSort = clock();
    double timeStdSort = double(endStdSort - startStdSort) / CLOCKS_PER_SEC;

    clock_t startBubbleSort = clock();
    bubble_sort(vec);
    //print_vec(vec.begin(), vec.end());
    clock_t endBubbleSort = clock();
    double timeBubbleSort = double(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC;

    std::cout << "std sort : " << timeStdSort << '\n';
    std::cout << "bubble sort : " << timeBubbleSort << '\n';
}
