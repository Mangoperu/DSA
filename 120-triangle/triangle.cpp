class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Initialize our DP array with the values of the bottom row of the triangle
        vector<int> dp = triangle[n - 1];
        
        // Start from the second-to-last row and move upwards
        for (int i = n - 2; i >= 0; --i) {
            // Traverse the current row
            for (int j = 0; j <= i; ++j) {
                // The minimum total to reach the bottom from the current cell 
                // is its own value plus the minimum of its two children from the row below
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        
        // The top element will now contain the minimum path sum
        return dp[0];
    }
};