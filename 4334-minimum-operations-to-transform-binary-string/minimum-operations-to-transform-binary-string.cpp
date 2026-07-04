class Solution {
public:
    const int INF = 1e9;

    string a, b;
    int len;
    vector<vector<int>> memo;

    int solve(int pos, int flipNext) {
        if (pos == len) return 0;

        if (memo[pos][flipNext] != -1)
            return memo[pos][flipNext];

        char ch = a[pos];
        if (flipNext)
            ch = (ch == '0' ? '1' : '0');

        int ans = INF;

        if (ch == b[pos]) {
            ans = min(ans, solve(pos + 1, 0));
        }

        if (ch == '0') {
            if (b[pos] == '1') {
                ans = min(ans, 1 + solve(pos + 1, 0));
            }

            if (pos + 1 < len && a[pos + 1] == '1') {
                int cost = (ch == b[pos]) ? 2 : 3;
                ans = min(ans, cost + solve(pos + 1, 1));
            }
        } else {
            if (b[pos] == '0') {
                if (pos + 1 < len) {
                    if (a[pos + 1] == '1') {
                        ans = min(ans, 1 + solve(pos + 1, 1));
                    } else {
                        ans = min(ans, 2 + solve(pos + 1, 0));
                    }
                } else {
                    return memo[pos][flipNext] = INF;
                }
            } else {
                if (pos + 1 < len && a[pos + 1] == '1') {
                    ans = min(ans, 2 + solve(pos + 1, 1));
                }
            }
        }

        return memo[pos][flipNext] = ans;
    }

    int minOperations(string s1, string s2) {
        a = s1;
        b = s2;
        len = a.size();

        memo.assign(len, vector<int>(2, -1));

        int res = solve(0, 0);
        return (res >= INF ? -1 : res);
    }
};