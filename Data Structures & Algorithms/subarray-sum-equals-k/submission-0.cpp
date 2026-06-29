class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s = 0;
        int res = 0;
        int n =nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i < n ; i ++){
            s += nums[i];
            if(s == k){
                res++;
            }
            int p = s - k;
            if(mp.find(p) != mp.end()){
                res += mp[p];
            }
            mp[s]++;
        }
        return res;
    }
};