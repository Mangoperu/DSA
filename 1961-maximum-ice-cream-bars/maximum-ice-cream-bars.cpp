class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int maxIceCreamBars = 0;

        for (int i = 0; i < costs.size(); i++) {
            if (costs[i] <= coins) {
                maxIceCreamBars++;
                coins -= costs[i];
            } else {
                break;
            }
        }

        return maxIceCreamBars;
    }
};