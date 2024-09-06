#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, int> report_counts;
    vector<string> banned;
    unordered_map<string, int> mail_counts;
	sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    for (const auto& elem : report) {
        stringstream ss(elem);
        string a, b;
        ss >> a >> b;
        report_counts[b] += 1;
    }
    for (const auto& elem : report_counts) {
        if (elem.second >= k) {
            banned.push_back(elem.first);
        }
    }
    for (const auto& elem : report) {
        stringstream ss(elem);
        string a, b;
        ss >> a >> b;
        if (find(banned.begin(), banned.end(), b) != banned.end()) {
            mail_counts[a] += 1;
        }
    }
    vector<int> answer;
    for (const auto& elem : id_list) {
        answer.push_back(mail_counts[elem]);
    }
    return answer;
}