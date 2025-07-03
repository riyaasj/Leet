class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> cards(2 * k);
        int j = 0;
        for(int i = cardPoints.size() - k; i < cardPoints.size(); i++){
            cards[j++] = cardPoints[i];
        }
        for(int i = 0; i < k; i++){
            cards[j++] = cardPoints[i];
        }
        int left = 0, right = 0, count = 0;
        while(right < k){
            count += cards[right];
            right++;
        }
        int res = count;
        while (right < cards.size()) {  
            count -= cards[left++];
            count += cards[right++];
            res = max(res, count);
        }
        return res;
    }
};