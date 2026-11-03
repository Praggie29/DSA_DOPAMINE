class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;
        while ( i < n ) {
            if ( s[i] == ' ' ) {
                i++;
                continue;
            }
                string word = "";
                while ( i < n && s[i] != ' ' ) {
                    word += s[i];
                    i++;
                }
                if (ans.empty()) {
                ans = word;
                } 
                else {
                ans = word + " " + ans;
                }
        }
        return ans;
    }
};