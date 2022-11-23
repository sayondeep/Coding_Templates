//
// Created by SAYON DEEP on 23-11-2022.
//
/*
    Time Complexity  : O((N*M)^2)
    Space Complexity : O(1)

    Where 'N' and 'M' are the number of rows and the columns int the BOMB_GRID
*/

vector<vector<int>> getSafeState(vector<vector<int>> &bombGrid, int n, int m)
{
    // Do while safe state is not achieved.
    while (true)
    {
        vector<vector<int>> blast;

        // Iterate through every cell
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If current cell is '0', continue with next cell
                if (bombGrid[i][j] == 0)
                {
                    continue;
                }

                int verticalUp = i, verticalDown = i, horizontalLeft = j, horizontalRight = j;

                // Checking cells with equal value in vertical up direction
                while (verticalUp >= 0 && verticalUp > i - 3 &&
                       bombGrid[verticalUp][j] == bombGrid[i][j])
                {
                    verticalUp--;
                }

                // Checking cells with equal values in vertical down direction
                while (verticalDown < n && verticalDown < i + 3 &&
                       bombGrid[verticalDown][j] == bombGrid[i][j])
                {
                    verticalDown++;
                }

                // Checking cells with equal values in horijontal left  direction
                while (horizontalLeft >= 0 && horizontalLeft > j - 3 &&
                       bombGrid[i][horizontalLeft] == bombGrid[i][j])
                {
                    horizontalLeft--;
                }

                // Checking cells with equal values in horizontal right direction
                while (horizontalRight < m && horizontalRight < j + 3 &&
                       bombGrid[i][horizontalRight] == bombGrid[i][j])
                {
                    horizontalRight++;
                }

                // If '3' or more adjacnet bomb have same power
                if (verticalDown - verticalUp > 3 ||
                    horizontalRight - horizontalLeft > 3)
                {
                    blast.push_back({i, j});
                }
            }
        }

        // If grid is safe
        if (blast.size() == 0)
        {
            break;
        }

        for (int i = 0; i < blast.size(); i++)
        {
            bombGrid[blast[i][0]][blast[i][1]] = 0;
        }

        // Shifting bombs
        for (int j = 0; j < m; j++)
        {
            int t = n - 1;

            for (int i = n - 1; i >= 0; i--)
            {
                if (bombGrid[i][j] != 0)
                {
                    swap(bombGrid[t][j], bombGrid[i][j]);
                    t--;
                }
            }
        }
    }

    return bombGrid;
}