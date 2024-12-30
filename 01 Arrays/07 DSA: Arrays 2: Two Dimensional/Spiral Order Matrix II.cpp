// https://www.scaler.com/academy/mentee-dashboard/class/236116/assignment/problems/63?navref=cl_tt_lst_sl

// Problem Description

// Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order and return the generated square matrix.



// Problem Constraints

// 1 <= A <= 1000



// Input Format

// First and only argument is integer A


// Output Format

// Return a 2-D matrix which consists of the elements added in spiral order.



// Example Input

// Input 1:

// 1
// Input 2:

// 2
// Input 3:

// 5


// Example Output

// Output 1:

// [ [1] ]
// Output 2:

// [ [1, 2], 
//   [4, 3] ]
// Output 3:

// [ [1,   2,  3,  4, 5], 
//   [16, 17, 18, 19, 6], 
//   [15, 24, 25, 20, 7], 
//   [14, 23, 22, 21, 8], 
//   [13, 12, 11, 10, 9] ]


// Example Explanation

// Explanation 1:

// Only 1 is to be arranged.
// Explanation 2:

// 1 --> 2
//       |
//       |
// 4<--- 3
// Explanation 3:


vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > ans(A, vector<int>(A));
    int i=0, j=0, As=1, N=A;

    while(N>1){
        for(int k=1; k<N; k++){
            ans[i][j]=As++;
            j++;
        }
        for(int k=1; k<N; k++){
            ans[i][j]=As++;
            i++;
        }
        for(int k=1; k<N; k++){
            ans[i][j]=As++;
            j--;
        }
        for(int k=1; k<N; k++){
            ans[i][j]=As++;
            i--;
        }
        N=N-2;
        i++;
        j++;
    }
    if (N==1) ans[i][j]=As++;
    return ans;
}

