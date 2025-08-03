class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i = 0; i < s.size(); i++){
            stringstream temp;
            temp << s.substr(i, s.size() - i) << s.substr(0, i);
            if(temp.str() == goal) return true;
        }
        return false;
    }
};