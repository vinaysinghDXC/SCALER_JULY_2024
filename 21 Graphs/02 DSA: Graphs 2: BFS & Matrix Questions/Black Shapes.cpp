// https://www.scaler.com/academy/mentee-dashboard/class/297909/homework/problems/291/?navref=cl_pb_nv_tb

// Problem Description

// Given character matrix A of dimensions N×M consisting of O's and X's, where O = white, X = black.








// Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)





// Problem Constraints

// 1 <= N, M <= 1000








// A[i][j] = 'X' or 'O'





// Input Format

// The First and only argument is character matrix A.



// Output Format

// Return a single integer denoting number of black shapes.



// Example Input

// Input 1:

//  A = [ [X, X, X], [X, X, X], [X, X, X] ]
// Input 2:

//  A = [ [X, O], [O, X] ]


// Example Output

// Output 1:

//  1
// Output 2:

//  2


// Example Explanation

// Explanation 1:

//  All X's belong to single shapes
// Explanation 2:

//  Both X's belong to different shapes
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int black(vector<string> &A) {
    int rows = A.size();
    int cols = A[0].size();

    queue<pair<int, int> > q;
    vector<vector<bool> > visited(rows, vector<bool>(cols, false));

    int blackshapes = 0;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == 'X' && !visited[i][j]) {

                blackshapes++;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    int x = curr.first;
                    int y = curr.second;

                    for (int k = 0; k < 4; k++) {
                        int movex = x + dx[k];
                        int movey = y + dy[k];

                        if (movex >= 0 && movex < rows && movey >= 0 && movey < cols &&
                            A[movex][movey] == 'X' && !visited[movex][movey]) {
                            visited[movex][movey] = true;
                            q.push({movex, movey});
                        }
                    }
                }
            }
        }
    }

    return blackshapes;
}
