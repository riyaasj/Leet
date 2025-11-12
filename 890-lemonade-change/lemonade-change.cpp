class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i: bills){
            if(i == 5) five++;
            else if(i == 10){
                ten++;
                if(five == 0) return false;
                else{
                    five--;
                }
            }
            else{
                if(ten && five){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};