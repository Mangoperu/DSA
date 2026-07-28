class Solution {
public:
    string smallestPalindrome(string s) 
    {
        string g(s.length() , '/');
        int n = s.length();
        if(n%2!=0){
            g[(n/2)] = s[(n/2)];
        }
        map <char , int> m;
        for(int  i  = 0 ; i<n ; i++){
            if(g[i] == '/'){
            m[s[i]]++;}
        }
        int strt = 0;
        vector<pair<char , int>> v;
        for(auto i:m){
            v.push_back(make_pair(i.first , i.second));
        }
        for(int i = 0 ; i<v.size() ; i++){
            g[strt] = v[i].first;
            g[n-strt - 1] = v[i].first;
            v[i].second -= 2;
            if(v[i].second>0){
                i--;
            }
            strt++;
        }
        return g;
    }
};