// https://www.scaler.com/academy/mentee-dashboard/class/236124/homework/problems/4364?navref=cl_tt_lst_nm

// Problem Description

// Given an integer, A. Find and Return first positive A integers in ascending order containing only digits 1, 2, and 3.


// NOTE: All the A integers will fit in 32-bit integers.




// Problem Constraints

// 1 <= A <= 29500



// Input Format

// The only argument given is integer A.



// Output Format

// Return an integer array denoting the first positive A integers in ascending order containing only digits 1, 2 and 3.



// Example Input

// Input 1:

//  A = 3
// Input 2:

//  A = 7


// Example Output

// Output 1:

//  [1, 2, 3]
// Output 2:

//  [1, 2, 3, 11, 12, 13, 21]


// Example Explanation

// Explanation 1:

//  Output denotes the first 3 integers that contains only digits 1, 2 and 3.
// Explanation 2:

//  Output denotes the first 7 integers that contains only digits 1, 2 and 3.

vector<int> Solution::solve(int A) {
    queue<int> q;
    vector<int> ans;

    for (int i=1; i<=3; i++)
        q.push(i);
    
    for (int i=0; i<A; i++){
        int front=q.front();
        q.pop();
        ans.push_back(front);

        for (int i=1; i<=3; i++)
            q.push(front*10+i);
    }

    return ans;
    
}
