class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<int> c;
        int n = s.length();
        int dig = 0;
        for(int i = 0 ; i<n ; i++ ){
            if(s[i] == '('){
                c.push(dig);
            }
            else{
                if(s[i] == ')'){
                    reverse(ans.begin() + c.top(), ans.begin() + dig);
                    c.pop();
                }
                else{
                ans.push_back(s[i]);
                dig++;

            }}
        }
        return ans;
    }
};