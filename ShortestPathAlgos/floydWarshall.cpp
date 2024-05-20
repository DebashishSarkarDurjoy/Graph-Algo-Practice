#include <iostream>
#include <vector>

#define inf 10000

using namespace std;
    

void floydWarshall(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();

    for (int N = 0; N < row; N++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ( grid[i][j] > grid[i][N] + grid[N][j] ) {
                    grid[i][j] = grid[i][N] + grid[N][j];
                }
            }
        }
    }

    for (auto row: grid) {
        for (auto col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

int main(void) {
    vector<vector<int>> grid = {
        {0, inf, -2, inf},
        {4, 0, 3, inf},
        {inf, inf, 0, 2},
        {inf, -1, inf, 0}
    };

    floydWarshall(grid);

    return 0;
}