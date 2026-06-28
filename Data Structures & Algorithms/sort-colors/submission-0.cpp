class Solution {
public:
    void sortColors(vector<int>& nums) {
         vector<int> cnt(3,0);
        for(int i: nums){
            cnt[i]++;
        }
        int a = cnt[0];
        int b = cnt[1];
        int c = cnt[2];
        int i = 0; 
        while(i < nums.size()){
            while ( i < a){
                nums[i] = 0;
                i++;
            }
            while(i < a + b){
                nums[i] = 1;
                i++;
            }
            while(i < a + b + c){
                nums[i] = 2;
                i++;
            }
        }
        
        
    }
};