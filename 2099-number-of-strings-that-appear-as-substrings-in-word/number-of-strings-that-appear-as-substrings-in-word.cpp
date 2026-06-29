class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int total = 0;
        for ( string &st : patterns ) {
            if ( word.find(st) != string::npos) total++;
        }
        return total;
    }
};