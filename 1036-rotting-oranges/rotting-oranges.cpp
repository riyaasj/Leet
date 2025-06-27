class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<vector<int>> q;
        int res = -1, o = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    o++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        if(o == 0){
            return 0;
        }
        while(!q.empty()){
            res++;
            int size = q.size();
            while(size--){
                vector<int> tmp = q.front();
                q.pop();
                for(auto x: dir){
                    vector<int> n = {tmp[0] + x[0], tmp[1] + x[1]};
                    if(n[0] >= 0 && n[0] < grid.size() && n[1] >= 0 && n[1] < grid[0].size() && grid[n[0]][n[1]] == 1){
                        q.push(n);
                        grid[n[0]][n[1]] = 2;
                        o--;
                    }
                }
            }
        }
        if(o != 0){
            return -1;
        }
        return res;
    }
};