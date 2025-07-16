class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(char c: s){
            m[c]++;
        }
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for(auto x: m){
            pq.push(x);
        }
        string res = "";
        while(!pq.empty()){
            auto x = pq.top();
            res.append(x.second, x.first);
            pq.pop();
        }
        return res;
    }
};