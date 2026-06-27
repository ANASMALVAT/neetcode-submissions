class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        set<pair<int,int>> s;
        for(int i : nums){
            mp[i]++;
        }
        for(auto i: mp){
            s.insert({i.second, i.first});
        }
        auto it = s.rbegin();
        vector<int> res;
        while(k--){
            res.push_back(it->second);
            it++;
        }
        return res;
        
    }
};
