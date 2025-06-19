class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<vector<int>> s;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!s.empty() && s.top()[0] <= temperatures[i]){
                s.pop();
            }
            int tmp = temperatures[i];
            if(s.empty()){
                temperatures[i] = 0;
            }
            else{
                temperatures[i] = s.top()[1] - i;
            }
            s.push({tmp, i});
        }
        return temperatures;
    }
};