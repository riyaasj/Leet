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
        int count = 0;
        for(int i = 0; i < k; i++){
            count += cards[i];
        }
        int res = count;
        for (int i = k; i < cards.size(); ++i) {
            count += cards[i] - cards[i - k];
            res = max(res, count);
        }
        return res;
    }
};