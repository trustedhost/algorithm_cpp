/* 42888 */
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

std::vector<std::string> split(const std::string& input, const char& delimiter) {
    std::stringstream ss(input);
    std::vector<std::string> str_vec;
    std::string temp;
    while (getline(ss, temp, delimiter)) {
        str_vec.push_back(temp);
    }
    return str_vec;
}

vector<string> solution(vector<string> record) {
    std::unordered_map<std::string, std::string> nameMap;
    for (const auto& elem : record) {
        std::vector<std::string> cmd = split(elem, ' ');
        if (cmd[0] == "Enter") {
            nameMap[cmd[1]] = cmd[2];
        } else if (cmd[0] == "Change") {
            nameMap[cmd[1]] = cmd[2];
        }
    }
    std::stringstream ss;
    for (const auto& elem : record) {
        std::vector<std::string> cmd = split(elem, ' ');
        if (cmd[0] == "Enter") {
            std::string name = nameMap[cmd[1]];
            ss << name << "님이 들어왔습니다." << '\n';
        } else if (cmd[0] == "Leave") {
            std::string name = nameMap[cmd[1]];
            ss << name << "님이 나갔습니다." << '\n';
        }
    }
    std::vector<std::string> answer;
    std::string temp;
    while(getline(ss, temp, '\n')) {
        answer.push_back(temp);
    }
    return answer;
}
