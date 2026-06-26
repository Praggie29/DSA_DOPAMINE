class Solution {
public:
    bool canConstruct(string s, int k) {
        if ( s.size() == k ) return true;
        if ( s.size () < k ) return false;
        unordered_map <char ,int> mpp;
        for ( char ch : s ) {
            mpp[ch]++;
        }
        int cnt = 0;
        for ( auto &it : mpp ) {
            if ( it.second % 2 != 0 ) cnt++;
        }
        return cnt <= k ;
    }
};