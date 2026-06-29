class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int,int> cnt;
        vector<int> res;
        for(int i : nums){
            cnt[i]++;
            if(cnt.size() > 2){
                unordered_map<int,int> ncnt;
                for(auto it: cnt){
                    if(it.second > 1){
                        ncnt[it.first] = it.second - 1;
                    }
                }
                cnt = ncnt;
            }
        }

        for(auto it: cnt){
            int a = it.first;
            int b = it.second;
            int f = 0;
            for(int j: nums){
                if(j == a) f++;
            }
            if(f > nums.size() / 3){
                res.push_back(a);
            }
        }
        return res;
    }
};
