/* 64061 */
#include <string>
#include <vector>
#include <stack>

using namespace std;
int pick_one(vector<vector<int>>& board, int column) {
	//row parsing
    for( int i = 0 ; i < board.size(); ++i) {
        int target = board[i][column];
        if (target != 0) {
            board[i][column] = 0; // change the value
            return target;
        }
    }
    return 0; //nothing happens

}
int solution(vector<vector<int>> board, vector<int> moves) {
    std::stack<int> basket;
    int score = 0;
    for (auto elem : moves) {
        int target = pick_one(board, elem - 1);
        if (target != 0) {
            if ( basket.empty() || basket.top() != target) basket.push(target);
            else {
                score += 2;
                basket.pop();
            }
        }
    }

    return score;
}
