class Solution {
public:
    bool isValid(int i, int j, string s){
        while(i < j){
            if(s[i] == s[j]){
                i++;j--;
            }
            else return false;
        } 
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        int cnt = 0;
        while(i < j){
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else{
                bool a =false;
                bool b = false;
                if(s[i + 1] == s[j]){
                    a = isValid(i + 1,j,s);
                }
                if(s[j - 1] == s[i]){
                    b = isValid(i,j-1,s);
                }
                if (a or b) return true;
                return false;
            }
        }
        return true;
    }
};