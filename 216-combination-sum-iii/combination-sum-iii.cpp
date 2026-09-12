class Solution {
public:
    void rec(int i , int k , int n , vector<vector<int>>&v  , vector<int>&x){
            if(n == 0){
                if(x.size() == k){
                    v.push_back(x);
                }
                return;
            }
            if(i == 10 || n<0){
                return;           
                 }
    

            x.push_back(i);
            rec(i+1 , k , n-i , v , x);
            x.pop_back();
            rec(i+1 , k , n , v , x);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int>x;
        rec(1 ,k , n,v , x);
        return v;
    }
};