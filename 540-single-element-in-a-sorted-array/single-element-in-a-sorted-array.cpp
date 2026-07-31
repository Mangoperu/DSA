class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];
        
        // Boundaries are perfectly safe now
        int a = 1;
        int b = n - 2; 
        
        while (b >= a) {
            int mid = a + (b - a) / 2;
            
            // Found the single element
            if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
                return nums[mid];
            }
            
            // If mid is odd
            if (mid % 2 != 0) {
                if (nums[mid] == nums[mid-1]) {
                    // Left side is perfectly paired, go right
                    a = mid + 1; 
                } else {
                    // Left side is disrupted, go left
                    b = mid - 1; 
                }
            } 
            // If mid is even
            else {
                if (nums[mid] == nums[mid+1]) {
                    // Left side is perfectly paired, go right
                    a = mid + 1; 
                } else {
                    // Left side is disrupted, go left
                    b = mid - 1; 
                }
            }
        }
        return -1;
    }
};