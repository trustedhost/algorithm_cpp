#include <vector>

void mapping(std::vector<int &hash, const std::vector<int> &arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > target) 
            continue;
        hash[arr[i]] = 1;
    }
}

bool solution(std::vector<int>arr, int target) {
    std::vector<int> hash(target + 1, 0);
    mapping(hash, arr, target);

    for (int i = 0;i < arr.size(); ++i) {
        int num = target - arr[i];

        if (arr[i] == num)
            continue;
        if (num < 0) {
            continue;
        }
        if (hash[num]) return true;
    }
    return false;
}


