class Solution {
public:
    int rec(int a, string &s, vector<int> &dp) {
        // Base case: If we successfully reached the end of the string, 
        // it means we found 1 valid way to decode it.
        if (a == s.length()) {
            return 1;
        }
        
        // Invalid case: A decoding cannot start with '0'
        if (s[a] == '0') {
            return 0;
        }
        
        // Return memoized result if available
        if (dp[a] != -1) {
            return dp[a];
        }

        // Option 1: Take one digit
        int ways = rec(a + 1, s, dp);
        
        // Option 2: Take two digits
        // Ensure we don't go out of bounds and the two digits form a valid number (10 to 26)
        if (a + 1 < s.length() && (s[a] == '1' || (s[a] == '2' && s[a + 1] <= '6'))) {
            ways += rec(a + 2, s, dp);
        }
        
        // Save and return the result
        return dp[a] = ways;
    }

    int numDecodings(string s) {
        // Initialize DP array with -1
        vector<int> dp(s.length(), -1);
        return rec(0, s, dp);
    }
};