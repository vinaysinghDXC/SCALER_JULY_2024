// // https://www.scaler.com/academy/mentee-dashboard/class/297909/homework/problems/208?navref=cl_tt_lst_sl

// // Problem Description

// // Given a 2-D board A of size N x M containing 'X' and 'O', capture all regions surrounded by 'X'.

// // A region is captured by flipping all 'O's into 'X's in that surrounded region.



// // Problem Constraints

// // 1 <= N, M <= 1000



// // Input Format

// // First and only argument is a N x M character matrix A.



// // Output Format

// // Return nothing. Make changes to the the input only as matrix is passed by reference.



// // Example Input

// // Input 1:

// //  A = [ 
// //        [X, X, X, X],
// //        [X, O, O, X],
// //        [X, X, O, X],
// //        [X, O, X, X] 
// //      ]
// // Input 2:

// //  A = [
// //        [X, O, O],
// //        [X, O, X],
// //        [O, O, O]
// //      ]


// // Example Output

// // Output 1:

// //  After running your function, the board should be:
// //  A = [
// //        [X, X, X, X],
// //        [X, X, X, X],
// //        [X, X, X, X],
// //        [X, O, X, X]
// //      ]
// // Output 2:

// //  After running your function, the board should be:
// //  A = [
// //        [X, O, O],
// //        [X, O, X],
// //        [O, O, O]
// //      ]


// // Example Explanation

// // Explanation 1:

// //  O in (4,2) is not surrounded by X from below.
// // Explanation 2:

// //  No O's are surrounded.


// https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/

#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

void capture(vector<vector<char> > &A, int i, int j, int N, int M){
    if (i<0 || i>=N || j<0 || j>=M || A[i][j]!='O') return;

    A[i][j] = '+';

    capture(A, i+1, j, N, M);
    capture(A, i-1, j, N, M);
    capture(A, i, j+1, N, M);
    capture(A, i, j-1, N, M);
}

void solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rows = A.size();
    int cols = A[0].size();

    for (int i = 0; i<rows; i++){   
        if (A[i][0] == 'O') capture(A, i, 0, rows, cols);
        if (A[i][cols-1] == 'O') capture(A, i, cols-1, rows, cols);
    }
    for (int i = 0; i<cols; i++){
        if (A[0][i] == 'O') capture(A, 0, i, rows, cols);
        if (A[rows-1][i] == 'O') capture(A, rows-1, i, rows, cols);
    }

    for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            if (A[i][j]== 'O') A[i][j] = 'X';
            else if (A[i][j] == '+') A[i][j] = 'O';
        }
    }
}
