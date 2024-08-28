#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
/*   line 27 : set 을 vector 로 변환하여 선언하기! */

template <typename Iter>
void print_iter(Iter start, Iter end) {
    Iter itr = start;
    while (itr != end) {
        std::cout << *itr << " " ;
        itr++;
    }
}
std::vector<int> solution(std::vector<int> numbers){
    //pick two numbers and push it to the sum_set

    std::set<int> sum_set;
    for (auto itr = numbers.begin(); itr != numbers.end() - 1; ++itr) {
        int num1 = *itr;
        for (auto itr2 = itr+ 1; itr2 != numbers.end(); ++itr2) {
            int num2 = *itr2;
            sum_set.insert(num1 + num2);
        }
    }
    //print_iter(sum_set.begin(), sum_set.end());
    std::vector<int> answer(sum_set.begin(), sum_set.end());
    return answer;
}
int main() {
    std::vector<int> int_vec = {5, 0, 2, 7};
    std::vector<int> answer = solution(int_vec);
    print_iter(answer.begin(), answer.end());
    return 0;
}
