#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct Music {
    std::string genre;
    int play_count;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    std::vector<pair<int, Music*>> musics;
    for (int i = 0; i < genres.size(); ++i) {
        Music* m = new Music{genres[i], plays[i]};
        musics.push_back({i, m});
    }
    std::unordered_map<string, int> genres_to_plays;
    for (int i = 0; i < genres.size(); ++i) {
        genres_to_plays[genres[i]] += plays[i];
    }
    sort(musics.begin(), musics.end(), [&](std::pair<int,Music*> a, std::pair<int, Music*> b) {
        string genre_a = a.second->genre;
        string genre_b = b.second->genre;
        int count_a = a.second->play_count;
        int count_b = b.second->play_count;
        
        if (genres_to_plays[genre_a] > genres_to_plays[genre_b]) {
            return a;
        } else if (genres_to_plays[genre_a] < genres_to_plays[genre_b]) {
            return b;
        } else {
            return (count_a > count_b) ? a : b;
        }
    });
    std::vector<int> answer;
    for (const auto& elem : musics) {
        answer.push_back(elem.first);
    }
    
    return answer;
    
    
    

}