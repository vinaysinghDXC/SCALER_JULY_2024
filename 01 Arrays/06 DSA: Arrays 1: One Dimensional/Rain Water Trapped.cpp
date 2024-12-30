// https://www.scaler.com/academy/mentee-dashboard/class/236078/assignment/problems/47?navref=cl_tt_nv

// Problem Description

// Imagine a histogram where the bars' heights are given by the array A. Each bar is of uniform width, which is 1 unit. When it rains, water will accumulate in the valleys between the bars.

// Your task is to calculate the total amount of water that can be trapped in these valleys.

// Example:

// The Array A = [5, 4, 1, 4, 3, 2, 7] is visualized as below. The total amount of rain water trapped in A is 11.


// Rain Water Trapped




// Problem Constraints

// 1 <= |A| <= 105
// 0 <= A[i] <= 105



// Input Format

// First and only argument is the Integer Array, A.



// Output Format

// Return an Integer, denoting the total amount of water that can be trapped in these valleys



// Example Input

// Input 1:

//  A = [0, 1, 0, 2]
// Input 2:

// A = [1, 2]

int Solution::trap(const vector<int> &A) {
    if (A.size()==2) return 0;

    vector<int> lrange(A.size(), 0);
    lrange[0]=A[0];
    for (int i=1; i<A.size(); i++){
        lrange[i]=max(A[i], lrange[i-1]);
    }

    vector<int> Rrange(A.size(), 0);
    Rrange[A.size()-1]=A[A.size()-1];
    for (int i=A.size()-2; i>=0; i--){
        Rrange[i]=max(A[i], Rrange[i+1]);   
    }

    int ans=0;
    for (int i=0; i<A.size(); i++){
        ans+=min(lrange[i], Rrange[i])-A[i];
    }
    return ans;
}
