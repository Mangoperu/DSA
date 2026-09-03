class Solution {
public:
    string frequencySort(string s) {
        // Size 256 covers all standard ASCII characters (uppercase, lowercase, numbers, symbols)
        vector<pair<int, char>> v(256);
        
        // Initialize the vector so each pair knows its corresponding character
        for(int i = 0; i < 256; i++){
            v[i].second = i;
        }
        
        // Count frequencies using the character's ASCII value directly as the index
        for(char c : s){
            v[c].first++;
        }
        
        // Sort in descending order using a custom lambda function
        sort(v.begin(), v.end(), [](pair<int, char>& a, pair<int, char>& b) {
            return a.first > b.first; 
        });
        
        string ans;
        // Build the result string
        for(int i = 0; i < 256; i++){
            if (v[i].first == 0) break; // Stop early once we hit characters with 0 frequency
            
            // C++ string::append is faster than a nested loop calling push_back
            ans.append(v[i].first, v[i].second);
        }
        
        return ans;
    }
};