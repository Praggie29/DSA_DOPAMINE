class Solution {
public:
    int numberOfSteps(int num) {
        int temp = num;
        int numOfSteps = 0;
        while ( temp ) {
           if ( temp % 2 == 0 ) {
              temp = temp / 2;
              numOfSteps++;
           }
           else {
             temp = temp - 1;
             numOfSteps++;
           }
        }
        return numOfSteps;
    }
};