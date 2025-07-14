class Solution {
public:
    bool bs(vector<int> &v, int target){
        int l = 0, r = v.size() - 1;
        while(l <= r){
            int k = (l + r) / 2;
            if(v[k] == target){
                return true;
            }
            else if(v[k] > target){
                r = k - 1;
            }
            else{
                l = k + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int m = 0; m < matrix.size(); m++){
            if(matrix[m][0] <= target && matrix[m].back() >= target){
                if(bs(matrix[m], target)) return true;
            }
            if(matrix[m][0] > target) break;
        }
        return false;
    }
};