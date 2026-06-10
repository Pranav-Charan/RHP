#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1}
    };

    void dfs(vector<vector<char>>& grid, int r, int c) {
        int R = grid.size();
        int C = grid[0].size();

        grid[r][c] = '0';

        for (auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < R &&
                nc >= 0 && nc < C &&
                grid[nr][nc] == '1') {
                dfs(grid, nr, nc);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        int islands = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {

                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};

int main() {
    int R, C;

    cout << "Enter rows and columns: ";
    cin >> R >> C;

    vector<vector<char>> grid(R, vector<char>(C));

    cout << "Enter grid (0 and 1):\n";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << "Number of Islands = "
         << obj.numIslands(grid) << endl;

    return 0;
}