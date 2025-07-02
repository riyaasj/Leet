class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        while(j < nums.size()){
            while(j < nums.size() && nums[j] == nums[j - 1]){
                j++;
            }
            if(j < nums.size()){
                nums[++i] = nums[j++];
            }
        }
        return i + 1;
    }
};