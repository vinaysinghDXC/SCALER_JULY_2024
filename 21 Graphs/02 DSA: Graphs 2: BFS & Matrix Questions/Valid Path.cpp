// Problem Description

// There is a rectangle with left bottom as (0, 0) and right up as (x, y).

// There are N circles such that their centers are inside the rectangle.

// Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

// Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.



// Problem Constraints

// 0 <= x , y, R <= 100

// 1 <= N <= 1000

// Center of each circle would lie within the grid



// Input Format

// 1st argument given is an Integer x , denoted by A in input.

// 2nd argument given is an Integer y, denoted by B in input.

// 3rd argument given is an Integer N, number of circles, denoted by C in input.

// 4th argument given is an Integer R, radius of each circle, denoted by D in input.

// 5th argument given is an Array A of size N, denoted by E in input, where A[i] = x cordinate of ith circle

// 6th argument given is an Array B of size N, denoted by F in input, where B[i] = y cordinate of ith circle



// Output Format

// Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).



// Example Input

// Input 1:

//  x = 2
//  y = 3
//  N = 1
//  R = 1
//  A = [2]
//  B = [3]
// Input 2:

//  x = 3
//  y = 3
//  N = 1
//  R = 1
//  A = [0]
//  B = [3]


// Example Output

// Output 1:

//  NO
// Output 2:

//  YES


// Example Explanation

// Explanation 1:

//  There is NO valid path in this case
// Explanation 2:

//  There is many valid paths in this case.
//  One of the path is (0, 0) -> (1, 0) -> (2, 0) -> (3, 0) -> (3, 1) -> (3, 2) -> (3, 3).

//  https://www.scaler.com/academy/mentee-dashboard/class/297909/homework/problems/418?navref=cl_tt_lst_sl


#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<int> dx = {-1, 1, 0, 0, 1, 1, -1, -1};
    vector<int> dy = {0, 0, -1, 1, 1, -1, 1, -1};

    vector<vector<int>> visited(A + 1, vector<int>(B + 1, 0));

    for (int i = 0; i < C; i++) {
        int cx = E[i], cy = F[i];
        for (int x = 0; x <= A; x++) {
            for (int y = 0; y <= B; y++) {
                if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= D * D) {
                    visited[x][y] = 1;
                }
            }
        }
    }

    if (visited[0][0] == 1 || visited[A][B] == 1) {
        return "NO";
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 2;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        if (x == A && y == B) {
            return "YES";
        }

        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i], newY = y + dy[i];

            if (newX >= 0 && newX <= A && newY >= 0 && newY <= B && visited[newX][newY] == 0) {
                q.push({newX, newY});
                visited[newX][newY] = 2;
            }
        }
    }

    return "NO";
}
