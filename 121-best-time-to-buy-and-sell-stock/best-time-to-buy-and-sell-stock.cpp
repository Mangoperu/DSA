class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case safety
        
        vector<int> mini(n);
        vector<int> maxi(n);
        
        mini[0] = prices[0];
        maxi[n-1] = prices[n-1];
        
        // Corrected: Compare against prices[i]
        for(int i = 1; i < n; i++){
            mini[i] = min(prices[i], mini[i-1]);
        }
        
        // Corrected: Compare against prices[i]
        for(int i = n-2; i >= 0; i--){
            maxi[i] = max(prices[i], maxi[i+1]); 
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, maxi[i] - mini[i]);
        }
        
        return ans;
    }
};