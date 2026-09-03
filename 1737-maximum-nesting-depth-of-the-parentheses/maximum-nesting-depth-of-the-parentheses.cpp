class Solution {
public:
    int maxDepth(string s) {
        int a = 0;
       // int count  = 0 ;
        int  n = s.length();
        int ans = 0;
        for(int i = 0 ; i< n ;i++){
            if(s[i] == '('){
                a++;
               // count++;
            }
            else if(s[i] == ')'){
                a--;
                //count++;
            }
            
           //if(a == 0){
                ans = max(ans , a);
                //count = 0;
           // }

        }
        return ans;
    }
};