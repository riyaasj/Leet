class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count = 0, left = 0;
        string res = "";
        for(int right = 0; right < s.size(); right++){
            if(s[right] == '1') count++;
            while(count > k){
                if(s[left] == '1'){
                    count--;
                }
                left++;
            }
            if(count == k) {
                while(s[left] == '0'){
                    left++;
                }
                string curr = s.substr(left, right - left + 1);
                if(res == "" || res.size() > curr.size() || (res.size() == curr.size() && curr < res)){
                    res = curr;
                }
            }
        }
        return res;
    }
};