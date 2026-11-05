class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int>lhp(n,0);
        int pref = 0 , suf = 1;
        while ( suf < n ) {
            if ( s[pref] == s[suf] ) {
                lhp[suf] = pref + 1;
                suf++;
                pref++;
            }
            else {
                if (pref != 0) {
                   pref = lhp[pref - 1];
                } else {
                   lhp[suf] = 0;
                   suf++;
                }
            }
        }
        return s.substr(0, lhp[n - 1]);
    }
};