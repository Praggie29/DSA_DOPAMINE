class Solution {
public:
    int addDigits(int num) {
        int temp = num;
        while ( temp > 9 ) {
           int sum = 0;
           int temp1 = temp;
           while ( temp1 ) {
             int rem = temp1 % 10;
             sum += rem;
             temp1 /= 10;
           }
           temp = sum;
        }
        return temp;
    }
};