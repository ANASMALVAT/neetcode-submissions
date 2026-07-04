class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cntz =0;
        int cntn = 0;
        int m = 1;
        int n = nums.size();
        vector<int> res(n,0);
        for(int i: nums){
            if(i == 0) cntz++;
            if(i < 0) cntn++;
        }
        if(cntz > 1) return vector<int>(n,0);
        for(int i: nums) if(i !=0) m = i*m;
        cntn = (cntn != 0 && cntn % 2 != 0) ? 1 : -1;
        cntn = (cntn == 0) ? 1 : 1;

        for(int i = 0; i < n;i++){
            if(cntz == 1){
                (nums[i] == 0) ? res[i] = m : res[i] = 0;
            }
            else{
                res[i] = (m / nums[i]) * cntn;
            }
        }
        return res;
    }
};
