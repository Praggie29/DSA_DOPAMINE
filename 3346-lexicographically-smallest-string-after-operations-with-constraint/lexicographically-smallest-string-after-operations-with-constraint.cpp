class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = "";
        for ( int i = 0 ; i < s.size() ; i ++ ) {
            int left = s[i] - 'a';
            int right = ( 'z' - s[i] ) + 1;
            int mini = min ( left , right );
            if ( k >= mini ) {
                k -= mini;
                ans += 'a';
            }
            else {
                char ch = s[i] - k;
                ans += ch;
                k = 0;
            }
        }
        return ans;
    }
};