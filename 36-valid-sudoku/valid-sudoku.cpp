class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<char> s;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) != s.end()){
                        return 0;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        for(int i = 0; i < 9; i++){
            unordered_set<char> s;
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(s.find(board[j][i]) != s.end()){
                        return 0;
                    }
                    s.insert(board[j][i]);
                }
            }
        }
        vector<unordered_set<char>> boxes(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if (boxes[boxIndex].count(board[i][j])) return false;
                    boxes[boxIndex].insert(board[i][j]);
                }
            }
        }

        return 1;
    }
};