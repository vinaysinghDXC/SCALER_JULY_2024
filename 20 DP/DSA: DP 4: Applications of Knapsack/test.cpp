#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Cell {
    int x, y, dist;
};

bool isValid(int x, int y, int A, int B) {
    return x >= 1 && x <= A && y >= 1 && y <= B;
}

int knightMinSteps(int A, int B, int C, int D, int E, int F) {
    // All possible moves for a knight
    vector<pair<int, int> > moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    // If source and destination are the same
    if (C == E && D == F) return 0;

    // Visited matrix to keep track of visited cells
    vector<vector<bool> > visited(A + 1, vector<bool>(B + 1, false));

    // Queue for BFS
    queue<Cell> q;
    q.push({C, D, 0});
    visited[C][D] = true;

    // BFS Loop
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        // Explore all possible knight moves
        for (auto move : moves) {
            int newX = current.x + move.first;
            int newY = current.y + move.second;

            if (isValid(newX, newY, A, B) && !visited[newX][newY]) {
                // If the destination is reached
                if (newX == E && newY == F) return current.dist + 1;

                // Mark as visited and push to queue
                visited[newX][newY] = true;
                q.push({newX, newY, current.dist + 1});
            }
        }
    }

    // If destination is not reachable
    return -1;
}

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    cout << knightMinSteps(A, B, C, D, E, F) << endl;
    return 0;
}
