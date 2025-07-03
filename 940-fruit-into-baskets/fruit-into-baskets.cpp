class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, res = 0;
        unordered_map<int, int> m;
        for(int right = 0; right < fruits.size(); right++){
            m[fruits[right]]++;
            while(m.size() > 2){
                m[fruits[left]]--;
                if(m[fruits[left]] == 0){
                    m.erase(fruits[left]);
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};