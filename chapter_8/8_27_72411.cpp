#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

void make_combination(string src, string dst, int depth, unordered_map<string, int>& combinations) {
    if (depth == dst.length()) {
        combinations[dst]++;
    } else {
        for (int i = 0; i < src.length(); ++i) {
            make_combination(src.substr(i + 1), dst + src[i], depth, combinations);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
	unordered_map<string, int> combinations;
    vector<string> answer;
    for (auto& order : orders) {
        sort(order.begin(), order.end());
    }
    for (int count : course) {
        for (auto order : orders) {
            make_combination(order, "", count, combinations);
        }
        int maxOrder = 0;
        for (auto it : combinations) {
            maxOrder = max(maxOrder, it.second);
        }
        if (maxOrder >= 2) {
            for (auto it : combinations) {
                if (it.second == maxOrder) {
                    answer.push_back(it.first);
                }
            }
        }
        combinations.clear();
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}