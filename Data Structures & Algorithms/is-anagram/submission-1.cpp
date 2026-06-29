class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26,0);
        for(char c : s){
            int i = c - 'a';
            cnt[i]++;
        }
        for(char c: t){
            int i = c - 'a';
            cnt[i]--;
        }
        for(int i: cnt){
            if(i != 0) return false;
        }
        return true;

    }
};
