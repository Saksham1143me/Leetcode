class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // If immediate move to (1, 1) is impossible
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        // Min-Heap for BFS (time, row, col)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}}); // Start at (0, 0) with time 0

        // Minimum time to reach each cell
        vector<vector<int>> time(m, vector<int>(n, INT_MAX));
        time[0][0] = 0;

        // Directions for 4-way movement
        int delr[] = {-1, 1, 0, 0};
        int delc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [currTime, cell] = pq.top();
            pq.pop();

            int row = cell.first, col = cell.second;

            // If reached the destination
            if (row == m - 1 && col == n - 1) {
                return currTime;
            }

            // Skip processing if a faster route to this cell was already found
            if (currTime > time[row][col]) {
                continue;
            }

            // Explore all 4 neighbors
            for (int k = 0; k < 4; k++) {
                int nr = row + delr[k];
                int nc = col + delc[k];

                // Check bounds
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    // Calculate the earliest valid time to visit the neighbor
                    int waitTime = (grid[nr][nc] > currTime + 1) ? grid[nr][nc] - (currTime + 1) : 0;
                    if (waitTime % 2 == 1) waitTime++; // Adjust for even/odd parity
                    int newTime = currTime + 1 + waitTime;

                    if (newTime < time[nr][nc]) {
                        time[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};
