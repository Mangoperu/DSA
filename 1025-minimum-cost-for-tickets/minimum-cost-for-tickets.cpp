class Solution {
public:
    int rec(vector<int>& d , vector<int>& c ,int a,int b , vector<int>&v){
        
        if(b >= d.size()){
            return 0;
        }
        if(a>=d[b]){
          return rec(d , c , a , b+1,v);
        }
        if(v[a]!= -1){
            return v[a];
        }
        int one = c[0]+rec(d , c , d[b] , b+1,v );
        int seven = c[1] + rec(d , c, d[b]+6 , b+1,v);
        int thity = c[2] + rec( d , c ,d[b] + 29 , b+1,v);
        v[a] = min(min(one  , seven) , thity);
        return v[a];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> v(400 , -1);
        return rec( days , costs , 0 , 0 , v);

    }
};