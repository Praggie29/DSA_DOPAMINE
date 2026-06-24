class Solution {
public:
    int minOperations(int k) {
        if ( k == 1 ) return 0;
        int mini = INT_MAX;
        for ( int i = 0 ; i < k ; i ++ ) {
            int b = i + 1;
           int a = ( k + b - 1 ) / b - 1 ;
           mini = min ( mini , a + i );
        }
        return mini;
    }
};