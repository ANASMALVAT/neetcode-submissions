class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> v(n + 1, 0);
        int mx = 0;
        for(int i = 1; i < n ; i ++){
            if(p[i] > p[i - 1]){
                v[i] = p[i] - p[i - 1];
                v[i] += v[ i - 1];
            }
            else{
                v[i] = v[i - 1];
            }
            mx = max(mx, v[i]);
        }
        return mx;
    }
};