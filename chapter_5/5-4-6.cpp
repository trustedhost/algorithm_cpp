/* 42889  */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

template <typename Iter>
void print_vec(Iter begin, Iter end) {
    Iter itr = begin;
    while (itr != end) {
        std::cout << *itr << " ";
        itr++;
    }
}

bool compare(std::pair<int, double> a, std::pair<int, double> b){
    if( a.second == b.second )
        return a.first < b.first;
    return a.second > b.second;
}
std::vector<int> solution(int N, std::vector<int> stages) {
    std::vector<int> stuck_people(N + 2, 0); // stuck_num
    for (auto stage_num : stages) {
        stuck_people[stage_num] += 1;
    }
    std::vector<double> fail_rate(N + 1, 0);
    for(int i = 1; i <= N; ++i) {
        int pass_num = 0;
        for (int j = i + 1; j <= N + 1; ++j) {
            pass_num += stuck_people[j];
        }
        if (pass_num != 0) {
            fail_rate[i] = (double)(stuck_people[i]) / (double)(pass_num + stuck_people[i]);
        } else {
            if ( stuck_people[i] == 0 )
                fail_rate[i] = 0;
            else fail_rate[i] = 1;   
        }
    }
    std::vector<std::pair<int, double>> fail_pair;
    for (int i = 1; i <= N; ++i) {
        fail_pair.emplace_back(i, fail_rate[i]);
    }
    sort(fail_pair.begin(), fail_pair.end(), compare);
    
    std::vector<int> answer;
    for (auto elem : fail_pair) {
        answer.push_back(elem.first);
    }
    return answer;

}

