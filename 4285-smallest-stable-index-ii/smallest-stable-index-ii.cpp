class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        
        // 1. Build prefix max array
        vector<int> v(n);
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
             maxi = max(maxi, nums[i]);
             v[i] = maxi;
        }
        
        // 2. Build suffix min array
        vector<int> m(n);
        int mini = INT_MAX; 
        for(int i = n - 1; i >= 0; i--) {
            mini = min(nums[i], mini);
            m[i] = mini; // Assigned directly to the matching index
        }
        
        // 3. Find the SMALLEST index that is stable
        for(int i = 0 ; i < n; i++) {
            int score = v[i] - m[i]; 
            if(score <= k) {
                return i; // Return immediately! This is the smallest index.
            }
        }
        
        return -1; // No stable index found
    }
};