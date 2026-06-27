class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid, int &cnt)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i >= 0 and j >= 0 and i < n and j < m and grid[i][j] == 1){
            grid[i][j] = -1;
            cnt--;
            return true;
        }
        if(i >= 0 and j >= 0 and i < n and j < m and grid[i][j] == -1){
            cnt--;
            return false;
        }
        
        return false;
    }
    void pushQ(bool x, int i, int j, queue<pair<int,int>> &q){
        if(x){
            q.push({i,j});
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int s = 0;
        
        queue<pair<int,int>> q;
        
        int n = grid.size();
        int m = grid[0].size();
        int f = 0;
        for(int i = 0; i < n;i ++){
            for(int j = 0; j < m ; j ++ ){
                if(grid[i][j] == 1 and f == 0){
                    grid[i][j] = -1;
                    q.push({i,j});
                    f = 1;
                }
            }
        }
        while(q.size() > 0){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            int cnt = 4;
            bool a = check(r + 1,c,grid, cnt);
            bool b = check( r - 1,c,grid,cnt);
            bool x = check(r, c + 1, grid,cnt);
            bool y = check (r, c- 1, grid,cnt);
            pushQ(a,r + 1,c,q);
            pushQ(b,r - 1,c,q);
            pushQ(x,r,c + 1,q);
            pushQ(y,r,c - 1,q);
            cout << r <<" " << c << " " << cnt << endl;
            s+= cnt;
        }
        return s;
    }
    
};