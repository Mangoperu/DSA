class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_index; 
        remainder_index[0] = -1; 
        
        int current_sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            
            int rem = current_sum % k;
            if (rem < 0) {
                rem += k;
            }
            
            if (remainder_index.find(rem) != remainder_index.end()) {
                if (i - remainder_index[rem] >= 2) {
                    return true;
                }
            } else {
                remainder_index[rem] = i;
            }
        }
        
        return false;
    }
};