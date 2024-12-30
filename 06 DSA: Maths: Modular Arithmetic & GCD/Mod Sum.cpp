// Problem Description

// Given an array of integers A, calculate the sum of A [ i ] % A [ j ] for all possible i, j pairs. Return sum % (109 + 7) as an output.



// Problem Constraints

// 1 <= length of the array A <= 105

// 1 <= A[i] <= 103



// Input Format

// The only argument given is the integer array A.



// Output Format

// Return a single integer denoting sum % (109 + 7).



// Example Input

// Input 1:

//  A = [1, 2, 3]
// Input 2:

//  A = [17, 100, 11]


// Example Output

// Output 1:

//  5
// Output 2:

//  61


// Example Explanation

// Explanation 1:

//  (1 % 1) + (1 % 2) + (1 % 3) + (2 % 1) + (2 % 2) + (2 % 3) + (3 % 1) + (3 % 2) + (3 % 3) = 5

//  https://www.scaler.com/academy/mentee-dashboard/class/236090/assignment/problems/4745?navref=cl_tt_nv

int Solution::solve(vector<int> &A) {
    vector<int> freq(1001);
    for(int i=0; i<A.size(); i++){
        freq[A[i]]++;
    }
    int mod=1e9+7;
    int ans=0;

    for(int i=1; i<freq.size(); i++){
        for(int j=1; j<freq.size(); j++){
            int val=i%j;
            int c1=freq[i];
            int c2=freq[j];
            int temp=val*c1*c2;
            ans=((ans%mod)+(temp%mod))%mod;
        }
    }
    return ans;
}
