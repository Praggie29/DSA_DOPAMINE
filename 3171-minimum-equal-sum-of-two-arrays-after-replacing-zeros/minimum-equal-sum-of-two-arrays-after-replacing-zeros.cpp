class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cntZero1 = 0 , cntZero2 = 0;
        long long sum1 = 0 , sum2 = 0;
        for ( int i = 0 ; i < nums1.size() ; i ++ ) {
            sum1 += nums1[i];
            if ( nums1[i] == 0 ) cntZero1++;
            
        }
        for ( int i = 0 ; i < nums2.size() ; i ++ ) {
            sum2 += nums2[i];
            if ( nums2[i] == 0 ) cntZero2++;
        }
        long long total1 = sum1 + cntZero1;
        long long total2 = sum2 + cntZero2;
        if ( total1 < total2 && cntZero1 == 0 ) return -1;
        if ( total2 < total1 && cntZero2 == 0 ) return -1;
        return max ( total1 , total2 );
    }
};