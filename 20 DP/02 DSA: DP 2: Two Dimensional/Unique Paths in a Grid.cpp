// https://www.scaler.com/academy/mentee-dashboard/class/297877/assignment/problems/8?navref=cl_tt_lst_nm

// Problem Description

// Given a grid of size n * m, lets assume you are starting at (1,1) and your goal is to reach (n, m). 
// At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).

// Now consider if some obstacles are added to the grids. 
// Return the total number unique paths from (1, 1) to (n, m).

// Note: 
// 1. An obstacle is marked as 1 and empty space is marked 0 respectively in the grid.
// 2. Given Source Point and Destination points are 1-based index.



// Problem Constraints

// 1 <= n, m <= 100
// A[i][j] = 0 or 1


// Input Format

// Firts and only argument A is a 2D array of size n * m.


// Output Format

// Return an integer denoting the number of unique paths from (1, 1) to (n, m).


// Example Input

// Input 1:

//  A = [
//         [0, 0, 0]
//         [0, 1, 0]
//         [0, 0, 0]
//      ]
// Input 2:

//  A = [
//         [0, 0, 0]
//         [1, 1, 1]
//         [0, 0, 0]
//      ]


// Example Output

// Output 1:

//  2
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  Possible paths to reach (n, m): {(1, 1), (1, 2), (1, 3), (2, 3), (3, 3)} and {(1 ,1), (2, 1), (3, 1), (3, 2), (3, 3)}  
//  So, the total number of unique paths is 2. 
// Explanation 2:

//  It is not possible to reach (n, m) from (1, 1). So, ans is 0.
#include <iostream>
#include <vector>

using namespace std;

int ways(vector<vector<int> > &A, int i, int j,vector<vector<int> >&dp){
    if (i < 0 || j < 0 || A[i][j] == 1) return 0;
    if (i == 0 && j == 0) return 1;// reached 0,0
    if (dp[i][j]!=-1) return dp[i][j];
    if (A[i][j]!=1) dp[i][j]=ways(A, i-1, j, dp)+ways(A,i, j-1, dp);
    return dp[i][j];
}


int uniquePathsWithObstacles(vector<vector<int> > &A) {
    int i = A.size()-1;
    int j = A[0].size()-1;
    if (A[0][0] == 1 || A[i][j] == 1) return 0;
    vector<vector<int> >dp(A.size(), vector<int>(A[0].size(), -1));
    int ans=ways(A, i, j, dp);
    return ans;
}


int finduniqueways(vector<vector<int> > &A, vector<vector<int> > &dpuniqueways, int sx, int sy){
    if (sx>=A.size() || sy>=A[0].size() || A[sx][sy]==1) return 0;
    
    if (sx==A.size()-1 && sy==A[0].size()-1) return 1;

    if (dpuniqueways[sx][sy]!=-1) return dpuniqueways[sx][sy];

    if (A[sx][sy]!=1) dpuniqueways[sx][sy] = finduniqueways(A, dpuniqueways, sx+1, sy) + finduniqueways(A, dpuniqueways, sx, sy+1);

    return dpuniqueways[sx][sy];
}

int uniquePathsWithObstacles(vector<vector<int> > &A) {
    vector<vector<int> > dpuniqueways(A.size(), vector<int> (A[0].size(), -1));
    return finduniqueways(A, dpuniqueways, 0, 0);
}
