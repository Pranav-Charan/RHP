#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int dp[3][3];

    // Copy first column
    for (int i = 0; i < 3; i++)
        dp[i][0] = a[i][0];

    // Fill DP table column-wise
    for (int j = 1; j < 3; j++) {
        for (int i = 0; i < 3; i++) {

            int up = (i > 0) ? dp[i - 1][j - 1] : 0;
            int left = dp[i][j - 1];
            int down = (i < 2) ? dp[i + 1][j - 1] : 0;

            dp[i][j] = a[i][j] + max(left, max(up, down));
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans = max(ans, dp[i][2]);

    cout << "Maximum Value = " << ans;

    return 0;
}