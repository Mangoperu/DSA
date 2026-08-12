class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg;
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
        }
        vector<int> ans;
        int j  = 0;
        int k =0;
        int i =0;
        while(i<n){
            if(nums[j]>0){
                ans.push_back(nums[j]);
                ans.push_back(neg[k]);
                k++;
                i+=2;
            }
            j++;
        }
        return ans;
    }
};