// https://www.scaler.com/academy/mentee-dashboard/class/297877/assignment/problems/22/?navref=cl_pb_nv_tb

// Problem Description

// Given an integer A, how many structurally unique BST's (binary search trees) exist that can store values 1...A?



// Problem Constraints

// 1 <= A <=18



// Input Format

// First and only argument is the integer A



// Output Format

// Return a single integer, the answer to the problem



// Example Input

// Input 1:

//  1
// Input 2:

//  2


// Example Output

// Output 1:

//  1
// Output 2:

//  2


// Example Explanation

// Explanation 1:

//  Only single node tree is possible.
// Explanation 2:

//  2 trees are possible, one rooted at 1 and other rooted at 2.



int Solution::numTrees(int A) {
    vector<int> cdp(A+1, 0);
    if (A<=1) return 1;
    cdp[0]=1;
    cdp[1]=1;

    for (int i = 2; i<=A; i++){
        int l = 0, r = i-1;
        while(r>=0){
            cdp[i]+=cdp[l]*cdp[r];
            l++;
            r--;
        }
    }

    return cdp[A];
}
