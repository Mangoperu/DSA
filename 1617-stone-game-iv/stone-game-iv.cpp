class Solution {
public:
    // Use an int vector to allow a -1 "unvisited" state
    vector<int> dp;
    
    bool solve(int n) {
        if (n == 0) return false;
        
        // If it's not -1, we have already calculated the answer
        if (dp[n] != -1) {
            return dp[n];
        }
        
        for (int i = 1; i * i <= n; i++) {
            if (solve(n - i * i) == false) {
                return dp[n] = 1; // Mark as true
            }
        }
        return dp[n] = 0; // Mark as false
    }
    
    bool winnerSquareGame(int n) {
        // Initialize the vector cleanly for every new test case LeetCode runs
        dp.assign(n + 1, -1);
        return solve(n);
    }
};