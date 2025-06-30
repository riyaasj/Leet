class Solution {
public:
    int findParent(int i, vector<int> &parent){
        if(parent[i] == i) return i;
        return parent[i] = findParent(parent[i], parent);
    }
    void u(vector<int> x, vector<int> &parent, vector<int> &size){
        int ap = findParent(x[0] - 1, parent), bp = findParent(x[1] - 1, parent);
        if(ap == bp) return;
        if(size[ap] < size[bp]){
            parent[ap] = bp;
            size[bp] += size[ap];
        }
        else{
            parent[bp] = ap;
            size[ap] += size[bp];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> size(edges.size(), 0), parent(edges.size());
        for(int i = 0; i < edges.size(); i++){
            parent[i] = i;
        }
        for(auto x: edges){
            if(findParent(x[0] - 1, parent) == findParent(x[1] - 1, parent)){
                return x;
            }
            u(x, parent, size);
        }
        return {};
    }
};