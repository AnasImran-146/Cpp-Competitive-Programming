#include <iostream>
using namespace std;

int main() {
    const int n = 5;  // 5x5 board

    // Step 1: Initialize the given board
    char board[n][n] = {
        {'X', 'O', 'O', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'X', 'X'},
        {'O', 'O', 'X', 'O', 'O'}
    };

    int maxLen = 0; // to store the longest sequence length

    // Step 2: Go through each cell one by one
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // Only check directions if this cell is 'X'
            if (board[i][j] == 'X') {

                // Direction 1: Horizontal (→)
                int count = 0;
                for (int k = j; k < n && board[i][k] == 'X'; k++)
                    count++;
                if (count > maxLen) maxLen = count;

                // Direction 2: Vertical (↓)
                count = 0;
                for (int k = i; k < n && board[k][j] == 'X'; k++)
                    count++;
                if (count > maxLen) maxLen = count;

                // Direction 3: Diagonal (↘)
                count = 0;
                for (int k = 0; i + k < n && j + k < n && board[i + k][j + k] == 'X'; k++)
                    count++;
                if (count > maxLen) maxLen = count;

                // Direction 4: Anti-Diagonal (↙)
                count = 0;
                for (int k = 0; i + k < n && j - k >= 0 && board[i + k][j - k] == 'X'; k++)
                    count++;
                if (count > maxLen) maxLen = count;
            }
        }
    }

    cout << "Longest sequence of Xs: " << maxLen << endl;

    return 0;
}
