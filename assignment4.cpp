
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;
const int INF = 1e18;

class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n) {
        int i = row, j = col;

        // Upper diagonal
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--; j--;
        }

        // Left row
        j = col;
        i = row;
        while (j >= 0) {
            if (board[i][j] == 'Q') return false;
            j--;
        }

        // Lower diagonal
        i = row, j = col;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i++; j--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(i, col, board, n)) {
                board[i][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};

void solve() {
    Solution s;
    int n;
    cin >> n;
    vector<vector<string>> results = s.solveNQueens(n);

    cout << "Total solutions: " << results.size() << "\n\n";

    int cnt = 1;
    for (auto &board : results) {
        cout << "Solution #" << cnt++ << ":\n";
        for (auto &row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }
}

signed main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
