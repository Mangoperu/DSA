class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int a = 1;
        // The maximum possible divisor we need is the max element in the array
        int b = 0;
        for(int num : nums) {
            b = max(b, num);
        }
        
        int ans = -1;
        
        while (a <= b) {
            // 1. Calculate mid inside the loop
            int mid = a + (b - a) / 2; 
            long long sum = 0;
            
            for (int i = 0; i < nums.size(); i++) {
                // Optimized ceiling division
                sum += (nums[i] + mid - 1) / mid;
            }
            
            // 2. Update bounds based on the sum
            if (sum <= threshold) {
                ans = mid;      // Found a valid divisor, record it
                b = mid - 1;    // Try to find an even smaller one
            } else {
                a = mid + 1;    // Sum is too large, we need a larger divisor
            }
        }
        
        // 3. Return the recorded answer
        return ans;
    }
};