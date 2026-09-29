#include <vector>

using namespace std;

class Solution {
public:
    int dp[105][105][205]; // dp[i][j][count]

    bool rec(int i, int j, vector<vector<char>>& grid, int n, int m, int count) {
        // Increment/decrement balance based on current character
        if (grid[i][j] == '(') {
            count++;
        } else {
            count--;
        }

        // If balance becomes negative, this path is invalid
        if (count < 0) return false;

        // Base case: reached the bottom-right cell
        if (i == n - 1 && j == m - 1) {
            return count == 0;
        }

        // Return cached result if already computed
        if (dp[i][j][count] != -1) {
            return dp[i][j][count];
        }

        bool down = false;
        bool right = false;

        if (i < n - 1) {
            down = rec(i + 1, j, grid, n, m, count);
        }
        if (j < m - 1) {
            right = rec(i, j + 1, grid, n, m, count);
        }

        return dp[i][j][count] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // A valid path length is (n + m - 1). If it's odd, it can never be balanced.
        if ((n + m - 1) % 2 != 0) return false;
        
        // Start cell must be '(' and end cell must be ')'
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;

        // Initialize memoization array with -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= n + m; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        return rec(0, 0, grid, n, m, 0);
    }
};