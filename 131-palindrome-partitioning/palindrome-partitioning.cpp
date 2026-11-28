class Solution {
public:
    bool isPalindrome ( string &s , int start , int end ) {
        while ( start < end ) {
            if ( s[start] != s[end] ) return false;
            start++;
            end--;
        }
        return true;
    }
    void f ( int idx , string &s , vector<string>&store , vector<vector<string>>&ans ) {
        if ( idx == s.size() ) {
            ans.push_back(store);
            return;
        }
        for ( int i = idx ; i < s.size() ; i ++ ) {
            if ( isPalindrome ( s , idx , i )) {
                store.push_back(s.substr(idx , i - idx + 1 ));
                f ( i + 1 , s , store , ans );
                store.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>store;
        f ( 0 , s , store , ans );
        return ans;
    }
};