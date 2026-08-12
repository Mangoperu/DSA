class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Use a vector instead of unordered_map for much faster O(1) lookups
        vector<int> remainder_freq(k, 0); 
        remainder_freq[0] = 1; // Base case
        
        int current_sum = 0;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            
            // Calculate positive remainder
            int rem = current_sum % k;
            if (rem < 0) {
                rem += k;
            }
            
            // Add the number of times we've seen this remainder before
            ans += remainder_freq[rem];
            
            // Increment the frequency of this remainder
            remainder_freq[rem]++;
        }
        
        return ans;
    }
};