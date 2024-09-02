#include <iostream>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

int main() {
    const int NUM_ELEMENTS = 10000000;
    std::map<int, int> orderedMap;
    std::unordered_map<int, int> unorderedMap;

    clock_t start, end;

    /* map */
    start = clock();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        orderedMap[i] = rand();
    }
    
    end = clock();

    std::cout << "map insertion time: " << double(end - start) / CLOCKS_PER_SEC << std::endl;


    /* unordered_map */
    start = clock();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        unorderedMap[i] = rand();
    }
    end = clock();

    std::cout << "unordered_map insertion time: " << double(end - start) / CLOCKS_PER_SEC << std::endl;
    return 0;
}

/* example return 
map insertion time: 11.4762
unordered_map insertion time: 2.86021
*/
