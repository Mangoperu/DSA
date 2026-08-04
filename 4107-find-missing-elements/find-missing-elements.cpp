class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // Handle edge case of an empty array
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        int curr = nums[0];          // Start at the minimum element
        int b = nums[nums.size()-1]; // End at the maximum element
        int i = 0;
        
        while (curr <= b) {
            // If the current number matches the array element
            if (i < nums.size() && curr == nums[i]) {
                // Advance 'i' past any duplicates in the array
                while (i < nums.size() && curr == nums[i]) {
                    i++;
                }
                curr++; // Move to the next expected number
            } 
            // If it doesn't match, it means 'curr' is missing
            else {
                ans.push_back(curr);
                curr++;
            }
        }
        return ans;
    }
};