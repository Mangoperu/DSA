class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int rightNeeded = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If we need an odd number of ')', we have a single stranded ')'.
                // We must insert a missing ')' to complete the previous pair.
                if (rightNeeded % 2 != 0) {
                    insertions++;
                    rightNeeded--; // We provided the missing ')', so we need one less
                }
                // A new '(' always demands two matching ')'
                rightNeeded += 2;
            } else { 
                // c == ')'
                rightNeeded--;
                
                // If rightNeeded drops below 0, we have a ')' with no matching '('
                if (rightNeeded < 0) {
                    insertions++;    // Insert a missing '(' before this ')'
                    rightNeeded = 1; // The new '(' needs two ')'. We just used one, so 1 remains.
                }
            }
        }
        
        // Add any remaining right parentheses we still need at the end of the string
        return insertions + rightNeeded;
    }
};