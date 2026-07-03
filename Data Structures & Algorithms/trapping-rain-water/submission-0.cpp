class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> vr(n,-1);
        vector<int> vl(n,-1);
        int l = -1;
        for(int i = 0; i < n; i++){
            if(height[i] >= l){
                vl[i] = -1;
                l = height[i];
            }else{
                vl[i] = l;
            }
        }
        int r = -1;
        for(int i = n - 1; i >= 0; i--){
            if(height[i] >= r){
                vr[i] = -1;
                r = height[i];
            }else{
                vr[i] = r;
            }
        }
        int res =0;
        for(int i = 0; i < n; i++){
            int lv = vl[i];
            int rv = vr[i];
            int m = min(lv, rv);
            if(m > height[i]){
                res += m;
                res -= height[i];
            }
        }
        return res;
         
    }
};
