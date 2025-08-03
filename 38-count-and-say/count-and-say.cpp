class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i < n; i++){
            stringstream temp;
            char curr = res[0];
            int index = 0;
            while(index < res.size()){
                int count = 0;
                while(res[index] == curr){
                    count++;
                    index++;
                }
                temp << count << curr;
                curr = res[index];
            }
            res = temp.str();
        }
        return res;
    }
};