//
// Created by SAYON DEEP on 23-11-2022.
//
/*
    Time Complexity: O(N*M)
    Space Complexity: O(N*M),

    Where N is the height of the sewage system and M is the width.
*/

#include<queue>

// Function to check if the current point has an opening upwards.
int connectUp(int x, int y, vector<vector<int>> &grid) {
    return (grid[x][y] == 1 || grid[x][y] == 2 || grid[x][y] == 4 || grid[x][y] == 7);
}

// Function to check if the current point has an opening downwards.
int connectDown(int x, int y, vector<vector<int>> &grid) {
    return (grid[x][y] == 1 || grid[x][y] == 2 || grid[x][y] == 5 || grid[x][y] == 6);
}

// Function to check if the current point has an opening to its left.
int connectLeft(int x, int y, vector<vector<int>> &grid) {
    return (grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 6 || grid[x][y] == 7);
}

// Function to check if the current point has an opening to its right.
int connectRight(int x, int y, vector<vector<int>> &grid) {
    return (grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 4 || grid[x][y] == 5);
}

// Function to check if the current point is a valid point or not.
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int undergroundExplorer(vector<vector<int>> &grid, int n, int m, int x, int y, int l) {

    // 2-D array to store the visited points.
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // Queue to store the points of BFS.
    queue<vector<int>> q;

    // Variable to store the answer.
    int ans = 0;

    if (grid[x][y]) {
        q.push({x, y, l});

        // Mark the current point as visited.
        vis[x][y] = 1;
    }

    while (!q.empty()) {

        // Temporary vector to store the current position and remaining distance.
        vector<int> curr = q.front();
        q.pop();

        // Increment the answer.
        ans++;

        // If distance is still remaining.
        if (curr[2] > 1) {

            // Check if (curr[0]-1,curr[1]) is a valid point and if it connects with (curr[0],curr[1]) and it should not be visited.
            if (isValid(curr[0] - 1, curr[1], n, m) && connectUp(curr[0], curr[1], grid) && connectDown(curr[0] - 1, curr[1], grid) && 0 == vis[curr[0] - 1][curr[1]]) {
                q.push({curr[0] - 1, curr[1], curr[2] - 1});
                vis[curr[0] - 1][curr[1]] = 1;
            }

            // Check if (curr[0]+1,curr[1]) is a valid point and if it connects with (curr[0],curr[1]) and it should not be visited.
            if (isValid(curr[0] + 1, curr[1], n, m) && connectDown(curr[0], curr[1], grid) && connectUp(curr[0] + 1, curr[1], grid) && 0 == vis[curr[0] + 1][curr[1]]) {
                q.push({curr[0] + 1, curr[1], curr[2] - 1});
                vis[curr[0] + 1][curr[1]] = 1;
            }

            // Check if (curr[0],curr[1]+1) is a valid point and if it connects with (curr[0],curr[1]) and it should not be visited.
            if (isValid(curr[0], curr[1] + 1, n, m) && connectLeft(curr[0], curr[1] + 1, grid) && connectRight(curr[0], curr[1], grid) && 0 == vis[curr[0]][curr[1] + 1]) {
                q.push({curr[0], curr[1] + 1, curr[2] - 1});
                vis[curr[0]][curr[1] + 1] = 1;
            }

            // Check if (curr[0],curr[1]-1) is a valid point and if it connects with (curr[0],curr[1]) and it should not be visited.
            if (isValid(curr[0], curr[1] - 1, n, m) && connectLeft(curr[0], curr[1], grid) && connectRight(curr[0], curr[1] - 1, grid) && 0 == vis[curr[0]][curr[1] - 1]) {
                q.push({curr[0], curr[1] - 1, curr[2] - 1});
                vis[curr[0]][curr[1] - 1] = 1;
            }

        }

    }

    // Return the answer.
    return ans;
}
