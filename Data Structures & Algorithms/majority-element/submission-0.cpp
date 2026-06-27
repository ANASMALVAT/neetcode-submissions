class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int lastnum = nums[0];
        int cnt = 1;
        
        int n = nums.size();
        for(int i = 1; i < n; i ++){
            if(nums[i] == lastnum){
                cnt++;
            }
            else{
                if(cnt > 1){
                    cnt--;
                }
                else{
                    cnt = 1;
                    lastnum = nums[i];
                }
            }
        }
        return lastnum;
    }
};