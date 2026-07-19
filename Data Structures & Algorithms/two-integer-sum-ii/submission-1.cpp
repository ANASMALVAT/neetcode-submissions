class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int j = n - 1;
        int i = 0;
        while(i < j){
            int s = nums[i] + nums[j];
            if(s == target){
                return {i + 1, j + 1};
            }
            else if(s < target){
                i++;
            }
            else{
                j --;
            }
        }
        return {-1};

    }
};
