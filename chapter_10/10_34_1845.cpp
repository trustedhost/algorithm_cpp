#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    set<int> types;
    for (const auto& elem : nums) {
        types.insert(elem);
    }
    size_t max_num = nums.size() / 2;
    return min(max_num, types.size());
}