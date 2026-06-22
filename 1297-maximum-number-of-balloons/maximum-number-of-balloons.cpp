class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector <int> freq ( 5 , 0 );
        for ( int i = 0 ; i < text.size() ; i ++ ) {
            if ( text[i] == 'b' ) freq[0]++;
            else if ( text[i] == 'a' ) freq[1]++;
            else if ( text[i] == 'l' ) freq[2]++;
            else if ( text[i] == 'o' ) freq[3]++;
            else if ( text[i] == 'n' ) freq[4]++;
        }
        int mini = INT_MAX;
        for ( int i = 0 ; i < 5 ; i ++ ) {
            if ( i == 2 || i == 3 ) {
                mini = min ( mini , freq[i] / 2 );
            }
            else {
                mini = min ( mini , freq[i] );
            }
        }
        return mini;
    }
};