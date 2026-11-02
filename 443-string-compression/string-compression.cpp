class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n <= 1) return n;
        
        int i = 0, j = 0;
        int inPlace = 0;
        char ch = chars[0];
        
        while (j < n) {
            if (chars[j] == ch) {
                j++;
            } else {
                int dis = j - i;
                chars[inPlace++] = ch;
                if (dis > 1) {
                    string countStr = to_string(dis);
                    for (char c : countStr) {
                        chars[inPlace++] = c;
                    }
                }
                
                ch = chars[j];
                i = j;
                j++;
            }
        }
        int dis = j - i;
        chars[inPlace++] = ch;
        if (dis > 1) {
            string countStr = to_string(dis);
            for (char c : countStr) {
                chars[inPlace++] = c;
            }
        }
        
        return inPlace;
    }
};