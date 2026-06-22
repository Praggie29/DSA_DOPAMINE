class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set <string> st;
        st.insert ( "0,0");
        int a = 0 , b = 0;
        for ( char ch : path ) {
            if ( ch == 'N' ) {
                b += 1;
                string s = to_string(a) + ',' + to_string(b);
                if ( st.find(s) != st.end()) {
                    return true;
                }
                else {
                    st.insert ( s );
                }
            }
                if ( ch == 'S' ) {
                    b -= 1;
                string s = to_string(a) + ',' + to_string(b);
                if ( st.find(s) != st.end()) {
                    return true;
                }
                else {
                    st.insert ( s );
                }
            }
            if ( ch == 'E' ) {
                a += 1;
                string s = to_string(a) + ',' + to_string(b);
                if ( st.find(s) != st.end()) {
                    return true;
                }
                else {
                    st.insert ( s );
                }
            }
            if ( ch == 'W' ) {
                a-=1;
                string s = to_string(a) + ',' + to_string(b);
                if ( st.find(s) != st.end()) {
                    return true;
                }
                else {
                    st.insert ( s );
                }
            }
        }
        return false;
    }
};