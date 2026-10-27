class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int prefProd = 1;
        for ( int i = 0 ; i < nums.size() ; i ++ ) {
            if ( prefProd == 0 ) prefProd = 1;
            prefProd *= nums[i];
            maxProd = max ( maxProd , prefProd );
           
        }
        int sufProd = 1;
        for ( int i = nums.size() - 1 ; i >= 0 ; i -- ) {
            if ( sufProd == 0 ) sufProd = 1;
            sufProd *= nums[i];
            maxProd = max ( maxProd , sufProd );
            
        }
        return maxProd;
    }
};