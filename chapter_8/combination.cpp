#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/* sol 1. - recursion */
void combination(string src, string dst, size_t depth) {
    if (dst.length() == depth) {
        std::cout << dst << endl;
    } else {
        for (size_t i = 0; i < src.length(); ++i) {
            combination(src.substr(i + 1), dst + src[i], depth);
        }
    }
}

/* sol 2. - permutation table */
void combination_2(string src, size_t depth) {
    vector<bool> v(src.length() - depth, false);
    string dst;
    v.insert(v.end(), depth, true);
    do {
        for(int i = 0; i < v.size(); ++i) {
            if (v[i]) dst += src[i];
        }
        cout << dst;
    } while (next_permutation(v.begin(), v.end()));
}

int main() {
    string s = "abcde";
    combination(s, "", 2);
    return 0;

}
