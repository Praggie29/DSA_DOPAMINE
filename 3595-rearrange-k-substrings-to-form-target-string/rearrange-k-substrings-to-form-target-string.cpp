class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.length();
        int size = n / k;
        unordered_map <string , int> mpp;
        for ( int i = 0 ; i < n ; i += size ) {
            string subString = t.substr(i,size);
            mpp[subString]++;
        } 
        for ( int i = 0 ; i < n ; i += size ) {
            string subString = s.substr(i,size);
            if ( mpp[subString] == 0) return false;
            mpp[subString]--;
        }
        return true;
    }
};