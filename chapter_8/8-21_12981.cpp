/* 12981 */
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    std::unordered_set<std::string> done;
    int failer = 0;
    for (int i = 0; i < words.size(); ++i) {
        if(done.find(words[i]) == done.end()) {
            done.insert(words[i]);
        } else {
            failer = i;
            break;
        }
        if ( i > 0 && words[i].front() != words[i - 1].back()) {
            failer = i;
            break;
        }
    }
    if (failer == 0) {
       	return {0, 0};
    } else {
        int index = failer + 1;
        int k = (index) % n; // 몇 번째 사람인가
        k = k ? k : n;
        int r = (index + n - 1) / n; // 몇 번째 round 인가
        return {k, r};
    }
}
