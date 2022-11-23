//
// Created by SAYON DEEP on 23-11-2022.
//
#include <vector>
#define INF 1000000000
int getmin(int vertexNumber, vector<bool> &visited, vector<int> &time)
{
    int minval = INF;
    int minidx = INF;

    for (int i = 0; i < vertexNumber; i++)
    {
        if (!visited[i] && minval > time[i])
        {
            minval = time[i];
            minidx = i;
        }
    }

    return minidx;
}

int minTimeInWormholeNetwork(int n, int sx, int sy, int dx, int dy, Wormhole* wormhole)
{
    int vertexNumber, wormholeNumber;
    int totalVertex = 2 * n + 2;
    vector<int> vertexX(totalVertex);
    vector<int> vertexY(totalVertex);
    vector<int> wormholeTime(totalVertex);
    vector<vector<int>> adjacencyMatrix(totalVertex, vector<int>(totalVertex));
    vector<int> time(totalVertex);
    vector<bool> visited(totalVertex);

    vertexNumber = 0;
    wormholeNumber = 0;

    vertexX[vertexNumber] = sx;
    vertexY[vertexNumber] = sy;
    vertexNumber++;
    vertexX[vertexNumber] = dx;
    vertexY[vertexNumber] = dy;
    vertexNumber++;

    for (int i = 0; i < n; i++)
    {

        vertexX[vertexNumber] = wormhole[i].startX;
        vertexY[vertexNumber] = wormhole[i].startY;
        vertexNumber++;

        vertexX[vertexNumber] = wormhole[i].endX;
        vertexY[vertexNumber] = wormhole[i].endY;
        vertexNumber++;

        wormholeTime[wormholeNumber] = wormhole[i].cost;
        wormholeNumber++;
    }

    for (int i = 0; i < vertexNumber; i++) // Creating complete graph using all the vertex
    {
        for (int j = i + 1; j < vertexNumber; j++)
        {
            adjacencyMatrix[i][j] = abs(vertexX[i] - vertexX[j]) + abs(vertexY[i] - vertexY[j]);
            adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
        }
    }

    for (int i = 2, j = 0; i < vertexNumber && j < wormholeNumber; i += 2, j++)
    {
        adjacencyMatrix[i][i + 1] = wormholeTime[j];
        adjacencyMatrix[i + 1][i] = wormholeTime[j];
    }

    // Dijkstra from the source vertex 0
    for (int i = 0; i < vertexNumber; i++)
    {
        time[i] = INF;
        visited[i] = 0;
    }

    time[0] = 0; // Initialize the time of source as 0

    for (int i = 0; i < vertexNumber - 1; i++)
    {
        int x = getmin(vertexNumber, visited, time);
        visited[x] = 1;

        for (int k = 0; k < vertexNumber; k++)
        {
            if (!visited[k] && time[k] > time[x] + adjacencyMatrix[x][k])
            {
                time[k] = time[x] + adjacencyMatrix[x][k];
            }
        }
    }

    return time[1]; // As 1 is the destination vertex
}