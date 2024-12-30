// https://www.scaler.com/academy/mentee-dashboard/class/297913/homework/problems/125143?navref=cl_tt_nv

// Problem Description

// Given an MxN matrix where each element can either be 0 or 1. We need to find the length of shortest path between a given source cell to a destination cell.

// A cell with value 0 denotes that it's a hurdle. The path can only be created out of the cells with values 1.
// If NO path exists then print -1.

// The matrix A is given as input of size M x N.
// The coordinates of Source cell are given by B, C.
// The coordinates of Destination cell are given by D, E.



// Problem Constraints

// 1 <= N , M <= 8
// 0 <= A[i][j] <= 1
// 0 <= B, C < N
// 0 <= D, E < M
// A[B][C] == A[D][E] == 1


// Input Format

// First Argument is a 2-D Integer Array denotes the matrix A, of size MxN.
// Second Argument is an Integer B, denoting the Source Row Index
// Third Argument is an Integer C, denoting the Source Column Index
// Fourth Argument is an Integer D, denoting the Destination Row Index
// Fifth Argument is an Integer E, denoting the Destination Column Index


// Output Format

// Output a single integer denoting the length of the minimum distance from Source to destination


// Example Input

// Input 1 :
// A = [[1, 1, 0, 0],
//      [0, 1, 1, 0],
//      [0, 0, 1, 1],
//      [0, 0, 0, 1]]
// B = 0, C = 0
// D = 3, E = 3
// Input 2 :
// A = [[1, 1, 1],
//      [1, 0, 1],
//      [1, 1, 1]]
// B = 0, C = 0
// D = 0, E = 2
// Input 3 :
// A = [[1, 0, 1],
//      [1, 0, 1],
//      [1, 0, 1]]
// B = 0, C = 0
// D = 0, E = 2



// Example Output

// Output 1 :
// 6
// Output 2 :
// 2
// Output 3 :
// -1


// Example Explanation

// For Input 1 :
// The shortest path is (0,0) -> (0,1) -> (1,1) -> (1,2) -> (2,2) -> (2,3) -> (3,3)
// For Input 2 :
// The shortest path is (0,0) -> (0,1) -> (0,2) 
// For Input 3 :
// No path exists so we return -1

void pathfinder(int &ans, vector<vector<int> > &A, int sr, int sc, int dr, int dc, vector<vector<int> > &visited, int currentlen){
    if (sr<0 || sc<0 || sr>=A.size() || sc>=A[0].size() || A[sr][sc]==0 || visited[sr][sc]==1){
        return;
    }

    if (sr==dr && sc==dc){
        ans=min(ans, currentlen);
        return;
    }

    visited[sr][sc]=1;

    pathfinder(ans, A, sr-1, sc, dr, dc, visited, currentlen+1);

    pathfinder(ans, A, sr, sc-1, dr, dc, visited, currentlen+1);

    pathfinder(ans, A, sr+1, sc, dr, dc, visited, currentlen+1);

    pathfinder(ans, A, sr, sc+1, dr, dc, visited, currentlen+1);

    visited[sr][sc]=0;


}

int Solution::FindShortestPath(vector<vector<int> > &A, int B, int C, int D, int E) {
    int ans = INT_MAX;
    vector<vector<int> > visited(A.size(), vector<int>(A[0].size(), 0));
    pathfinder(ans, A, B, C, D, E, visited, 0);
    return (ans == INT_MAX) ? -1 : ans;
}
