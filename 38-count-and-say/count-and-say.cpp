class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i < n; i++){
            string temp = "";
            char curr = res[0];
            int index = 0;
            while(index < res.size()){
                int count = 0;
                while(res[index] == curr){
                    count++;
                    index++;
                }
                temp = temp + to_string(count) + curr;
                curr = res[index];
            }
            res = temp;
        }
        return res;
    }
};