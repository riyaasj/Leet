class Solution {
public:
    int search(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<int>>& vis){
        if(index == word.size()){
            return 1;
        }
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || vis[i][j]){
            return 0;
        }
        int res = 0;
        if(word[index] == board[i][j]){
            vis[i][j] = 1;
            res = search(board, word, index + 1, i + 1, j, vis)
            || search(board, word, index + 1, i - 1, j, vis)
            || search(board, word, index + 1, i, j + 1, vis)
            || search(board, word, index + 1, i, j - 1, vis);
        }
        vis[i][j] = 0;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if(search(board, word, 0, i, j, vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};