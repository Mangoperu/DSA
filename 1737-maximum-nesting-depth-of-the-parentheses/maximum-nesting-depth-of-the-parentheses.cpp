class Solution {
public:
    int maxDepth(string s) {
        int a = 0;
        int  n = s.length();
        int ans = 0;
       stack<char> c;
       for(int i = 0 ; i<n ; i++){
        if(s[i] == '('){
            c.push(s[i]);
        }
        else if(s[i] == ')'){
            c.pop();
        }
        ans = max(ans , (int)c.size());
       }
        return ans;
    }
};