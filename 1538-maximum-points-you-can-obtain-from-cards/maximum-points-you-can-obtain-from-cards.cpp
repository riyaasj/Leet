class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int count = 0;
        for(int i = 0; i < k; i++){
            count += cardPoints[i];
        }
        cout << count << " ";
        int res = count;
        int j = cardPoints.size();
        for(int i = k - 1; i >= 0; i--){
            count -= cardPoints[i];
            count += cardPoints[--j];
            cout << count << " ";
            res = max(res, count);
        }
        return res;
    }
};