class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &colours, int i, int pColour){
        colours[i] = 1 - pColour;
        for(int x: graph[i]){
            if(colours[x] == -1){
                if(dfs(graph, colours, x, colours[i]) == false) return false;
            }
            else{
                if(colours[x] == colours[i]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colours(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(colours[i] == -1){
                if(dfs(graph, colours, i, 0) == false) return false;
            }
        }
        return true;
    }
};