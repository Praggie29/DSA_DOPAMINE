class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if ( n > m ) return false;
        unordered_map < char , int > mpp;
        for ( char i : s1 ) mpp[i]++;
        int i = 0 , j = 0;
        while ( j + n <= m ) {
            string subStr = s2.substr ( j , n );
            unordered_map < char , int > checkMap;
            for ( char ch : subStr ) checkMap[ch]++;
            if ( mpp == checkMap ) return true;
            j++;
        }
        return false;
    }
};