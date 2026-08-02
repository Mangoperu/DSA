class Solution {
public:
    int rec(int n, vector<int>& v) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        // Return cached result if already calculated
        if (v[n] != -1) {
            return v[n];
        }

        // Calculate and store the result
        v[n] = rec(n - 1, v) + rec(n - 2, v) + rec(n - 3, v);
        return v[n];
    }
    
    int tribonacci(int n) {
        vector<int> v(n + 1, -1);
        return rec(n, v);
    }
};