#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int diff[4][2] = {
        {0, -1}, {0, 1},
        {-1, 0}, {1, 0}
    };

    int dfs(vector<vector<int>>& matrix,
            vector<vector<int>>& dp,
            int row, int col) {

        if (dp[row][col] != 0)
            return dp[row][col];

        int R = matrix.size();
        int C = matrix[0].size();

        int maxLen = 1;

        for (int i = 0; i < 4; i++) {
            int nr = row + diff[i][0];
            int nc = col + diff[i][1];

            if (nr >= 0 && nr < R &&
                nc >= 0 && nc < C &&
                matrix[nr][nc] > matrix[row][col]) {

                maxLen = max(maxLen,
                             1 + dfs(matrix, dp, nr, nc));
            }
        }

        return dp[row][col] = maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();

        vector<vector<int>> dp(R, vector<int>(C, 0));

        int ans = 0;

        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                ans = max(ans, dfs(matrix, dp, row, col));
            }
        }

        return ans;
    }
};

int main() {
    int R, C;
    cout << "Enter rows and columns: ";
    cin >> R >> C;

    vector<vector<int>> matrix(R, vector<int>(C));

    cout << "Enter matrix:\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    cout << "Longest Increasing Path = "
         << obj.longestIncreasingPath(matrix) << endl;

    return 0;
}