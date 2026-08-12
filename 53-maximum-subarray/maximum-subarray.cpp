class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Build the prefix sum array properly
        vector<int> pre(n , 0);
        pre[0] = nums[0];
        for(int i = 1; i < n ; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        
        // 2. minPrice starts at 0 to handle subarrays starting at index 0
        int minPrice = 0; 
        
        // 3. maxProfit starts at INT_MIN to handle arrays with all negative numbers
        int maxProfit = INT_MIN; 
        
        for(int i = 0; i < n; i++) {
            // Calculate max subarray sum ending here FIRST
            maxProfit = max(maxProfit, pre[i] - minPrice);
            
            // Then update the lowest prefix sum seen so far for future iterations
            minPrice = min(minPrice, pre[i]);
        }
        
        return maxProfit;
    }
};