//
// Created by SAYON DEEP on 23-11-2022.
//
/*
    Time Complexity: O( N * M * ( 2 ^ G ) )
    Space Complexity: O( N * M * ( 2 ^ G ) )

    where N denotes the number of rows and columns, and G denotes the number of houses containing gold
*/

int goForGold(int n, int m, vector<vector<int>> arr, int x, int y) {

    // Map to store the houses containing gold
    map < vector < int > , int > mp;

    // Variable to number the houses containing gold
    int num = 0;

    // Traverse the city to find houses containing gold
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                mp[{i, j}] = num++;
            }
        }
    }

    // Variable to set the maximum value of bit-mask
    int target = pow(2, num);

    // Bit-mask, where mask[i][j][k] represents minimum steps to reach (i,j)
    // when we have already covered the gold-houses corresponding to the set bits in binary representation of 'k'
    int mask[n][m][target];

    // Initialize minimum steps to -1, to mark a position as unvisited
    memset(mask, -1, sizeof(mask));

    // Variable to keep the track of steps in bfs
    int steps = 0;

    // Array to simulate the moves
    vector < vector < int >> moves = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

    // BFS queue
    queue < vector < int >> q;

    // Variable to store the calculated-mask
    int ctr = 0;

    // Check if the starting position contains gold or not
    if (arr[0][0] == 1) {

        // Store the gold-house number in 'ctr'
        ctr += mp[{0, 0}];

        // Convert 'ctr' into 2^ctr to create a mask
        ctr = pow(2, ctr);
    }

    // Push the starting position after masking it
    q.push({0, 0, ctr});

    // Mark the starting position as visited, to avoid revisiting it
    mask[0][0][ctr] = 0;

    // BFS algorithm
    while (!q.empty()) {

        int sz = q.size();

        while (sz--) {

            int i = q.front()[0];

            int j = q.front()[1];

            int k = q.front()[2];

            q.pop();

            // If we have reached (X,Y) and collected all the gold.
            // Note that 'k' storing the bitmask will be (11....111) in binary representation
            if (i == x && y == j && k == target - 1) {
                return steps;
            }

            // Move to the the next adjacent house
            for (auto u: moves) {

                // 'i + u[0]' & 'j + u[1]' stores the new x-coordinate & y-coordinate
                int newX = i + u[0], newY = j + u[1];

                // Check that you stay within the city bounds and don't move to a house containing guards
                if (newX < n && newX >= 0 && newY < m && newY >= 0 && arr[newX][newY] != 2) {

                    // If the new position is a gold-house
                    if (arr[newX][newY] == 1) {

                        // Store the gold-house number in 'ctr'
                        ctr = mp[{newX, newY}];

                        // Check if the ctr'th bit of the current mask is OFF
                        if (!(k & (1 << ctr))) {

                            // Convert 'ctr' into 2^ctr to create a mask
                            ctr = k + pow(2, ctr);

                            // Check if the new mask is already visited
                            if (mask[newX][newY][ctr] != -1) {
                                continue;
                            }

                            // Push the new masked position into bfs-queue
                            q.push({newX, newY, ctr});

                            // Marked the new masked position as visited
                            mask[newX][newY][ctr] = 1;
                        }

                            // Incase the ctr'th bit of the current mask is ON (already visited this gold house previously)
                        else {

                            // In the previous visit to this house, we might have visited less gold-houses, check that
                            // Incase no extra gold houses were visited then mask[newX][newY][k] would be != -1 (ie: visited)
                            if (mask[newX][newY][k] != -1) {
                                continue;
                            }

                            // Incase extra gold-houses were found after last visit, then the mask 'k' would be different now
                            // Push the new masked position into bfs-queue
                            q.push({newX, newY, k});

                            // Marked the new masked position as visited
                            mask[newX][newY][k] = 1;
                        }
                    }

                        // If the new position is not a gold-house
                    else {

                        // Check if the masked position is already visited or not
                        if (mask[newX][newY][k] != -1) {
                            continue;
                        }

                        // Incase extra gold-houses were found after last visit, then the mask 'k' would be different now
                        // Push the new masked position into bfs-queue
                        q.push({newX, newY, k});

                        // Marked the new masked position as visited
                        mask[newX][newY][k] = 1;
                    }
                }
            }
        }

        // Inrement the value of 'steps'
        steps++;
    }

    // Unable to reach the final position after collecting all the gold
    return -1;

}