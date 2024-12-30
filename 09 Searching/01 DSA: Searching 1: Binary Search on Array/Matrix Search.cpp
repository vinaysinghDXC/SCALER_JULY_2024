// https://www.scaler.com/academy/mentee-dashboard/class/236074/homework/problems/196?navref=cl_tt_lst_nm

// Problem Description

// Given a matrix of integers A of size N x M and an integer B. Write an efficient algorithm that searches for integer B in matrix A.

// This matrix A has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than or equal to the last integer of the previous row.
// Return 1 if B is present in A, else return 0.

// NOTE: Rows are numbered from top to bottom, and columns are from left to right.



// Problem Constraints

// 1 <= N, M <= 1000
// 1 <= A[i][j], B <= 106



// Input Format

// The first argument given is the integer matrix A.
// The second argument given is the integer B.



// Output Format

// Return 1 if B is present in A else, return 0.



// Example Input

// Input 1:

// A = [ 
//       [1,   3,  5,  7]
//       [10, 11, 16, 20]
//       [23, 30, 34, 50]  
//     ]
// B = 3
// Input 2:

// A = [   
//       [5, 17, 100, 111]
//       [119, 120, 127, 131]    
//     ]
// B = 3


// Example Output

// Output 1:

// 1
// Output 2:

// 0


// Example Explanation

// Explanation 1:

//  3 is present in the matrix at A[0][1] position so return 1.
// Explanation 2:

//  3 is not present in the matrix so return 0.

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int N = A.size(); 
    int M = A[0].size();
    
    int l = 0;
    int r = N * M - 1;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        int row = mid / M;
        int col = mid % M;
        
        int midElement = A[row][col];
        
        if (midElement == B) {
            return 1;  
        } else if (midElement < B) {
            l = mid + 1;  
        } else {
            r = mid - 1; 
        }
    }
    
    return 0;
}
