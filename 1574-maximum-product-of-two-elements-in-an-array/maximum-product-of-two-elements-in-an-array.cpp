class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int s1 = nums[0];
        int s2 = nums[1];
        int l1 = nums[0];
        int l2 = nums[1];
        int n = nums.size();
        if(l2<l1){
            swap(l1,l2);
        }
        if(s1>s2){
            swap(s1 , s2);
        }
        for(int i = 2 ; i<n ; i++){
            if(nums[i]>l2){
                l1 = l2;
                l2 = nums[i];
            }
            else if(nums[i]>l1){
                l1 = nums[i];
            }
            if(nums[i]<s1){
                s2 = s1;
                s1 = nums[i];
            }
            else if(nums[i]<s2){
                s2 = nums[i];
            }
        }

        return max((s1-1)*(s2-1) , (l1-1)*(l2-1));
    }
};