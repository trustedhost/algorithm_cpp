#include <vector>
#include <algorithm>
#include <memory>
#include <unordered_map>
using namespace std;

struct Music {
    string genre;
    int count;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<pair<int, Music*>> musics;
    for (int i = 0; i < genres.size(); ++i) {
        Music* m = new Music{genres[i], plays[i]};
        musics.push_back({i, m});
    }
    
    unordered_map<string, int> genre_counts;
    for (int i = 0; i < genres.size(); ++i) {
        genre_counts[genres[i]] += plays[i];
    }
    
    sort (musics.begin(), musics.end() , [&](pair<int, Music*> a, pair<int, Music*> b) {
        const string& genre_a = a.second->genre;
        const string& genre_b = b.second->genre;
        int count_a = a.second->count;
        int count_b = b.second->count;
        if (genre_a != genre_b) {
            return genre_counts[genre_a] > genre_counts[genre_b];
        } 
        if (count_a != count_b) {
            return count_a > count_b;
        }
        return a.first < b.first;
    } );
    
    vector<int> answer;
    unordered_map<string, int> genre_count;
    for (const auto& elem : musics) {
        if (genre_count[elem.second->genre] < 2) {
            answer.push_back(elem.first);
            genre_count[elem.second->genre] += 1;
        }
    }
    return answer;
    
}