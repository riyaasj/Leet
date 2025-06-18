class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, m;
        while(l <= r){
            m = (l + r) / 2;
            if(matrix[m][0] <= target && matrix[m].back() >= target){
                break;
            }
            else if(matrix[m][0] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        if(l > r){
            return false;
        }
        l = 0, r = matrix[m].size() - 1;
        while(l <= r){
            int x = (l + r) / 2;
            if(matrix[m][x] == target){
                return true;
            }
            else if(matrix[m][x] > target){
                r = x - 1;
            }
            else{
                l = x + 1;
            }
        }
        return false;
    }
};