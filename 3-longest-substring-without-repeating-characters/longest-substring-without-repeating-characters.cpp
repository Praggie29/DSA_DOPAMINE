class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0 , j = 0;
        unordered_map < char , int > mpp;
        int longestSubString = INT_MIN;
        while ( j < n ) {
           if ( mpp.find(s[j]) == mpp.end() ) {
                mpp[s[j]]++;
                j++;
           }
           else {
              longestSubString = max ( longestSubString , j - i );
              while ( mpp.find(s[j]) != mpp.end()) {
                    mpp[s[i]]--;
                    if ( mpp[s[i]] == 0 ) {
                        mpp.erase(s[i]);
                    }
                    i++;
              }
           }
        }
        longestSubString = max ( longestSubString , j - i );
        return longestSubString;
    }
};