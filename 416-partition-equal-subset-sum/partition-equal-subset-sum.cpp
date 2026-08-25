class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        
        if(sum % 2 != 0) return false;
        
        int target = sum / 2;
        
        // LeetCode constraints: 
        // 1 <= nums.length <= 200, 1 <= nums[i] <= 100
        // Max possible sum = 20000, Max target = 10000
        bitset<10001> dp;
        dp[0] = 1; // Base case: we can always make a sum of 0
        
        for(int num : nums) {
            // Shift the bits to the left by 'num' and combine with current dp
            dp = dp | (dp << num);
        }
        
        return dp[target];
    }
};