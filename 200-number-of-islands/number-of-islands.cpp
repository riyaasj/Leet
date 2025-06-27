class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    res++;
                    queue<vector<int>> q;
                    q.push({i, j});
                    grid[i][j] = '2';
                    while(!q.empty()){
                        vector<int> tmp = q.front();
                        q.pop();
                        for(auto x: dir){
                            vector<int> n = {tmp[0] + x[0], tmp[1] + x[1]};
                            if(n[0] >= 0 && n[0] < grid.size() && n[1] >= 0 && n[1] < grid[0].size() && grid[n[0]][n[1]] == '1'){
                                q.push(n);
                                grid[n[0]][n[1]] = '2';
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};