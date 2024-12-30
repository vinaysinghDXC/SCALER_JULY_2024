// https://www.scaler.com/academy/mentee-dashboard/class/297861/homework/problems/1140?navref=cl_tt_nv

// Problem Description

// You are given an array A of N integers and three integers B, C, and D.

// You have to find the maximum value of A[i]*B + A[j]*C + A[k]*D, where 1 <= i <= j <= k <= N.



// Problem Constraints

// 1 <= N <= 105

// -10000 <= A[i], B, C, D <= 10000



// Input Format

// First argument is an array A
// Second argument is an integer B
// Third argument is an integer C
// Fourth argument is an integer D



// Output Format

// Return an Integer S, i.e maximum value of (A[i] * B + A[j] * C + A[k] * D), where 1 <= i <= j <= k <= N.



// Example Input

// Input 1:

//  A = [1, 5, -3, 4, -2]
//  B = 2
//  C = 1
//  D = -1
// Input 2:

//  A = [3, 2, 1]
//  B = 1
//  C = -10
//  D = 3


// Example Output

// Output 1:

//  18
// Output 2:

//  -4


// Example Explanation

// Explanation 1:

//  If you choose i = 2, j = 2, and k = 3 then we will get
//  A[2]*B + A[2]*C + A[3]*D = 5*2 + 5*1 + (-3)*(-1) = 10 + 5 + 3 = 18
// Explanation 2:

//  If you choose i = 1, j = 3, and k = 3 then we will get
//  A[1]*B + A[3]*C + A[3]*D = (3*1) + (-10*1) + (3*1) = 3 - 10 + 3 = -4
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void findmax(vector<int> &A, int fac, vector<int> &maxarr, int idx, int &curridx){
    if (idx==A.size()) return;

    if (idx > 0 && maxarr[idx] + (A[idx] * fac) >= maxarr[idx - 1]) {
        curridx = idx;
    }

    maxarr[idx]=max(maxarr[idx-1], maxarr[idx]+(A[idx]*fac));

    findmax(A, fac, maxarr, idx+1, curridx);
}

int solve(vector<int> &A, int B, int C, int D) {
    vector<int> maxarr(A.size(), 0);
    int idx=0;
    int curridx=0;

    maxarr[0]=maxarr[0]+A[0]*B;
    findmax(A, B, maxarr, 1, curridx);

    maxarr[0]=maxarr[0]+A[0]*C;
    findmax(A, C, maxarr, 1, curridx);

    maxarr[0]=maxarr[0]+A[0]*D;
    findmax(A, D, maxarr, 1, curridx);

    return maxarr[curridx];
}
