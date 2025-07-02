class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int s = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(i == 0){
                        s = 1;
                    }
                    else{
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < matrix[0].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < matrix[0].size(); i++){
            if(matrix[0][i] == 0){
                for(int j = 0; j < matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
        if(s == 1){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[0][j] = 0;
            }
        }
    }
};