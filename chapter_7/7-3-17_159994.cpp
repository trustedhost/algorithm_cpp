/* 159994 */ 
#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    std::queue<string> q1, q2, qGoal;
    for(const auto& elem : cards1 ) {
        q1.push(elem);
    }
    for(const auto& elem : cards2 ) {
        q2.push(elem);
    }
    for(const auto& elem : goal ) {
        qGoal.push(elem);
    }
    while (!qGoal.empty())  {
        if (qGoal.front() == q1.front()) {
            qGoal.pop();
            q1.pop();
        }
        else if (qGoal.front() == q2.front()) {
            qGoal.pop();
            q2.pop();
        }
        else {
         	break;   
        }	
    }
    answer = (qGoal.empty()) ? "Yes" : "No";
    return answer;
}
