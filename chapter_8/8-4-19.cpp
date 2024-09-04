#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

template <typename Iter>
void print_vec(Iter begin, Iter end) {
    Iter itr = begin;
    while(itr != end) {
        std::cout << std::boolalpha << *itr << ' ';
        itr++;
    }
    std::cout << std::endl;
}
int hash(std::string str) {
    long long  hash = 0;
    for(int i = 0; i < str.length(); ++i) {
        hash += ((int)str[i] * (31)^i) % 1000000007;
        std::cout << hash << '\n';
    }
    return hash;
}

std::vector<bool> solution(std::vector<std::string> string_list, std::vector<std::string> query_list) {
    std::vector<bool> answer(query_list.size());
    std::unordered_set<int> hashes;
    for (const auto& elem : string_list) {
        hashes.insert(hash(elem));
    }
    
    for (int i = 0; i < query_list.size(); ++i) {
        bool found = (hashes.find(hash(query_list[i])) != hashes.end());
        answer[i] = found;
    }
    return answer;
}

int main() {
    std::vector<std::string> string_list = {"apple", "banana", "cherry"};
    std::vector<std::string> query_list = {"banana", "kiwi"};
    std::vector<bool> answer = solution(string_list, query_list);
    print_vec(answer.begin(), answer.end());
    return 0;
}
