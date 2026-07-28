class Solution {
public:
    int rec(int m , int n , vector<vector<int>>& v, vector<vector<int>>& grid){
        // Fixed base case: checks for obstacle at start
        if(m == 1 && n == 1){
          return grid[0][0];
        }
        
        if(v[m][n] != -1){
            return v[m][n];
        }
        
        int left = INT_MAX;
        int up = INT_MAX;
        
        if(m > 1)  left = rec(m-1 , n, v, grid) + grid[m-1][n-1];
        if(n > 1)  up = rec(m , n-1, v, grid) + grid[m-1][n-1];
        
        v[m][n] = min(left,up);
        return min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> v(m+1, vector<int>(n+1, -1));
        return rec(m, n, v, grid);
    }
};