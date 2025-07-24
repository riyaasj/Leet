class Solution {
public:
    int dfs(vector<vector<char>>& board, string word, int index, int i, int j){
        if(index == word.size()){
            return 1;
        }
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[index]){
            return 0;
        }
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, index + 1, i + 1, j) ||
                     dfs(board, word, index + 1, i - 1, j) ||
                     dfs(board, word, index + 1, i, j + 1) ||
                     dfs(board, word, index + 1, i, j - 1);

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};