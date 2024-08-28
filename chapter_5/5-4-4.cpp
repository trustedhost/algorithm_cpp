#include <iostream>
#include <vector>
#include <algorithm>

template <typename Iter>
void print_vec(Iter begin, Iter end) {
    Iter itr = begin;
    while (itr != end) {
        std::cout << *itr << " "; 
        itr++;
    }
}
std::vector<int> person1 = {1, 2, 3, 4, 5};
std::vector<int> person2 = {2, 1, 2, 3, 2, 4, 2, 5};
std::vector<int> person3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

std::vector<int> generate_answer_sheet(std::vector<int> person, int size) {
    std::vector<int> answer_sheet(size, 0);
    int repeat = static_cast<int>(size / person.size());
    int leftover = size % person.size();
    int index = 0;
    for (size_t i = 0; i < repeat; ++i) {
        for (size_t j = 0; j < person.size(); ++j) {
            answer_sheet[index] = person[j];
            index++;
        }
    }
    for (size_t i = 0; i < leftover; ++i) {
        answer_sheet[index] = person[i];
        index++;
    }
    return answer_sheet;
}

std::vector<int> solution(std::vector<int> answers) {
    std::vector<int> answer_sheet1 = generate_answer_sheet(person1, answers.size());
    std::vector<int> answer_sheet2 = generate_answer_sheet(person2, answers.size());
    std::vector<int> answer_sheet3 = generate_answer_sheet(person3, answers.size());
    
    std::vector<std::vector<int>> answer_sheets = {answer_sheet1, answer_sheet2, answer_sheet3};

    std::vector<int> scores(answer_sheets.size(), 0);
    for(size_t i = 0 ; i < answer_sheets.size(); ++i) {
        for (size_t j = 0; j < answers.size(); ++j) {
            if ( answer_sheets[i][j] == answers[j] ) scores[i]++;
        }
    }

    auto maxIter = max_element(scores.begin(), scores.end());
    std::vector<int> max_scorer;
    for(size_t i = 0; i < scores.size(); ++i) {
        if( *maxIter == scores[i]) {
            max_scorer.push_back(i+1);
        }
    }
    print_vec(max_scorer.begin(), max_scorer.end());
    return max_scorer;;

    
}


int main() {
    std::vector<int> answer = generate_answer_sheet(person1, 17);
    print_vec(answer.begin(), answer.end());

   
    solution(answer);
    return 0;
}
