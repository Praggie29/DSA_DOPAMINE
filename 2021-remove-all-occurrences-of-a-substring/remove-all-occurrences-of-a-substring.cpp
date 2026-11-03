class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        int i = 0 , j = 0 ;
        while ( j + m <= s.size() ) {
            string subStr = s.substr(j,m);
            if ( subStr == part ) {
                s.erase(j,m);
                j = 0;
                i = 0;
            }
            else {
               j++;
               i++;
            }
        }
        return s;
    }
};