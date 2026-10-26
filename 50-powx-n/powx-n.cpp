class Solution {
public:
    double power ( double x , long long n) {
     if ( n == 0 ) return 1;
     if ( n % 2 == 0 ) return power ( x * x , n / 2 );
     return x * power ( x * x , ( n - 1 ) / 2 );
   }
    double myPow(double x, int n) {
        long long pow = abs((long long)n);
        double ans = power ( x , pow );
        if ( n < 0 ) return 1 / ans;
        return ans;
    }
};