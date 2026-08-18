class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k) return -1;
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int l = 0; int r = maxi;
        int ans = INT_MAX;
        while(l <= r){
            int mid = (l + r) >> 1;
            int cntk = k;int temp = 0;int cntm = m;
            for(int i = 0; i < bloomDay.size(); i++) {
                if(bloomDay[i] <= mid) {
                    cntk--;
                    if(cntk == 0 && cntm != 0) {
                        cntm--;
                        cntk = k;
                    }
                    if(cntm == 0){
                        temp = min(ans, mid);
                        break;
                    }
                }
                else{
                    cntk = k;
                }
            }
            if(temp != 0) {
                r = mid - 1;
                ans = temp;
            }
            else {
                l = mid + 1;
            }

        }
        return ans;
    }
};