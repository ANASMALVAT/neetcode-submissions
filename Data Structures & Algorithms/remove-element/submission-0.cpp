class Solution {
public:

    int removeElement(vector<int>& nums, int val) {
        int cur = -1;
        int i = 0;
        int n = nums.size();
        while(i < n){
            if(nums[i] == val){
                if(cur == -1){
                    cur = i;
                }
            }
            else{
                if(cur != -1){
                    swap(nums[i], nums[cur]);
                    cur++;
                }
            }
            i++;
        }
        if(cur == -1) return n;
        return cur;
    }
};