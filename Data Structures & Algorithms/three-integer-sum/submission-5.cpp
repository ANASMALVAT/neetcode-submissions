class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n  - 2 ; i++){

            if(i > 0 and nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            int a = nums[i];
            while (j < k){
                if(nums[j] + nums[k] + a == 0){
                    res.push_back({a,nums[j], nums[k]});
                    j ++;
                    k--;
                }
                else if(a + nums[j] + nums[k] < 0){
                    j++;
                }
                else{
                    k--;
                }
                if(res.size() > 1){
                    int n = res.size() - 1;
                    int m = res.size() - 2;
                    if(res[n] == res[m]){
                        res.pop_back();
                    }
                }
            }
        }
        return res;
    }
};
