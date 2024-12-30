// https://www.scaler.com/academy/mentee-dashboard/class/297881/assignment/problems/68?navref=cl_tt_lst_nm

// Problem Description

// Write a program to print the pascal triangle up to A rows.









// Problem Constraints

// 1 <= A <= 25











// Input Format

// The first argument is an integer A.









// Output Format


// Return a 2D array consisting of A rows whose each row contains A integers.








// Example Input

// Input 1:








// A = 3
// Input 2:


// A = 5








// Example Output

// Output 1:








// 1 0 0 
// 1 1 0 
// 1 2 1 
// Output 2:

// 1 0 0 0 0
// 1 1 0 0 0
// 1 2 1 0 0
// 1 3 3 1 0
// 1 4 6 4 1 









// Example Explanation

// Explanation 1:








// Row 1 = 1 0 0 
// Row 2 = 1C0 1C1 0 = 1 1 0
// Row 3 = 2C0 2C1 2C2 = 1 2 1

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > ans(A, vector<int>(A, 0));
    for (int i =0; i<A; i++){
        for (int j=0; j<=i; j++){
            if (j==0 || j==i) ans [i][j]=1;
            else ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans;
}