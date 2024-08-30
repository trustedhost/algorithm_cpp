/* 49994 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>


using std::string;

    
struct Point {
    int x = 0, y = 0;
    std::set<std::pair<std::pair<int, int>, std::pair<int,int>>> paths;
    void pathInsert(std::pair<int, int> start,  std::pair<int,int> end) {
        paths.insert(std::make_pair(start, end));
    }
    void L() {
        if ( -5 < x ) {
            x -= 1; 
            pathInsert({x, y}, {x + 1, y});
        }
    }
    void R() {
        if ( x < 5 ) {
            x += 1; 
            pathInsert({x - 1, y},{x, y});
        }
    }
    void U() {
        if ( y < 5 ) {
            y += 1; 
            pathInsert({x, y - 1}, {x, y});
        }
    }
    void D() {
        if ( y > -5 ) {
            y -= 1; 
            pathInsert({x, y}, {x, y + 1});
        }
    }
    void print_point() {
        std::cout << x << ", " << y << '\n';
    }
    void print_paths() {
        auto itr = paths.begin();
        while (itr != paths.end() ){
            std::cout << itr->first.first << ", " << itr->first.second << ") -> (" << itr->second.first << ", " <<
            itr->second.second << '\n';
            itr++;
        }
    }
};
int solution(string dirs) {
    int answer = 0;
    std::cout << dirs;
    Point p;
    for (size_t i = 0; i < dirs.length(); ++i){
        switch(dirs[i]) {
            case 'L' :
                p.L();
                break;
            case 'R' :
                p.R();
                break;
            case 'U' :
                p.U();
                break;
            case 'D' :
                p.D();
                break;
        }
    }
    std::cout << p.paths.size();
    return p.paths.size();
}

int main() {
    std::string dirs("LRUD");

    solution(dirs);
}

