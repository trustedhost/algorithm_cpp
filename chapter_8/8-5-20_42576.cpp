/* 42576 */

/* sol 1 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    if (participant.size() == 1) {
        return participant[0];
    }
    for (int i = 0; i < participant.size(); ++i) {
        if (participant[i] != completion[i]) return participant[i];
    }
}

/* sol 2 */
string solution(vector<string> participant, vector<string> completion) {
    std::unordered_map<string, int> participant_map;
    for (const auto& elem : participant) {
        participant_map[elem] += 1; 
    }
    for (const auto& elem : completion) {
        participant_map[elem] -= 1;
        if (participant_map[elem] == 0) {
            participant_map.erase(participant_map.find(elem));
        }
    }
    return participant_map.begin()->first;
    
}
