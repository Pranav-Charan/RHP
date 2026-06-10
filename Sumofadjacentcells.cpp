#include <bits/stdc++.h>
using namespace std;

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

    int row, col;
    cout << "Enter row and column: ";
    cin >> row >> col;

    int diff[8][2] = {
        {-1,-1}, {-1,0}, {-1,1},
        { 0,-1},         { 0,1},
        { 1,-1}, { 1,0}, { 1,1}
    };

    long long sum = 0;

    for (int i = 0; i < 8; i++) {
        int nr = row + diff[i][0];
        int nc = col + diff[i][1];

        if (nr >= 0 && nr < R &&
            nc >= 0 && nc < C) {
            sum += matrix[nr][nc];
        }
    }

    cout << "Adjacent Sum = " << sum << endl;

    return 0;
}