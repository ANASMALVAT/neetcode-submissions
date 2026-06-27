class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        // validate that the rows and column has the unique number
        
        unordered_map<char,vector<int>> mpr;
        unordered_map<char,vector<int>> mpc;

        
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n ; i++){
            for(int j = 0 ;j < m; j ++){
                char c = board[i][j];
                if(c == '.') continue;
                vector<int>& mprv = mpr[c];
                vector<int>& mpcv = mpc[c];
                if(find(mprv.begin(),mprv.end(),i) != mprv.end()){
                    return false;
                }
                if(find(mpcv.begin(),mpcv.end(),j) != mpcv.end()){
                    return false;
                }
                mpr[c].push_back(i);
                mpc[c].push_back(j);
            }
        }

        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
        
    }
};
