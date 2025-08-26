#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<string> grid;

// Function to check if expanding to size k is valid
bool isValid(int r, int c, int k) {
    char ch = grid[r][c];
    int startRow = r - k, endRow = r + k;
    int startCol = c - k, endCol = c + k;

    if (startRow < 0 || endRow >= n || startCol < 0 || endCol >= m) return false;

    for (int i = startRow; i <= endRow; i++) {
        if (grid[i][startCol] != ch || grid[i][endCol] != ch) return false;
    }
    for (int j = startCol; j <= endCol; j++) {
        if (grid[startRow][j] != ch || grid[endRow][j] != ch) return false;
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> m >> q;
        grid.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        
        cout << n << " " << m << " " << q << endl;
        
        while (q--) {
            int r, c;
            cin >> r >> c;
            
            int maxSize = 1;
            while (isValid(r, c, maxSize)) {
                maxSize++;
            }
            
            cout << (2 * (maxSize - 1) + 1) << endl;
        }
    }

    return 0;
}
