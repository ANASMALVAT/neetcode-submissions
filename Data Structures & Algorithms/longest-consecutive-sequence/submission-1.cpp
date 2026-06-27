class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i] = 1;
        }
        int mxSeq = 1;
        unordered_map<int,int> vis;
       for(int i : nums){
         int li = i - 1;
         if(mp[li]){
            continue;
         }
         else{
            int curS = 1;
            int j = i + 1;
            while(mp[j]){
                j++;
                curS++;
            }
            mxSeq = max(mxSeq, curS);
         }
       }
       return mxSeq;
    }
};
