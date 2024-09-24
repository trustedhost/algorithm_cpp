#include <iostream>

using namespace std;

bool numInRange(int start, int end, int num) {
    if (num >= start && num <= end) {
        return true;
    } else {
        return false;
    }
}

int sliceGroup(int start, int end, int a, int b, int depth) {
    int slice = (start + end) / 2;
    if ( numInRange(start, slice, a) && numInRange(slice + 1, end, b) ) {
        return depth;
    } else if ( numInRange(start, slice, a) && numInRange(start, slice, b) ) {
        return sliceGroup(start, slice, a, b, depth + 1);
    } else if ( numInRange(slice + 1, end, a) && numInRange(slice + 1, end, b) ) {
        return sliceGroup(slice + 1, end, a, b, depth + 1);
    } else { // 1, 2 처럼 붙어있는 경우.
        return depth;
    }
}

int log2(int n) {
    if (n == 1) {
        return 0;
    } else {
        return 1 + log2(n / 2);
        
    }
}

int solution(int n, int a, int b)
{	
    int first, second;
    first = (a > b) ? b : a;
    second = (a > b) ? a : b;
    int sliceCount = sliceGroup(1, n, a, b, 0);
    std::cout << sliceCount << endl;
    return log2(n) - sliceCount;
}