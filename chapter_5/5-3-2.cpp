#include <iostream>
#include <algorithm>
#include <vector>
/*  중복값을 제거하고 배열 데이터를 내림차순으로 정렬하는 solution. */
/* sort 함수를 사용하기 위해서는 반드시 정렬 되어있는 vector 를 사용한다. */
template <typename Iter>
void print_vec(Iter begin, Iter end) {
    Iter itr = begin;
    while (itr != end) {
        std::cout << *itr;
        itr++;
    }
}

std::vector<int> solution(std::vector<int> lst) {
    sort(lst.rbegin(), lst.rend());
    lst.erase(unique(lst.begin(), lst.end()), lst.end());
    return lst;
}

int main() {
    std::vector<int> int_vec = {2, 5, 2, 3, 5, 6, 3, 2};
    std::vector<int> answer = solution(int_vec);
    print_vec(answer.begin(), answer.end());
}
