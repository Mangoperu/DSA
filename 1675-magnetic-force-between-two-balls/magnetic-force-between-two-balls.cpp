class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin() , position.end());
        int a = 1;
        int b = position[position.size() - 1] - position[0];
        int mid = a +(b-a)/2;
        int n = position.size();
        int ans = -1;
        while(b>=a){
            int k = m-1;
            int last = position[0];
            for(int i = 0 ; i<n ; i++){
                if(position[i]-last >= mid){
                    k--;
                    last = position[i];
                }
            }
            if(k>0){
                b = mid-1;
            }
            if(k<=0){
                a  =mid+1;
                ans = max(mid , ans);
            }
            mid = a +(b-a)/2;

        }
        return ans;
    }
};