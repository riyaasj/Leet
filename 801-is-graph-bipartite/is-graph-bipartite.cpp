class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &colours, int i, int pColour){
        visited[i] = 1;
        colours[i] = 1 - pColour;
        for(int x: graph[i]){
            if(!visited[x]){
                if(dfs(graph, visited, colours, x, colours[i]) == false) return false;
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
        vector<int> visited(graph.size(), 0), colours(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(!visited[i]){
                if(dfs(graph, visited, colours, i, 0) == false) return false;
            }
        }
        return true;
    }
};