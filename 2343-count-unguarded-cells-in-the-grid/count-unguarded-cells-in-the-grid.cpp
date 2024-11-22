class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 2; 
        }
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 1;
        }
        int delr[] = {-1, 1, 0, 0};
        int delc[] = {0, 0, -1, 1};

        for (int i = 0; i < guards.size(); i++) {
            int r = guards[i][0], c = guards[i][1];
            for (int k = 0; k < 4; k++) { 
                int nr = r, nc = c;
                while (true) {
                    nr += delr[k];
                    nc += delc[k];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        break;
                    if (grid[nr][nc] == 1 || grid[nr][nc] == 2) 
                        break;
                    if (grid[nr][nc] == 0) 
                        grid[nr][nc] = 3;
                }
            }
        }
        int unguardedCount = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0)
                    ++unguardedCount;
            }
        }

        return unguardedCount;
    }
};
