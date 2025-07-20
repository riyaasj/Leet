class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> v = triangle[n - 1];  
        
        for (int i = n - 2; i >= 0; i--) {
            vector<int> temp(i + 1);
            for (int j = 0; j <= i; j++) {
                temp[j] = min(v[j], v[j + 1]) + triangle[i][j];
            }
            v = temp;
        }

        return v[0];  
    }
};