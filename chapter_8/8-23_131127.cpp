#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0; i < discount.size() - 9; ++i) {
	    std::unordered_map<std::string, int> d_number;
        int check = 0;
        for (int j = 0; j < want.size(); j++) {
            d_number[want[j]] = 0;
        }
        for (int j = i; j < i + 10; ++j ) {
            d_number[discount[j]]++;
        }
        for (int j = 0; j < want.size(); j++) {
            if (d_number[want[j]] != number[j]) {
                break;
            } else {
                check += 1;
            }
        }
        if (check == want.size()) {
            answer += 1;
        }
    }
    return answer;
}
