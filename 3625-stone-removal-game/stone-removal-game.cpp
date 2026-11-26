class Solution {
public:
    bool canAliceWin(int n) {
        int removeCount = 10;
        bool aliceTurn = true;

        while (n >= removeCount) {
            n -= removeCount;
            removeCount--;
            aliceTurn = !aliceTurn;
        }
        return !aliceTurn;
    }
};